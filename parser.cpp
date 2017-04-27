#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

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
	for(;iter<n;iter++){

		cin>>prods;
		strncpy(gmr[iter].p,prods,1);
		strcpy(gmr[iter].production,&prods[3]);

	}

	cout<<"\nEnter the string to be parsed:"<<endl;
	cin>>input;

	int ip_length = strlen(input);

	char stack[10], scann;
	
	int start_position=0, position, k, j, f, l, m;
	int state;
	iter=0;
	
	//Let us move the INPUT

	scann=input[iter];

	//Push the first character into the stack
	stack[start_position]=scann;

	//Actual move
	iter++;
	start_position++;

	cout<<"\n\nStack\tInput\tAction"<<endl;
	do
	{
		//Initialize the state State 2 = Reduced State 1 = Shift
		state=1;
		while(state!=0){

			cout<<"\n";
			for(position=0; position<start_position; position++){
				cout<<stack[position];
			}

			cout<<"\t";
			for(position=iter; position<ip_length; position++){
				cout<<input[position];
			}

			if(state==2){
				cout<<"\tReduced";
			}

			else{
				cout<<"\tShifted";
			}

			state=0;
			
			//Let's see if reduction is possible here
			getch();
	
		for(k=0;k<start_position;k++){
				f=0;

				for(j=0;j<10;j++)
				{
					prods[j]='\0';
				}

				int prods_pos=0;

				for(j=k; j<start_position; j++){ //removing first Char
					prods[prods_pos]=stack[j];
					prods_pos++;
				}
				
				//Comparing each possibility with production
				for(m=0 ;m<n; m++){
					int cr = strcmp(prods,gmr[m].production);

					//if cr is zero then match is found
					if(cr==0)
					{
						for(l=k;l<10;l++) //removing matched part from our beloved stack
						{
							stack[l]='\0';
							start_position--;
						}

						start_position=k;

						//concatinate the string
						strcat(stack,gmr[m].p);
						start_position++;
						state=2;
					}
				}
			}
		}

		//moving input
		scann=input[iter];
		stack[start_position]=scann;
		iter++;
		start_position++;

	}while(strlen(stack)!=1 && start_position!=ip_length+1);

	if(strlen(stack)==1){
		cout<<"\nString Accepted";
	}
	else{
		cout<<"\nRejected";
	}

	getch();

	//Success, HELL YEAH!
	return 0;
}