#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	while(cin>>n){
		if(n == 0)
			break;
		else
			cin>>m;
		//int result = Joseph_circut(n, m, 0);
		int res = 0;
		for(int i = 1; i <= n; i++)
			res = (res+m)%i;
		cout<<++res<<endl;
	}
	return 0;
}