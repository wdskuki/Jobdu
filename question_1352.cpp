#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXIMUM 10000001
int n, k;
int *a;

struct Resut{
	int a, b;
	int mult;
}result;


bool binary_search(int beg, int end, int val, int &index){
	if(beg > end){
		return false;
	}
	int mid = (beg+end)/2;
	if(a[mid] == val){
		index = mid; 
		return true;
	}
	else if(a[mid] > val){
		index = mid;
		return binary_search(beg, mid-1, val, index);
	}
	else{
		index = end;
		return binary_search(mid+1, end, val, index);
	}
}

void findRes(){
	int index = n-1;
	for(int i = 0; i < n; i++){
		if(a[i]*2 > k) break;
		if(binary_search(i+1, index, k-a[i], index)){
			int t = a[i]*(k-a[i]);
			if(result.mult > t){
				result.a = a[i];
				result.b = k-a[i];
				result.mult = t;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	while(cin>>n>>k){
		result.a = result.b = -1;
		result.mult = MAXIMUM;
		a = new int [n];
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		findRes();
		cout<<result.a<<" "<<result.b<<endl;

		delete []a;
	}
	return 0;
}