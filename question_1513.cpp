#include <iostream>
#include <stdio.h>
using namespace std;


int countNum(int t){
	int count = 0;
	if(t > 0){
		while(t != 0){
			if(t%2 == 1)
				count++;
			t /= 2;
		}
	}else if(t < 0){
		t = ~t;
		while(t != 0){
			if(t%2 == 1)
				count++;
			t /= 2;
		}
		count = 32 - count;
	}

	return count;
}

void print(int *a, int len){
	for(int i = 1; i <= len; i++)
		cout<<a[i]<<"\n";
}

int main(int argc, char const *argv[])
{
	// int a = -2;
	// printf("%x\n", a);
	// a = ~a;
	// printf("%x\n", a);

	int n;
	while(cin>>n){
		int t;
		int *a = new int[n+1];
		int index = 1;
		for(int i = 0; i < n; i++){
			cin>>t;
			int num = countNum(t);
			//cout<<num<<endl;
			a[index++] = num;
		}

		print(a, n);
		delete []a;
	}
	return 0;
}