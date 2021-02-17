#include<iostream>
#include<unordered_map>

#define max 100 
using namespace std;

int mat[10][10];
int stack[max];
int top=-1;

void push(int data){
	if(top==max){
		cout << "stack is Full" ;
	}
	else{
		stack[++top]=data;
		cout << stack[top];
	}
}

int pop(){
	if(top==-1){
		cout << "stack is empty" ;
	}
	else{
		return stack[top--];
	}
	return -1;
}
void spiral(int row,int col){
	int rowstart=0,colstart=0,rowend=row,colend=col,i;
	while(rowstart<rowend && colstart<colend){
		for(i=colstart;i<colend;i++){
			cout << mat[rowstart][i] << "\t";
			push(mat[rowstart][i]);
		}
		rowstart++;
		for(i=rowstart;i<rowend;i++){
			cout << mat[i][colend-1] << "\t";
			push(mat[i][colend-1]);
		}
		colend--;
		if(rowstart<rowend){
			for(i=colend-1;i>=colstart;i--){
				cout << mat[rowend-1][i] << "\t";
				push(mat[rowend-1][i]);
			}
			rowend--;
		}
		if(colstart<colend){
			for(i=rowend-1;i>=rowstart;i--){
				cout << mat[i][colstart] << "\t";
				push(mat[i][colstart]);
			}
			colstart++;
		}
	}
}

void antiSpiral(){
	//cout << stack[top];
	while(top!=-1){
		cout << pop() ;
	}
}

void zigzag(int row,int col){
	int even=0,odd=1,i;
	while(even<row || odd<row){
		for(i=0;i<col;i++){
			cout << mat[even][i];
		}
		cout << "\n" ;
		even=even+2;
		if(odd<row){
			for(i=col-1;i>=0;i--){
				cout << mat[odd][i];
			}
			odd=odd+2;
		}
		cout << "\n" ;
	}
}

void search(int row,int col,int target){
	int i=0,j=col-1;
	if(target<mat[0][0] || target>mat[row-1][col-1]){
		cout << "Not Found" ;
	}
	else{
		while(i<row && j>=0){
			if(mat[i][j]==target){
				cout << "Found" ;
				break;
			}
			else if(mat[i][j]>target){
				j--;
			}
			else{
				i++;
			}
		}
	}
}

void search_common(int row,int col){
	unordered_map<int,int> mp;
	int i,j;	
	for(j=0;j<col;j++){
		mp[mat[0][j]]=1;
	}
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(mp[mat[i][j]]==i){
				mp[mat[i][j]]=i+1;
				if(i==col-1){
					cout << mat[i][j] <<"\n" ;
				}
			}
		}
	}

}
int main(){
	int i,j,row,col;
	cout << "Enter Number Of rows And Columns....";
	cin >> row >> col;
	//input matrix
	for(i=0;i<row;i++){
		cout << "Enter Rows Elements...." ;
		for(j=0;j<col;j++){
			cin >> mat[i][j];
		}
	}
	//print matrix
	for(i=0;i<row;i++){
		cout << "\n" ;
		for(j=0;j<col;j++){
			cout << mat[i][j] << "\t";
		}
	}
	cout << "\n" ;
	spiral(row,col);
	cout << "\n" ;
	zigzag(row,col);
	cout << "\n" ;
	antiSpiral();
//	cout << "\n Enter Target Element...." ;
//	cin >> i;
//	search(row,col,i);
	cout << "\n" ;
	search_common(row,col);
	return 0;
}