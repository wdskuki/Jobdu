/* 对于一个大于1正整数n可以分解质因数：n=p1^a1*p2^a2*p3^a3*…*pk^ak,
 * 则n的正约数的个数就是（a1+1）（a2+1）（a3+1）…(ak+1) 
 * 其中p1，p2，p3，…pk都是n的质因数;a1、a2、a3…ak是p1、p2、p3，…pk的指数
 */

#include <iostream>
#include <math.h>
using namespace std;
long num = 1;

void func(long a){
	int b = a;
	int count = 0;
	while(a%2 == 0){
		++count;
		a /= 2;
	}
	num *= (count+1);



	for(int i = 3; i <= a; i+=2){
		count = 0;
		while(a%i == 0){
			++count;
			a /= i;
		}
		num *= (count+1);
	}
}



int main(int argc, char const *argv[])
{
	int N;
	while(cin>>N){
		if(N == 0) break;
		long a;
		for(int i = 0; i < N; i++){
			cin>>a;
			num = 1;
			func(a);
			cout<<num<<endl;
		}
	}
	return 0;
}