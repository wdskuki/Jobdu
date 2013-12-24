#include <iostream>
#include <stack>
using namespace std;

void print(stack<int>& istack){
	while(!istack.empty()){
		cout<<istack.top()<<endl;
		istack.pop();
	}
}

int main(int argc, char const *argv[])
{
	int t;
	stack<int> istack;
	while(cin>>t){
		if(t == -1){
			print(istack);
			break;
			//istack.clear();
		}
		else{
			istack.push(t);
		}
	}
	return 0;
}