#include <iostream>
using namespace std;

long addTwoElem(long a, long b){
	long xorRes = a ^ b;
	long andRes = a & b;
	if(andRes == 0)
		return xorRes;
	else
		return addTwoElem(xorRes, andRes);
}

long n;
int main(int argc, char const *argv[])
{
	while(cin>>n){
		
	}
	return 0;
}