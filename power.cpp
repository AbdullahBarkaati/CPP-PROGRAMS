#include<iostream>
 
using namespace std;

int power(int num,int pow){
	int i=0,res=1;
	while(i<pow){
		res=res*num;
		i++;
	}
	return res;
}

int power_recursion(int num,int pow){
	if(pow==0){
		return 1;
	}
	else{
		return num*power_recursion(num,pow-1);
	}
}

int power_divide(int num,int pow){
	if(pow==0){
		return 1;
	}
	else if(pow==1){
		return num;
	}
	else{
		if(pow%2==0){
			return (power(num,pow/2)*power(num,pow/2));
		}
		else{
			return (power(num,1)*power(num,pow-1));
		}
	}
}
int main(){
	int num,pow;
	cout << "Enter Number And Power....." ;
	cin >>num>>pow;
	cout << power(num,pow) << "\n";
	cout << power_recursion(num,pow) << "\n";
	cout << power_divide(num,pow);
	return 0;
}