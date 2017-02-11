#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <regex>

using namespace std;

int main(){
	regex integer("(\\+|-)?[[:digit:]]+");
	regex string1("(\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\")|(\'[^\'\\\\]*(?:\\\\.[^\'\\\\]*)*\')");
	regex varname("[a-zA-Z_][a-zA-Z0-9_]{0,31}");
	regex key1("if|else|elif|for|while|is|not|function|return|break|continue|goto");
	regex relop("<|>|==|!=|>=|<=");
	regex op("\\+|\\-|\\*|\\/");
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
	
	//key is the variable that stores the raw input string
	string key;
	
	//Symtab index stores value in the key value pair. Set it 300 default for variables. Start at line number 1. Comment flag set to zero.
	int symtabIndex = 300, line = 0;

	// boolean flag to keep track whether the input string is a comment or not.
	bool comment_flag = false;
	
	//Infinite loop, keeps taking ip for now. File I/O will take care of this.
	while(true){

		//Take the input
		getline(cin,key);

		// increment the line
		line++;

		// make flag set to false intitally
		comment_flag = false;

		//TempKey is where we store the extracted substring, ie. something that matches a regex or a hashed value
		string tempKey;


		//strb is used so as to find out the end of a matched substring.
		int strB = 0;
		

		while(strB < key.length()){
			// if the input string is a comment, break out of the loop.
			if(comment_flag) break;

			//i stores the starting index of the substring.
			int i = strB;
			for(;strB<key.length();strB++){
				//Below is where we figure out the breakpoint for the substring.
				if(key[strB] == ' ' ||key[strB] == ',' ||key[strB] == ';' ||key[strB] == '+' ||key[strB] == '-' ||key[strB] == '*' ||key[strB] == '/' ||key[strB] == '(' ||key[strB] == ')') 
					break;
				//Lookahead for certain operators
				else if(key[strB] == '='  ||key[strB] == '>' ||key[strB] == '<' ||key[strB] == '!'){
					if(key[strB+1] == '=' && (strB-i<1)) {
						//Incrementing it by to 2 so as to compensate for the look ahead.
						strB+=2;
					}
					break;
				}
			}

			int len; // length of the substring
			len = strB-i;
			// If a single character then, len will be 0 since no increment is carried in that case, this following if will take of of it.
			if(len == 0){
				len = 1;
				strB++;
			}
			
			tempKey = key.substr(i,len);
			//If comment, break out. No need to fiddle around the Symbol table.
			if(regex_match(tempKey,comm)) {
				cout<<"comment"<<endl;
				// set the flag indicating the string is a comment.
				comment_flag = true;
				cout << "Line number: " << line<< endl;
				cout<<"----------------------------------------------------------------------"<<endl;
				break;
			}

			// TODO: Fix this. The entry will be added to symtab regardless of it's prior presence
			unordered_map<string,int>::iterator it = symtab.find(tempKey);
			// Not found in symtab
			if(it == symtab.end()){
				    cout << tempKey << " not found in the Symbol table. \n";
				    // Find the type of the matched string.
				    unordered_map<string,int>::iterator keyIt = keyMap.find(tempKey);
				    // Add to the symbol table
				    if(keyIt != keyMap.end()){
				    	symtab[tempKey] = keyIt->second;
				    	cout << "added " << tempKey << " to symtab at index " << keyIt->second << endl;
				    }
				    // Else add it by using the def symtabIndex, because it's not a kw/punctuation/operator.
				    else{
				    	symtab[tempKey] = symtabIndex++;
					    cout << "added " << tempKey << " to symtab at index " << symtabIndex-1 << endl;
					}

				}
			else
			    cout << "Found in the symbol" << it->first <<" with value "<< it->second << "\n";
			// Use RegEx to find the type of token.
			if(regex_match(tempKey,key1)) cout<<"keyword"<<endl;
			else{
				if(regex_match(tempKey,varname)) cout<<"var"<<endl;
				else if(regex_match(tempKey,string1)) cout<<"string"<<endl;
				else if(regex_match(tempKey,integer)) cout<<"integer"<<endl;
				else if(regex_match(tempKey,relop)) cout<<"Relational Operator"<<endl;
				else if(regex_match(tempKey,op)) cout<<"Operator"<<endl;
				else cout<<"ERROR! Plx check the syntax"<<endl;
			}
			cout << "Line number: " << line<< endl;
			cout<<"----------------------------------------------------------------------"<<endl;
		}
	}
	// Return SUCCESS. HELL YEAH!
	return 0;
}
