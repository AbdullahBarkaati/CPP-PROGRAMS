#include<iostream>
#include<stack>

using namespace std;

int main(){
	stack<int> s;
	s.push(10);
	cout << s.top();
	return 0;
}