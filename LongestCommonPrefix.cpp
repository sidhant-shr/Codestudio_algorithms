# using Iterative Approach

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Approach Using Normal Iterative Approach
    string ans;
    for(int i = 0; i < arr[0].length(); i++){
        char curr = arr[0][i];
        bool match = true;
        for(int j = 1; j < n; j++){
            if(!(arr[j].length() > i && arr[j][i] == curr)){
                match = false;
                break;
            }
        }
        if(match){
            ans.push_back(curr);
        }
        else{
            break;
        }
    }

    return ans;
}

# Using Tries

#include <bits/stdc++.h>

class Node{
    public:
        char data;
        Node* children[26];
        bool isTerminal;
    public:
        Node(){
            data = '#';
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        } 
        Node(char val){
            data = val;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie: public Node {
    public: 
        Node* root;
    public:
        Trie(){
            root = NULL;
        }
        Trie(Node* node){
            root = node;
        }
        void insert(string val){
            if(root == NULL){
                root = new Node();
            }
            Node* curr = root;
            int n = val.size();
            for(int i = 0; i < n; i++){
                if(curr->children[val[i] - 'a'] == NULL){
                    curr->children[val[i] - 'a'] = new Node(val[i]);
                }
                curr = curr->children[val[i] - 'a'];
            }
            curr->isTerminal = true;
        }
        string lcp(int refMinSize){
            // Normal Logic: Util Diverge 
            Node* curr = root;
            string ans;
            for(int i = 0; i <= refMinSize; i++){
                if(i != 0)
                    ans.push_back(curr->data);
                int count = 0;
                Node* next = NULL;
                for(int j = 0; j < 26; j++){
                    if(curr->children[j] != NULL){
                        count++;
                        next = curr->children[j];
                    }
                }
                if(count != 1) return ans;
                
                curr = next;
            }
            return ans;

        }
};


string longestCommonPrefix(vector<string> &arr, int n)
{
    // Approach Using Trie Data Structure
    // Using a refference string
    Trie ds;
    int refMinSize = INT_MAX;
    for(string i : arr){
        ds.insert(i);
        int m = i.size();
        refMinSize = min(refMinSize, m);
    }

    return ds.lcp(refMinSize);
}
