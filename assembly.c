#include"stdio.h"
//#include"conio.h"
#include"string.h"
#include"stdlib.h"
struct quadraple
{
char op;
char arg1[5];
char arg2[5];
char result[5];
}quad[15];
int n=0;
char expn[20][20];
void assignment(int);
void uminus(int );
void explore();
void codegen(char op[5],int);
char tuple[15][15];
int main(void)
{
int nRetInd,i,m;
char str[15];
//clrscr();
printf("Enter the no of statements\n");
scanf("%d",&m);
printf("Enter the statements\n");
for(i=0;i<m;i++)
{
scanf("%s",&expn[i]);
strcpy(tuple[n++],expn[i]);
}
explore();
i=0;
printf("\n\ncode generated :\n");
while(i< n)
{
if(quad[i].op=='+')
codegen("ADD",i);
if(quad[i].op=='=')
assignment(i);
if(quad[i].op=='-')
if(!strcmp(quad[i].arg2,"\0"))
uminus(i);
else
codegen("SUB",i);
if(quad[i].op=='*')
codegen("MUL",i);
if(quad[i].op=='/')
codegen("DIV",i);
i++;
}
//getch();
return 0;
}
void codegen(char op[5],int t)
{
char str[25];
printf("MOV R0,%s\n",quad[t].arg1);
printf("%s R0,%s\n",op,quad[t].arg2);
printf("MOV %s,R0\n",quad[t].result);
}
void assignment(int t)
{
char str[25];
printf("MOV R0,%s\n", quad[t].arg1);
printf("MOV %s,R0\n", quad[t].result);
}
void uminus(int t)
{
char str[25];
printf("MOV R0,0\n");
printf("SUB R0,%s\n",quad[t].arg1);
printf("MOV %s,R0\n",quad[t].result);
}

void explore()
{
int i,j,t,t1,t2;
for(i=0;i < n;i++)
{
for(j=0,t=0;j < strlen(tuple[i])&&tuple[i][j]!='=';j++)
{
quad[i].result[t++]=tuple[i][j];
}
t1=j;
quad[i].result[t]='\0';
if(tuple[i][j]=='=')
{
quad[i].op='=';
}
if(tuple[i][j+1]=='+'||tuple[i][j+1]=='-'||tuple[i][j+1]=='*'||tuple[i][j+1]=='/')
{
quad[i].op=tuple[i][j+1];
t1=j+1;
}
for(j=t1+1,t=0;j<strlen(tuple[i])&&tuple[i][j]!='+'&&tuple[i][j]!='-'&&tuple[i][j]!='*'&&tuple[i][j] !='/';j++)
{
quad[i].arg1[t++]=tuple[i][j];
}
t2=j;
quad[i].arg1[t]='\0';
if(tuple[i][j]=='+'||tuple[i][j]=='-'||tuple[i][j]=='*'||tuple[i][j]=='/')
{
quad[i].op=tuple[i][j];
}
for(j=t2+1,t=0;j< strlen(tuple[i]);j++)
{
quad[i].arg2[t++]=tuple[i][j];
}
quad[i].arg2[t]='\0';
}
}
