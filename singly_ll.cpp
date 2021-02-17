#include<iostream>
#include<unordered_set>
#include<stack>

using namespace std;


class Node{
	public:
	int data;
	Node *next;
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
	Node * create(int n,Node *head);

//Reverse
	Node * reverse_itr(Node *head);
	void reverse_rec(Node *curr,Node *prev,Node **head);
	Node * reverse_rec(Node *head);

//Reverse In Group Of k;
	Node * reverse_in_grp(Node *head,int k);

//Detect Loop
	int isLoop(Node *head);

//Remove Duplicates
	void removeDuplicateSorted(Node *head);
	void removeDuplicateUnSorted(Node *head);
	Node * moveLastToFront(Node *head);

//Find Mid Of LL
	int findMid(Node *head); 
	int findMidUsingPtr(Node *head);
	int findMidUsingMid(Node *head);

//Palindrome Linked List

	int isPalUsingSt(Node *head);
	int isPalUsingRev(Node *head);
	int isPalUsingHalfRev(Node *head);

//Delete Nodes Having Greater Vale Right Side
	
	void dltRightNode(Node *head);
	void dltGrtRight(Node *head);

//Display
	void display(Node *head);
};

Node * Node::create(int n,Node *head){
	int i,data;
	Node *temp,*current;
	for(i=0;i<n;i++){
		cout << "Enter Node Data..." ;
		cin >> data;
		temp=new Node(data);
		if(head==NULL){
			head=temp;
			current=temp;
		}
		else{
			while(current->next!=NULL){
				current=current->next;
			}
			current->next=temp;
			current=temp;
		}
	}
	return head;
}

Node * Node::reverse_itr(Node *head){
	Node *temp,*temp1,*curr;
	temp=head;
	temp1=head->next;
	head->next=NULL;
	while(temp1!=NULL){
		curr=temp1->next;
		temp1->next=temp;
		temp=temp1;
		temp1=curr;
	}
	return temp;
}

void Node::reverse_rec(Node *curr,Node *prev,Node **head){
	if(curr->next==NULL){
		*head=curr;
		curr->next=prev;
		return ;
	}
	Node *next=curr->next;
	curr->next=prev;
	reverse_rec(next,curr,head);
}


Node * Node::reverse_rec(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node *rest=reverse_rec(head->next);
	head->next->next=head;
	head->next=NULL;
	return rest;
}

Node * Node::reverse_in_grp(Node *head,int k){
	Node *curr=head,*next=NULL,*prev=NULL;
	int count=0;
	while(curr!=NULL && count<k){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	if(next!=NULL){
		head->next=reverse_in_grp(next,k);
	}
	return prev;
		
}


int isLoop(Node *head){
	Node *temp=head,*temp1=head;
	//cout << temp->data << temp1->data ;
	while(temp1 && temp && temp1->next){
		temp=temp->next;
		temp1=temp1->next->next;
		if(temp==temp1){
			return 1;
			break;
		}
		//cout << temp->data << temp1->data ;
	}
	return 0;
}

void Node::removeDuplicateSorted(Node *head){
	Node *curr=head,*temp;
	while(curr->next!=NULL){
		if(curr->data==curr->next->data){
			temp=curr->next->next;
			free(curr->next);
			curr->next=temp;
		}
		else{
			curr=curr->next;
		}
	}
}

void Node::removeDuplicateUnSorted(Node *head){
	Node *curr=head,*next;
	unordered_set<int> h;
	h.insert(curr->data);
	while(curr->next!=NULL){
		if(h.find(curr->next->data)!=h.end()){
			next=curr->next->next;
			free(curr->next);
			curr->next=next;
		}
		else{
			h.insert(curr->next->data);
			curr=curr->next;
		}
	}
}

Node * Node::moveLastToFront(Node *head){
	Node *curr=head,*newhead;
	while(curr->next->next!=NULL){
		curr=curr->next;
	}
	newhead=curr->next;
	curr->next=NULL;
	newhead->next=head;
	return newhead;

}

int Node::findMid(Node *head){
	int count=0,i;
	Node *temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	temp=head;
	i=0;
	while(temp && i<(count/2)){
		temp=temp->next;
		i++;
	}
	return temp->data;
}

int Node::findMidUsingPtr(Node *head){
	Node *slow=head,*fast=head;
	while(fast && fast->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow->data;
}

int Node::findMidUsingMid(Node *head){
	Node *mid=head;
	int count=1;
	while(head){
		count++;
		if(count%2!=0){
			mid=mid->next;
		}
		head=head->next;
	}
	return mid->data;
}

int Node::isPalUsingSt(Node *head){
	Node *temp=head;
	stack<int> s;
	int cnt=0,i=0;
	while(temp){
		cnt++;
		s.push(temp->data);
		temp=temp->next;
	}
	temp=head;
	while(temp && i<(cnt/2)){
		if(temp->data!=s.top()){
			return 0;
		}
		i++;
		temp=temp->next;
		s.pop();
	}
	return 1;
}

void Node::dltRightNode(Node *head){
	Node *curr,*temp,*next;
	for(curr=head;curr!=NULL;){
		for(temp=curr->next;temp->next!=NULL;){
			if(temp->data>curr->data){
				//next=temp->next;
				free(curr);
				//temp=next;
				curr=temp;
			}
			temp=temp->next;
		}

	}	
}

void Node::dltGrtRight(Node *head){
	Node *curr=head,*temp;
	while(curr && curr->next){
		if(curr->data<curr->next->data){
			curr->data=curr->next->data;
			curr->next=curr->next->next;
		}
		else{
			curr=curr->next;
		}
	}
}

void Node::display(Node *head){
	Node *temp=head;
	while(temp!=NULL){
		cout << temp->data << "\t";
		temp=temp->next;
	}
}

int main(){
	Node *head=NULL;
	int n;
	cout << "ENter Number Of Nodes...." ;
	cin >> n;
	head=head->create(n,head);
	head->display(head);
	cout << "\n" ;
/*	head=head->reverse_itr(head);
	head->display(head);
	cout << "\n";
	head->reverse_rec(head,NULL,&head);
	head->display(head);
	cout << "\n";
	cout << "Enter Grp Number....\n";
	cin >> n;
	head=head->reverse_in_grp(head,n);
	head->display(head);

	cout << "\n" ;
	head->removeDuplicateSorted(head);
	head->display(head);


	cout << "\n" ;
	head->removeDuplicateUnSorted(head);
	head->display(head);


	cout << "\n" ;
	head=head->moveLastToFront(head);
	head->display(head);


	cout << isSameNode(head);
	if(isLoop(head)){
		cout << "Loop Is Present...\n" ;
	}
	else{
		cout << "Loop Is Not Present...\n" ;
	
	}

	cout << "\n Using Count" << head->findMid(head);
	cout << "\n Using Ptrs" << head->findMidUsingPtr(head);
	cout << "\n Using Mid" << head->findMidUsingMid(head);

	if(head->isPalUsingSt(head)){
		cout << "\nString Is Palindrome...";
	}
	else{
		cout << "\nString Is Not Palindrome...";	
	}*/

	head->dltRightNode(head);
	head->display(head);
	return 0;
}