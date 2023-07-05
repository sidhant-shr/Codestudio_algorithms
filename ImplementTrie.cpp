class Node{
    public:
        char data;
        // each for an alphabet
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
    private: 
        Node* root;

    public:
        Trie(){
            root = NULL;
        }
        Trie(Node* node){
            root = node;
        }

    // Insertion
    void insert(string word) {
        if(root == NULL){
            root = new Node();
        }
        Node* curr = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(curr->children[word[i] - 'a'] == NULL){
                curr->children[word[i] - 'a'] = new Node(word[i]);
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->isTerminal = true;
    }

    // Traversal

    bool search(string word) {
        Node* curr = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(curr->children[word[i] - 'a'] == NULL) return false;
            curr = curr->children[word[i] - 'a'];
        }
        return curr->isTerminal;
    }
    // starts with prefix

    bool startsWith(string prefix) {
        Node* curr = root;
        int n = prefix.size();
        for(int i = 0; i < n; i++){
            if(curr->children[prefix[i] - 'a'] == NULL) return false;
            curr = curr->children[prefix[i] - 'a'];
        }
        return true;
    }
};
