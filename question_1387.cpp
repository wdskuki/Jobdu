#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		if(n == 1){
			cout<<1<<endl;
			continue;
		}
		long f[100];
		f[0] = 0;
		f[1] = 1;
		for(int i = 2; i <= n; i++)
			f[i] = f[i-1]+ f[i-2];
		cout<<f[n]<<endl;
	}
	return 0;
}