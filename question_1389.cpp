#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		if(n == 1 || n == 2){
			cout<<n<<endl;
			continue;
		}
		long f[100];
		f[1] = 1;
		f[2] = 2;
		for(int i = 3; i <= n; i++){
			f[i] = 1;
			for(int j = 1; j < i; j++)
				f[i] += f[j];
		}
		cout<<f[n]<<endl;
	}
	return 0;
}