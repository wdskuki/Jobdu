#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// int main(int argc, char const *argv[])
// {
// 	string str;
// 	while(getline(cin, str)){
// 	istringstream stream(str);
// 	vector<string> svec;
// 	string word;
// 	while(stream >> word)
// 		svec.push_back(word);

// 	int len = svec.size();
// 	for(int i = 0; i != len; i++){
// 		if(i == len-1)
// 			cout<<svec[i]<<endl;
// 		else
// 			cout<<svec[i]<<"%20";
// 	}
// }
// 	//cout<<str<<endl;
// 	return 0;
// }

int main(int argc, char const *argv[])
{
	string str;
	while(getline(cin, str)){
		//const char* chr = str.c_str();
		//cout<<chr<<endl;
		int len = str.size();
	//	char *chr = new char [len+1];
	//	strcpy(chr, str.c_str());

		for(int i = 0; i < len; i++){
			if(str[i] != ' ')
				cout<<str[i];
			else{
				cout<<"%20";
			}		
		}
		cout<<endl;
	}
	return 0;
}