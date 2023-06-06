#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{
    bool flag = false;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
          if (arr[j] > arr[j + 1]) {
          
            swap(arr[j], arr[j + 1]);
            flag = true;
          }

        }
        if(flag == false){
        break;
    }
    }


    // Write your code here.
}
