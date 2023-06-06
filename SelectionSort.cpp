#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i<n-1; i++){
        int intMin = i ;

        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[intMin]){
                intMin = j;
            }      
            }
            swap(arr[intMin], arr[i]);
    }
    // Write your code here.
}
