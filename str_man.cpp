#include<iostream>
#include<string>

using namespace std;

string reverse(string str){
	string rev;
	char c;
	int i=0,j=str.length()-1;
	while(i<j){
		c=str[i];
		str[i]=str[j];
		str[j]=c;
		i++;
		j--;
	}
	cout << "IN FUNCTION" ;
	//rev[j]='\0' ;
	return str;
}

string rev_str(string str){
	int i,j;
	string rev;
	for(i=0;str[i]!='\0';i++);
	for(j=0,i=i-1;i>=0;j++,i--){
		rev[j]=str[i];
	}
	rev[j]='\0';
	return rev;		
}
int isChar(char c){
	if((c>='A' && c<='Z') || (c>='a' && c<='z')){
		return 1;
	}
	return 0;
}
string rev_without_numeral(string str){
	int i=0,j=str.length()-1;
	char c;
	string rev;
	while(i<j){
		if(!isChar(str[i])){
//			cout << str[i] <<"\t" ;
			i++;
		}
		else if(!isChar(str[j])){
			
			j--;
		}
		else{
			c=str[i];
			str[i]=str[j];
			str[j]=c;
			i++;
			j--;
		}
	}
	return str;
}
int main(){
	string str,rev;
	cout << "Enter String..." ;
	cin >> str;
	rev = reverse(str);
	cout << "AFTER FIRST"  << rev;
	rev=rev_without_numeral(str);
	cout << "\nAFTER SECOND" << rev; 
	return 0;
}