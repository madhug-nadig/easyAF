# include<stdio.h>
//# include<conio.h>
# include<string.h>
struct declare
{
char id[10],type[10];
int off,w;
}a[10];
char ex[30],code[30],code1[30];
int ch,i=1,n;

void main()
{
//clrscr();
printf("\n\t\tGeneration of three address code");
while(1)
{
printf("\n1.if...then\n2.if...then...else\n3.while...do\n4.Code for declaration statement\n5.Exit\n");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter the conditional expression:");
scanf("%s",ex);
printf("\nTranslation scheme for if %s then...is",ex);
printf("\nEnter the code:");
scanf("%s",code);
printf("\n\tif %s goto L%d\n",ex,i);
printf("\tgoto *\n");
printf("L%d:\tt:=%s\n\tc:=t\n*:\tEnd\n",i,code);
break;
case 2:
printf("\nEnter the conditional expression:");
scanf("%s",ex);
printf("\nTranslation scheme for if %s then...else...is",ex);
printf("\nEnter the code:");
scanf("%s",code);
printf("\nEnter the code2:");
scanf("%s",code1);
printf("\n\tif %s goto L%d\n",ex,i);
printf("L%d:\tt:=%s\n",i+1,code1);

printf("\tc:=t\n\tgoto *\n");
printf("L%d:\tt:=%s\n\tc:=t\n*:\tEnd\n",i,code);
break;
case 3:
printf("\nEnter the conditional expression:");
scanf("%s",ex);
printf("\nTranslation scheme for while %s do...is",ex);
printf("\nEnter the code:");
scanf("%s",code);
printf("L%d:\twhile %s goto L%d\n\tgoto *\n",i,ex,i+1);
printf("L%d:\tt:=%s\n\tc:=t\n\tgoto L%d\n*:\tEnd\n",i+1,code,i);
break;
case 4:
printf("Enter the number of declarations:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter the identifier:");
scanf("%s",a[i].id);
printf("\nEnter the type of identifier:");
scanf("%s",a[i].type);
}
a[0].off=0;
if(strcmp(a[0].type,"int")==0)
a[0].w=4;
if(strcmp(a[0].type,"real")==0)
a[0].w=8;
for(i=1;i<n;i++)
{
if(strcmp(a[i].type,"int")==0)
{
a[i].off=a[i-1].off+a[i-1].w;
a[i].w=4;
}
if(strcmp(a[i].type,"real")==0)
{
a[i].off=a[i-1].off+a[i-1].w;
a[i].w=8;
}
}
printf("\nIdentifier\tType\tOffset\tWidth\n");
printf("%s\t\t%s\t%d\t%d\n",a[0].id,a[0].type,a[0].off,a[0].w);
for(i=1;i<n;i++)
printf("%s\t\t%s\t%d\t%d\n",a[i].id,a[i].type,a[i].off,a[i].w);
break;
case 5:
exit(0) ;
default:
printf("\nChoice is wrong\n");
}
}
}
