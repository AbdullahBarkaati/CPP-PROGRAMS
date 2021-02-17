#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int count_words(string line){
	int cnt=0,i;
	line.insert(line.end(),' ');
	for(i=0;i<=line.size();i++){
		if(line[i]==' '){
			cnt++;
		}
	}
	return cnt;
}

void print_words_count(string line){
	unordered_map<string,int> mp;
	int i;
	line.insert(line.end(),' ');
	string word="";
	for(i=0;i<line.size();i++){
		if(line[i]==' '){
			if(mp.find(word)==mp.end()){
				mp.insert(make_pair(word,1));
				word="";
			}
			else{
				mp[word]++;
				word="";		
			}
		}
		else{
			word=word+line[i];
		}
	}
	for(auto i:mp){
		cout << i.first << " " << i.second ;
	}
}

int print_max_words(string line){
	unordered_map<string,int> mp;
	int i,max,cnt=0;
	line.insert(line.end(),' ');
	string word="";
	for(i=0;i<line.size();i++){
		if(line[i]==' '){
			if(mp.find(word)==mp.end()){
				mp.insert(make_pair(word,cnt));
				word="";
				cnt=0;
			}
			else{
				mp[word]=cnt;
				cnt=0;		
			}
		}
		else{
			word=word+line[i];
			cnt++;
		}
	}
	max=0;
	for(auto i:mp){
		if(max<i.second){
			max=i.second;
		}
	}
	return max;
}
int main(){
	string line;
	cout << "\n Enter Line...." ;
	getline(cin,line);
	cout << count_words(line);
	cout << "\n" ;
	print_words_count(line);
	cout << "\n" ;
	cout << print_max_words(line);	
	return 0;
}