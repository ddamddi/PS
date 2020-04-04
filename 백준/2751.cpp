#include <iostream>
using namespace std;

int arr[1000000], ans[1000000];

void merge(int arr[], int left, int mid, int right){
	int left_idx = left;
	int right_idx = mid+1;
	int sorted_idx = left_idx;

	while(left_idx <= mid && right_idx <= right){
		if(arr[left_idx] <= arr[right_idx]){
			ans[sorted_idx++] = arr[left_idx++];
		}
		else{
			ans[sorted_idx++] = arr[right_idx++];
		}
	}
	
	if(left_idx > mid){
		for(int i=right_idx; i<=right; i++)
			ans[sorted_idx++] = arr[i];
	}
	
	if(right_idx > right){
		for(int i=left_idx; i<=mid; i++)
			ans[sorted_idx++] = arr[i];
	}
	
	for(int i = left; i <= right; i++)
		arr[i] = ans[i];
}

void merge_sort(int arr[], int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}	
}

int main(){
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	merge_sort(arr, 0, N-1);
	
	for(int i = 0; i < N; i++)
		cout << arr[i] << '\n';
	
	return 0;
}
