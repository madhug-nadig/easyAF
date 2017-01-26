#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <regex>
// #include <bits/stdc++.h>
using namespace std;

int main(){
	unordered_map<string, int> umap;
	umap["if"] = 1;
	umap["else"] = 2;
	umap["elif"] = 3;
	umap["for"] = 4;
	umap["while"] = 5;
	umap["is"] = 6;
	umap["not"] = 7;
	umap["function"] = 8;
	umap["return"] = 9;
	umap["break"] = 10;
	umap["continue"] = 11;
	umap["goto"] = 12;

	unordered_map<string, int> symtab;

	string key;
	char in;
	int symtabIndex = 0;
	
	while(true){
		cin >> key;
		string tempKey;
		
		int strB = 0;
		while(strB < key.length()){
			int i = strB;
			// cout<<strB<<" "<<key.length()<<endl;
			for(;strB<key.length();strB++){
				if(key[strB] == ' ' ||key[strB] == ',' ||key[strB] == ';' ||key[strB] == '+' ||key[strB] == '-' ||key[strB] == '*' ||key[strB] == '/') break;
			}
			tempKey = key.substr(i,(strB-i));
			cout << tempKey<<endl;
			unordered_map<string,int>::iterator it = symtab.find(tempKey);
			if(it == symtab.end()){
				    cout << tempKey << " not found\n";
				    symtab[tempKey] = symtabIndex++;
				    cout << "added " << tempKey << " to symtab at index " << symtabIndex-1 << endl;
				}
			else
			    cout << "Found " << it->first <<" with value "<< it->second << "\n";
			cout<<"--------------------------------------------"<<endl;

			if(key[strB] == ' ' ||key[strB] == ',' ||key[strB] == ';' ||key[strB] == '+' ||key[strB] == '-' ||key[strB] == '*' ||key[strB] == '/'){
				string temp = key.substr(strB,1);
				it = symtab.find(temp);
				if(it == symtab.end()){
					    cout << temp << " not found\n";
					    symtab[temp] = symtabIndex++;
					    cout << "added " << key[strB] << " to symtab at index " << symtabIndex-1 << endl;
					}
				else
				    cout << "Found " << it->first <<" with value "<< it->second << "\n";
				cout<<"--------------------------------------------"<<endl;
			}
			strB++;
		}
	}
	
	return 0;
}