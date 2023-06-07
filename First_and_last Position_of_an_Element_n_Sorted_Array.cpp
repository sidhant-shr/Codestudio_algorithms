// using binary search

//First and Last Position of an Element In Sorted Array

#include <bits/stdc++.h> 

    int firstOccurence(vector<int>& arr,int size,int key){
    int s = 0;
    int e = size-1;
    int mid = s + (e-s)/2;
    int ans = - 1;



while(s<=e){
    if(arr[mid]==key){
        ans = mid;
        e = mid-1;
    }

    if(key>arr[mid]){
        s = mid+1;
        
    }

    else (key<arr[mid]){      // key in left part so key<arr[i]
        e=mid-1;
    }
     mid = s + (e-s)/2;

}
return ans;
}

int lastOccurence(vector<int>& arr,int size,int key){
    int s = 0;
    int e = size-1;
    int mid = s + (e-s)/2;
    int answer = - 1;



while(s<=e){
    if(arr[mid]==key){
        answer = mid;
        s = mid + 1;
    }


    if(key>arr[mid]){
        s = mid+1;
        
    }

    else  (key<arr[mid]){       
        e=mid-1;
    }
    mid = s + (e-s)/2;



}
return answer;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int>p;
    p.first = firstOccurence(arr,n,k);
    p.second= lastOccurence(arr,n,k);
    return p;
    // Write your code here
}
