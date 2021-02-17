#include<iostream>
#include<string>

using namespace std;

/*string rev_line(string line){
	int i=0,j=line.length()-1;
	string rev;
	char c;
	while(i<j){
		c=line[i];
		line[i]=line[j];
		line[j]=c;
//		cout << line[i] << line[j] <<"\t" ;
		i++;
		j--;
	}
	//rev[i]='\n';
	return line;
}

string rev_line_words(string line){
	string rev;
	int j=line.length()-1,cur=0,k;
	while(j>=0){
		if(line[j]==' '){
			k=j;	
			while(line[k]!=' ' || line[k]!='\n'){
				rev[cur++]=line[k++];
			}
			rev[cur++]=' ';
		}
		j--;
	}
	return rev;
}

string rev_words_line(string str){
	int i=0,j=str.length(),cur,end,ind=0,k=0;
	string rev[10],line;
	while(i<j){
		cur=i;
		while(str[i]!=' '){
			i++;
		}
		while(cur<i){
			rev[ind][k++]=str[cur++];
		}
	//	rev[ind][k]='\0';
	//	ind++;
	//	k=0;
	//	if(str[i]==' '){
	//		cur++;
	//	}
		i++;
	}
//	cout << cur ;
	for(i=0;i<ind;i++){
		cout << rev[i];
	}
	return line;
}*/

void reverse(string &s,int i,int j){
	char c;
	while(i<j){
		c=s[i];
		s[i]=s[j];
		s[j]=c;
		i++;
		j--;
	}
}
string rev_words_line(string str){
	//cout << "IN FUNCTION" ;
	int i,j,n;
	j=0;
	//in order to reverse last word
	str.insert(str.end(),' ');
	cout << "string" << str;
	cout << "\nlen=" << str.length();
	n=str.length();
	for(i=0;i<n;i++){
		if(str[i]==' '){
			reverse(str,j,i-1);
			j=i+1;
	//		cout << "j=" << j ;
		}
	}
	//str.pop_back();
	reverse(str,0,n-1);
	return str;
}
int main(){
	string line,rev;
	cout << "Enter The Line...." ;
	getline(cin,line) ;
//	cout << line;
//	cout << line.length();
//	cout << "\n" << rev_line(line);
	rev=rev_words_line(line);
	cout << "\n" << rev ;
	return 0;
}