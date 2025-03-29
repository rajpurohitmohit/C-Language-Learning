// Functions
#include<stdio.h>
#include<conio.h>

int sum(int a,int b);
int main(){
    int m = 5;
    int n = 8;
    printf("The sum is %d\n",sum(m,n));
    return 0;
}
int sum(int a,int b){
    return a+b;
}