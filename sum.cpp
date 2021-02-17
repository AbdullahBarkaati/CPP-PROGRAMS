#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int addition(int x,int y);
int main(){
	int x,y,z,i;
	printf("Enter Two Numbers...") ;
	scanf("%d%d",x,y);

/*	//first method using + operator without storing result in other variable
	//time complexity O(1)
	//space complexity required for storing only 2 variables

	cout << x+y ;

	//second method using + operator with storing result in other variable
	//time complexity O(1)
	//space complexity required for storing 3 variables

	z=x+y;
	cout << z ;

	//third method using - operator
	//time complexity O(1)
	//space complexity required for storing only 2 variables

	cout << x-(-y) ;


	//fourth method using ++(increment) operator
	//time complexity O(n) where n = x or y 
	//space complexity required for storing 3 variables
	
	i = 0 ;
	while(i<x){
		y++;
		i++;
	}
	cout << y ;

	//fifth method using bitwise operator
	//time complexity O(n) where n = x or y 
	//space complexity required for storing 3 variables
	
	i = 0 ;
	while(i<x){
		y++;
		i++;
	}
	cout << y ;	*/
	printf("%*d",x,y) ;
	return 0;
}