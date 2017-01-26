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

	return 0;
}