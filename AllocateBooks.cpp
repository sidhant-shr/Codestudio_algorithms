#include <bits/stdc++.h>

bool isPossible(vector<int> &arr, int n, int m, long long mid)
{
	long long studentCount = 1;
	long long pageSum = 0;
	
	for(int i=0; i<n; i++)
	{
		if(pageSum + arr[i] <= mid) pageSum += arr[i];
		else
		{
			studentCount++;
			if(studentCount > m || arr[i] > mid) return false;
			pageSum = arr[i];
		}
	}
	
	return true;
} 

long long ayushGivesNinjatest(int m, int n, vector<int> time) 
{	
	if(n < m) return -1;
	
	long long sum = 0;	
	for(int i=0; i<n; i++) sum += time[i];

	long long s = 0;
	long long e = sum;
	
	long long ans = -1;
	
	while(s <= e)
	{
		long long mid = s + (e-s) / 2;
		
		if(isPossible(time, n, m, mid))
		{
			ans = mid;
			e = mid - 1;
		}
		
		else s = mid + 1;
	}
	
	return ans;
}
