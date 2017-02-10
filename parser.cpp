#include<iostream>
#include<conio.h>
#include<string.h>

struct grammar{
	char p[1];
	char production[20]; 
}gmr[10];

int main(){

	int iter=0, n;

	cout<<"Enter the number of productions: "<<endl;
	cin>>n;

	char prods[10], input[100];

	cout<<"\nEnter productions:"<<endl;
	for(;iter<np;iter++){

		cin>>prods;
		strncpy(gmr[iter].p,prods,1);
		strcpy(gmr[iter].production,&prods[3]);

	}

	for(iter =0;iter<np;iter++){
		cout<< gmr[iter].p << gmr[iter].production <<endl;
	}
	return 0;
}