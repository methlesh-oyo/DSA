#include <bits/stdc++.h>
#define vi vector<int> 
using namespace std;

const int inf=1e9;

vi FindMaxCrossingSubarray(vi A, int low, int mid, int high){
	int left_sum = -inf;
	int sum = 0;
	int max_left=low, max_right=high;
	for(int i=mid; i>=low; i--){
		sum += A[i];
		if(sum>left_sum){
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = -inf;
	sum=0;
	for(int i=mid+1; i<=high; i++){
		sum += A[i];
		if(sum>right_sum){
			right_sum = sum;
			max_right = i;
		}
	}
	return {max_left, max_right, left_sum+right_sum};
}

vi FindMaximumSubarray(vi A, int low, int high){
	if(high==low)
		return {low, high, A[low]};
	int mid = (low+high)/2;

	// left_low, low_high, left_sum
	vi lll = FindMaximumSubarray(A, low, mid);

	// right_low, right_high, right_sum
	vi rrr = FindMaximumSubarray(A, mid+1, high);

	// cross_low, cross_high, cross_sum
	vi ccc = FindMaxCrossingSubarray(A, low, mid, high);

	if(lll[2]>=rrr[2] and lll[2]>=ccc[2])
		return lll;
	if(rrr[2]>=lll[2] and rrr[2]>=ccc[2])
		return rrr;
	return ccc;
}
int main(){

	vi A = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

	int low = 0, high = A.size()-1;

	A = FindMaximumSubarray(A, low, high);

    // Output 1-indexed
	cout<<"Left Index: "<<A[0]+1<<"\n";
	cout<<"Right Index: "<<A[1]+1<<"\n";
	cout<<"Sum: "<<A[2]<<"\n";

	return 0;
}
