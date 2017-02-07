#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <regex>
// #include <bits/stdc++.h>
using namespace std;

int main(){
	regex integer("(\\+|-)?[[:digit:]]+");
	regex string1("(\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\")|(\'[^\'\\\\]*(?:\\\\.[^\'\\\\]*)*\')");
	regex varname("[a-zA-Z_][a-zA-Z0-9_]{0,31}");
	regex key1("if|else|elif|for|while|is|not|function|return|break|continue|goto");
	regex comm("#.*$");

	unordered_map<string, int> keyMap;
	// values 1-99 for keywords
	keyMap["if"] = 1;
	keyMap["else"] = 2;
	keyMap["elif"] = 3;
	keyMap["for"] = 4;
	keyMap["while"] = 5;
	keyMap["is"] = 6;
	keyMap["not"] = 7;
	keyMap["function"] = 8;
	keyMap["return"] = 9;
	keyMap["break"] = 10;
	keyMap["continue"] = 11;
	keyMap["goto"] = 12;
	// values 100-199 for punctuations
	keyMap[","] = 100;
	keyMap[";"] = 101;
	keyMap["\""] = 102;
	keyMap["\'"] = 103;
	keyMap["("] = 104;
	keyMap[")"] = 105;
	// values 200-299 for relational operators
	keyMap["*"] = 200;
	keyMap["/"] = 201;
	keyMap["+"] = 202;
	keyMap["-"] = 203;
	keyMap["="] = 204;
	keyMap["=="] = 205;
	keyMap["!="] = 206;
	keyMap[">="] = 207;
	keyMap["<="] = 208;
	// values 300-INFINITY for variable names
	unordered_map<string, int> symtab;

	string key;
	char in;
	int symtabIndex = 300;
	while(true){
		// cout<<"enter token:\t";
		cin >> key;
		string tempKey;

		int strB = 0;
		while(strB < key.length()){
			int i = strB;
			for(;strB<key.length();strB++){
				if(key[strB] == ' ' ||key[strB] == ',' ||key[strB] == ';' ||key[strB] == '+' ||key[strB] == '-' ||key[strB] == '*' ||key[strB] == '/' ||key[strB] == '(' ||key[strB] == ')') break;
				else if(key[strB] == '='  ||key[strB] == '>' ||key[strB] == '<' ||key[strB] == '!'){
					if(key[strB+1] == '=' && (strB-i<1)) strB+=2;
					break;
				}
			}
			int len;
			len = strB-i;
			if(len == 0){
				len = 1;
				strB++;
			}
			tempKey = key.substr(i,len);
			if(regex_match(tempKey,comm)) {
				cout<<"comment"<<endl;
				cout<<"----------------------------------------------------------------------"<<endl;
				break;
			}
			// cout << tempKey<<endl;
			unordered_map<string,int>::iterator it = symtab.find(tempKey);
			if(it == symtab.end()){
				    cout << tempKey << " not found\n";
				    unordered_map<string,int>::iterator keyIt = keyMap.find(tempKey);
				    if(keyIt != keyMap.end()){
				    	symtab[tempKey] = keyIt->second;
				    	cout << "added " << tempKey << " to symtab at index " << keyIt->second << endl;
				    }

				    else{
				    	symtab[tempKey] = symtabIndex++;
					    cout << "added " << tempKey << " to symtab at index " << symtabIndex-1 << endl;
					}
				}
			else
			    cout << "Found " << it->first <<" with value "<< it->second << "\n";
			if(regex_match(tempKey,key1)) cout<<"keyword"<<endl;
			else{
				if(regex_match(tempKey,varname)) cout<<"var"<<endl;
				if(regex_match(tempKey,string1)) cout<<"string"<<endl;
				if(regex_match(tempKey,integer)) cout<<"integer"<<endl;
			}
			cout<<"----------------------------------------------------------------------"<<endl;
		}
	}
	return 0;
}
