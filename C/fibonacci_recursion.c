#include <stdio.h>
int fib(int a,int b,int n){
  int c=0;
  if(n==0){
    return c;
  }
  else{
    c=a+b;
    printf(" %d",a);
    a=b;
    b=c;
    return fib(a,b,n-1);
}
}
int main(){
  int N;
  printf("Enter the number of terms\n");
  scanf("%d",&N);
  int f=fib(0,1,N);
  return 0;
}
