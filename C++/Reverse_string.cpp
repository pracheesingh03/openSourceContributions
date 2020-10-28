#include<iostream.h>
#include<stdio.h>
#include<string.h>
 
int main()
{
	char a[50],temp;
	int i,j,len;
	cout<<"Enter any string:\n";
	gets(a);
	len=strlen(a);
 
	cout<<"Reverse of the string is: ";
 
	for(i=0,j=len-1;i<len/2;++i,--j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
 
	cout<<a;
	return 0;
}
