#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    int j=0;
    for(int i = 1 ; i<n; i++){

        int temp = arr[i];

        for(j = i-1; j>=0;j--){
            if(temp<arr[j]){

                arr[j+1]= arr[j];
                
            }

            else{
                break;
            }



        }
         arr[j+1]=temp;
    }
    // Write your code here.
}
