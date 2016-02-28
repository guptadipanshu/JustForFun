#include "List.h"
#include <iostream>
#include <map>
using namespace std;

void List:: insert(int data){
	if(head==NULL)
	 head=new Node(data);
	else{
	Node * temp=new Node(data);
	temp->next=head;
	head=temp;
}
}
void List::remove_dups(){
Node *temp=head;
map<int,bool> arr;
	while(temp!=NULL)
	{
		if(arr.find(temp->data)->second==0)
		{
			arr.insert(std::make_pair(temp->data,1));
			temp=temp->next;
		}
		else
		{
			Node * rep=temp->next;
			if(rep==NULL)
			{
				delete temp;
				temp=NULL;
			}
			else
			{
				temp->data=rep->data;
				temp->next=rep->next;
				delete rep;
				rep=NULL;
			}
			
		}
	}
}
void List::print(){
	Node* temp=head;
	while(temp!=NULL){
		cout<<" "<<temp->data;
		temp=temp->next;
	}
	cout<<"\n";
}

void List::reverse()
{
	if(head==NULL)
		return;
	Node * start=head;
	if(start->next==NULL)
		return;
	Node * curr=start->next;
	while(curr!=NULL){
		Node * temp=curr->next;
		curr->next=start;
		start=curr;
		curr=temp;
	}
	head->next=NULL;
	head=start;
}
