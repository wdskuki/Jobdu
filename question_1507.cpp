#include <iostream>
using namespace std;

int bitCompAdd(int a, int b){
	int xorRes = a ^ b;
	int andRes = a & b;

	if(andRes != 0){
		return bitCompAdd(xorRes, andRes<<1);
	}else
		return xorRes;
}

int main(int argc, char const *argv[])
{
	int a, b;
	while(cin>>a>>b){
		int res = bitCompAdd(a,b);
		cout<<res<<endl;
	}
	return 0;
}