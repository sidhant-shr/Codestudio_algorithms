bool isPossible(vector<int>boards,int k,int mid){
    int painter = 1;
    int n = boards.size();
    int boardsPainted = 0;

    for(int i =0;i<n;i++){
        if(boardsPainted + boards[i] <= mid){
            boardsPainted += boards[i];
        }
        else{
            painter++;

            if(painter>k || boards[i]>mid){
                return false;
            }

            boardsPainted = boards[i];
        }

    }
    return true;
    
}




int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;

    int boardSum = 0;
    int n = boards.size();

    for(int i = 0;i<n;i++){
        boardSum+=boards[i];
    }

    int e = boardSum;

    int mid = s + (e-s)/2 ;
    int ans = -1;

    while(s<=e){
        if(isPossible(boards,k,mid)){
            ans = mid;

            e =mid - 1;

            
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2 ;

    }
    //    Write your code here.
}
