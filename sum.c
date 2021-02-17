//Name : Abdullah Mohammed Sabir
//Roll Number : R19111001

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int addition(int x,int y);
int main(){
	int x,y,z,i,temp,carry,sum;
	printf("Enter Two Numbers...") ;
	scanf("%d%d",&x,&y);


	//first method using + operator without storing result in other variable
	//time complexity O(1)
	//space complexity is memory required for storing 2 integer variables

		printf("sum=%d\n", x+y) ;


	//second method using + operator with storing result in other variable
	//time complexity O(1)
	//space complexity is memory required for storing 3 integer variables

		z=x+y;
		printf("sum=%d\n", z) ;


	//third method using - operator
	//time complexity O(1)
	//space complexity is memory required for storing 2 integer variables

		printf("sum=%d\n", x-(-y)) ;


	//fourth method using ++(increment) operator
	//time complexity O(n) where n = x or y 
	//space complexity is memory required for storing 3 integer variables
	
		i = 0 ;
		temp=y; //temp is used in order to not change the value of y
		while(i<x){
			temp++;
			i++;
		}
		printf("sum=%d\n", temp) ;


	//fifth method using printf function as printf returns number of characters printed
	//time complexity O(1) 
	//space complexity is memory required for storing 2 integer variables
	
		printf("sum=%d \n",printf("%*c%*c",x, '\r',y, '\r')) ;


	//sixth method using bitwise operator
	//time complexity is O(1) //not sure
	//space complexity is memory required for storing 3 ineteger variables 
		temp=y;
		sum=x; //sum is used in order to not change the value of x
		while(temp!=0){
			carry= sum & temp;
			sum= sum^temp;
			temp= carry<<1 ;
		}
		printf("sum=%d \n",sum);


	//seventh method using logarithmic and exponential method
	//time complexity is O(1) //not sure
	//space complexity is memory required for storing 2 integer variables
	
		printf("sum=%g\n", log(exp(x) * exp(y)));


	//eightth method using function call
		printf("sum=%d\n",addition(x,y)); 
	
	
	return 0;
}

int addition(int x,int y){
	//time complexity is O(1)
	//space complexity is memory required for storing 2 integer variables
	return x+y ;
}


//best solution among all these is first one (in my opinion)