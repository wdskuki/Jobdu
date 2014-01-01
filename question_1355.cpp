#include <iostream>
#include <stdlib.h>
using namespace std;

int cmp(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}
int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		if(n == 0)
			break;
		if(n < 5){
			cout<<"Oh My God!"<<endl;
			continue;
		}
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		qsort(a, n, sizeof(int), cmp);

		int zeroNum = 0;
		int gapNum = 0;
		for(int i = 0; i < n; i++){
			if(a[i] == 0)
				zeroNum++;
			if(i < n-1 && (a[i+1] - a[i] == 2))
				gapNum++;
		}
		if(gapNum <= zeroNum)
			cout<<"So Lucky!"<<endl;
		else
			cout<<"Oh My God!"<<endl;

		delete []a;
	}
	return 0;
}