#include <iostream>
using namespace std;
long long *a;
void rectangleFill(int n){
	//if(n == 1 || n == 2)
	//	return n;
	//int *a = new int[n+1];
	a[1] = 1;
	a[2] = 2;
	for(int i = 3; i <= n; i++)
		a[i] = a[i-1] + a[i-2];
	//int result = a[n];
	//delete []a;
	//return result;
}

int main(int argc, char const *argv[])
{
	int n;
	a = new long long [100];
	rectangleFill(100);
	while(cin>>n){
		cout<<a[n]<<endl;
	}
	delete []a;
	return 0;
}