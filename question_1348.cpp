#include <iostream>
using namespace std;
#define MAXIMUM 9999999
#define MINIMUM (-1)

int n;
int *a;

long long method_1(){
	if(n <= 1)
		return 0;
	long long *b;
	b = new long long [n];
	b[0] = 0;
	int maxValue = MAXIMUM;
	int minValue = MINIMUM;

	for(int i = 1; i < n; i++){
		b[i] = 0;
		
		maxValue = a[i] > maxValue? a[i] : maxValue;
		minValue = a[i] < minValue? a[i] : minValue;

		if(a[i] >= maxValue){
			b[i] = b[i-1];
			continue;
		}
		if(a[i] < minValue){
			b[i] = b[i-1] + i-1;
			continue;
		}

		for(int j = i-1; j >= 0; j--){

			if(a[j] > a[i])
				b[i]++;
		}
		b[i] += b[i-1];


	}
	long long result = b[n-1];
	delete []b;

	return result;
}

long long cnt = 0;
void merge(int *a ,int beg, int mid, int end){
	int leftLen = mid-beg+1;
	int rightLen = end-mid;
	int *left = new int[leftLen+1];
	int *right = new int[rightLen+1];

	for(int i = beg; i <= mid; i++)
		left[i-beg] = a[i];
	left[leftLen] = MAXIMUM;
	for(int i = mid+1; i <= end; i++)
		right[i-mid-1] = a[i];
	right[rightLen] = MAXIMUM;

	int leftIndex = 0;
	int rightIndex = 0;
	for(int i = beg; i <= end; i++){
		if(left[leftIndex] <= right[rightIndex]){
			a[i] = left[leftIndex];
			leftIndex++;
		}else{
			a[i] = right[rightIndex];
			rightIndex++;

			cnt += (leftLen - leftIndex);
		}
	}

	delete []left;
	delete []right;
}

void merge_sort(int *a, int beg, int end){
	if(beg >= end)
		return;
	int mid = (beg+end)/2;
	merge_sort(a, beg, mid);
	merge_sort(a, mid+1, end);
	merge(a, beg, mid, end);
}

long long method_2(){
	merge_sort(a, 0, n-1);
	return cnt;
}

int main(int argc, char const *argv[])
{
	while(cin>>n){
		cnt = 0;
		a = new int [n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		long long result = method_2();
		cout<<result<<endl;
		delete []a;
	}
	return 0;
}