#include <sstream>
#include <stack>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string line;
	while(getline(cin, line)){
		istringstream istream(line);
		string word;
		stack<string> sstack;
		while(istream>>word)
			sstack.push(word);
		bool flag = false;
		while(!sstack.empty()){
			if(flag == false){
				flag = true;
				cout<<sstack.top();
			}else{
				cout<<" "<<sstack.top();
			}
			sstack.pop();
		}
		cout<<endl;
	}
	return 0;
}