#include <iostream>
#include <stdlib.h>
using namespace std;
char pipei(char a[],int &i)
{
	int ok=0;
	if(a[i]==0) return ok;
	
	while(a[i]=='(' || a[i]=='[' || a[i]=='{')
	{
		if(a[i]=='(')      {i++; if(pipei(a,i)==1) ok=6; else return 0;}
		else if(a[i]=='[') {i++; if(pipei(a,i)==2) ok=6; else return 0;}
		else if(a[i]=='{') {i++; if(pipei(a,i)==3) ok=6; else return 0;}
	}

	if(a[i]==')') {i++; return 1;}
	else if(a[i]==']') {i++; return 2;}
	else if(a[i]=='}') {i++; return 3;}
	return ok;
}

int main()
{
	char a[500],b[500];
	gets(a);
	while(a[0]!=0)
	{
	int i=0,m=0;
	for(i=0;a[i]!=0;i++)
		if(a[i]=='('||a[i]==')'||a[i]=='['||a[i]==']'||a[i]=='{'||a[i]=='}')
			b[m++]=a[i];
	b[m]=0;
	i=0;
	if((int)pipei(b,i)==6) cout << "yes" << endl;
		else cout << "no" << endl;
	
	gets(a);
	}


	return 0;
}
