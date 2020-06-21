#include <bits/stdc++.h>
using namespace std;

const int max_size=1000001;

int n, arr[max_size];

void merge_sort(int l, int r, int arr[]){
	int mid=(l+r)/2;
	if(l<r){
		merge_sort(l, mid, arr);
		merge_sort(mid+1, r, arr);

		int i=l, j=mid+1, k=0, b[r-l+1];
		while(i<=mid && j<=r){
			if(arr[i]<arr[j]){
				b[k]=arr[i];
				i++;
				k++;
			}
			else{
				b[k]=arr[j];
				j++;
				k++;
			}
		}
		while(i<=mid){
			b[k]=arr[i];
			i++;
			k++;
		}
		while(j<=r){
			b[k]=arr[j];
			j++;
			k++;
		}
		k=0;
		for(int i=l; i<=r; i++){
			arr[i]=b[k++];
		}
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Array before sorting:\n";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	merge_sort(0, n-1, arr);
	cout<<"Array after sorting:\n";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
