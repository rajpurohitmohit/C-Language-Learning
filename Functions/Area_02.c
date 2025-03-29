#include<stdio.h>

int sq(int f);
int rec(int g, int h);
int cir(float r);

int main(){
    int a,b,c;
    float d;
    printf("Enter the side of square:- ");
    scanf("%d",&a);

    printf("The area of Square is:- %d",sq(a));

    printf("\nEnter the length and breadth of the rectangle:- ");
    scanf("%d",&b);
    scanf("%d",&c);

    printf("The area of the rectangle would be:- %d",rec(b,c));


    printf("\nEnter the radius of the circle:- ");
    scanf("%f",&d);

    printf("The area of circle is:- %d",cir(d));
    return 0;
}
int sq(int f){
    f*=f;
    return f;
}
int rec(int g, int h){
    g * h;
    return g*h;
}

int cir(float r){
    float s = 3.14 * (r*r);
    return s;
}