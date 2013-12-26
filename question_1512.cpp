#include <stack>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Queue{
public:
	stack<int> s1;
	stack<int> s2;
	
	void push(int a){
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		s1.push(a);
	}
	int pop(){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		if(s2.empty())
			return -1;
		else{
			int result = s2.top();
			s2.pop();
			return result;
		}
	}
};


class Queue2{
public:
	stack<int> s1;
	stack<int> s2;
	
	void push(int a){
		s1.push(a);
	}
	int pop(){
		if(s1.empty())
			return -1;
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		int result = s2.top();
		s2.pop();

		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		return result;
	}
};

class Queue3{
public:
	stack<int> s1;
	stack<int> s2;
	
	void push(int a){
		if(!s1.empty())
			s1.push(a);
		else{
			while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}
			s1.push(a);
		}
	}
	int pop(){
		int result;
		if(!s2.empty()){
			result = s2.top();
			s2.pop();
			return result;
		}else{
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			if(s2.empty())
				return -1;
			else{
				result = s2.top();
				s2.pop();
				return result;
			}
		}
	}
};


class Queue4{
public:
	stack<int> s1;
	stack<int> s2;
	
	void push(int a){
		s1.push(a);
	}
	int pop(){
		int result;
		if(!s2.empty()){
			result = s2.top();
			s2.pop();
			return result;
		}else{
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			if(s2.empty())
				return -1;
			else{
				result = s2.top();
				s2.pop();
				return result;
			}
		}
	}
};


int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		Queue4 q;
		string oper;
		int num;
		for(int i = 0; i < n; i++){
			cin>>oper;
			if(oper.compare("PUSH") == 0){
				cin>>num;
				//scanf("%d", &num);
				q.push(num);
			}else if(oper.compare("POP") == 0){
				int result = q.pop();
				cout<<result<<endl;
			}
		}
	}
	return 0;
}
