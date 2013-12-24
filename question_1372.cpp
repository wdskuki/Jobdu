#include <iostream>
#include <stdio.h>
using namespace std;

#define MINIMUM (-1001)
#define MAXIMUM 1001

int n;
int *a;

struct Range{
	int beg, end;
	int val;
};

Range changeValue(){
	Range Neg; // record if all the value is negtagive
	Neg.beg = Neg.end = -1;
	Neg.val = MINIMUM;

	Range Max; //record the max one
	Max.beg = Max.end = -1;
	Max.val = MINIMUM;

	Range Tem; //record the temp active value
	Tem.beg = Tem.end = -1;
	Tem.val = MINIMUM;

	for(int i = 0; i < n; i++){
		if(a[i] > Neg.val){
			Neg.val = a[i];
			Neg.beg = Neg.end = i;
		}
		
		if(i == 0)
			a[i] = a[i] >= 0? a[i] : 0;
		else{
			int t = a[i] + a[i-1];
			a[i] = t >= 0? t : 0;
		}
		
		// if(a[i] > 0){
		// 	if(Tem.beg == -1){
		// 		Tem.beg = i;
		// 		Tem.end = i;
		// 		Tem.val = a[i];
		// 	}else{
		// 		if(a[i] > Tem.val){
		// 			Tem.val = a[i];
		// 			Tem.end = i;
		// 		}
		// 	}
		// }else{
		// 	if(Max.val < Tem.val){
		// 		Max.val = Tem.val;
		// 		Max.beg = Tem.beg;
		// 		Max.end = Tem.end;
		// 	}
		// 	Tem.beg = Tem.end = -1;
		// 	Tem.val = MINIMUM;
		// }
	}
	return Neg;
}


Range findMax(){
	Range Neg = changeValue();
	if(Neg.val < 0)
		return Neg;

	Range Tem;
	Tem.beg = Tem.end = -1;
	Tem.val = MINIMUM;

	Range Max;
	Max.beg = Max.end = -1;
	Max.val = MINIMUM;

	for(int i = 0; i < n; i++){
		if(a[i] == 0 && Tem.beg != -1){
			if(Tem.val > Max.val){
				Max.val = Tem.val;
				Max.beg = Tem.beg;
				Max.end = Tem.end;
			}

		// cout<<Max.val<<" "
		// 	<<Max.beg<<" "
		// 	<<Max.end<<endl;

			Tem.beg = Tem.end = -1;
			Tem.val = MINIMUM;
		}else{
			if(Tem.beg == -1){
				Tem.beg = Tem.end = i;
				Tem.val = a[i];	
//				cout<<"aaaaaaa\n";			
			}else{
				if(a[i] > Tem.val){
					Tem.end = i;
					Tem.val = a[i];
//					cout<<"bbbbbbbb\n";
				}
//				cout<<"ccccccccccc\n";
			}
		// cout<<Tem.val<<" "
		// 	<<Tem.beg<<" "
		// 	<<Tem.end<<endl;
		}
	}
	if(Tem.val > Max.val){
		Max.val = Tem.val;
		Max.beg = Tem.beg;
		Max.end = Tem.end;
	}
	return Max;
}

void print(int *a, int len){
	for(int i = 0; i < len; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	while(cin>>n && n != 0){
		a = new int [n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Range Max = findMax();

	//	print(a, n);

		cout<<Max.val<<" "
			<<Max.beg<<" "
			<<Max.end<<endl;
		delete []a;
	}
	return 0;
}