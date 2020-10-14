#include<stdio.h>
void tower_hanoi(int n, char source,char dest,char aux)
{
    if(n==1)
    printf("\n Move from %c to %c",source, dest);
    
    else
    {
        tower_hanoi(n-1,source,aux,dest);
        tower_hanoi(1, source,dest,aux);
        tower_hanoi(n-1,aux,dest,source);
    }
}
main()
{
    int n;
    printf(" \n Enter the number of rings\n");
    scanf("%d",&n);
    tower_hanoi(n,'A','C','B');
}
