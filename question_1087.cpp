/* 对于一个大于1正整数n可以分解质因数：n=p1^a1*p2^a2*p3^a3*…*pk^ak,
 * 则n的正约数的个数就是（a1+1）（a2+1）（a3+1）…(ak+1) 
 * 其中p1，p2，p3，…pk都是n的质因数;a1、a2、a3…ak是p1、p2、p3，…pk的指数
 */

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
long long num = 1;


bool isPrime(long long a){
	if(a == 2)
		return true;
	if(a%2 == 0)
		return false;
	long long st = sqrt(a);
	long long t = a > 9? st : 9;
	for(long long i = 3; i <= t; i+=2){
		if(a%i == 0)
			return false;
	}
	return true;
}

void func(long long a){
	long long b = a;
	long long count = 0;
	while(a%2 == 0){
		++count;
		a /= 2;
	}
	num *= (count+1);

	for(long long i = 3; i <= a; i+=2){
		count = 0;
		if(!isPrime(a)){
			while(a%i == 0){
				++count;
				a /= i;
			}
			num *= (count+1);
		}else{
			count = 1;
			num *= (count+1);
			break;
		}
	}

}



int main(int argc, char const *argv[])
{
	int N;
	while(scanf("%d", &N) != EOF){
		if(N == 0) break;

		long long *a = new long long [N];
		for(int i = 0; i < N; i++)
			cin>>a[i];
		for(int i = 0; i < N; i++){
			num = 1;
			func(a[i]);
			cout<<num<<endl;
		}
	}
	return 0;
}