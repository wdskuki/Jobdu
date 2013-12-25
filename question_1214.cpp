
#include <iostream>
using namespace std;
// #define MAXIMUM 1501
// int a[MAXIMUM];

// bool isUglyNumber(int a){
// 	if(a == 1)
// 		return true;
// 	while(a%2 == 0)
// 		a /= 2;
// 	while(a%3 == 0)
// 		a /= 3;
// 	while(a%5 == 0)
// 		a /= 5;
// 	return (a == 1);
// }

// void init(){
// 	for(int i = 0; i < MAXIMUM; i++)
// 		a[i] = -1;
// }

// long long find_N(int n){
// 	int index = 1;
// 	long long count = 0;
// 	while(1){
// 		if(isUglyNumber(index)){
// 			count++;
// 			if(count == n)
// 				return index;
// 			else
// 				index++;
// 		}else{
// 			index++;
// 		}
// 	}
// }



// int main(int argc, char const *argv[])
// {
// 	int n;
// 	while(cin >> n){
// 		long long result = find_N(n);
// 		cout<<result<<endl;
// 	}
// 	return 0;
// }



int n;
long long * a;

long long minTriple(long long t1, long long t2, long long t3){
	long long t = t1 < t2? t1 : t2;
	t = t < t3? t: t3;
	return t;
}

long long findUglyNum(){
	if(n == 1)
		return 1;
	int T2, T3, T5;
	a = new long long[n+1];
	a[1] = 1;
	T2 = T3 = T5 = 1;
	for(int i = 2; i <= n; i++){
		a[i] = minTriple(a[T2]*2, a[T3]*3, a[T5]*5);
		if(a[i] == a[T2]*2)
			T2++;
		if(a[i] == a[T3]*3)
			T3++;
		if(a[i] == a[T5]*5)
			T5++;
	}
	long long result = a[n];
	delete []a;
	return result;
}

int main(int argc, char const *argv[])
{
	while(cin>>n){
		long long result = findUglyNum();
		cout<<result<<endl;
	}
	return 0;
}