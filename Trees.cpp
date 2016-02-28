#include "Trees.h"

#include <iostream>
#include <stack>
#include <queue>
#include <map>
using namespace std;

void Tree::insert(int data){
	insert(data,root);
}
void Tree::inorder(){
	inorder(root);
	inorder_iterative(root);
	postorder_iterative(root);
}

void Tree::update(int data){
	cout<<"update "<<update(data,root);
}

void Tree::deleteNode(int data){
	deleteNode(data,root);
}

void Tree::insert(int data,Node* & croot){
	if(croot==NULL){
		cout<<"inserting\n";
		croot = new Node(data);
		return;
	}
	if(data<croot->elem){
		cout<<"insert left child "<<data<<" "<<croot->elem<<"\n";
		insert(data,croot->left);
	}
	else{
		cout<<"insert right child "<<data<<" "<<croot->elem<<"\n";
		insert(data,croot->right);
	}
}

void Tree::inorder(Node* croot){
	if(croot==NULL){
		return;
	}
	inorder(croot->left);
	cout<<" "<<croot->elem;
	inorder(croot->right);
}

void Tree::inorder_iterative(Node *&croot){
	cout<<"\n";
	std::stack<Node*> stack_node;
	if(croot==NULL)
		return;
	Node * curr=root;
	stack_node.push(root);
	while(curr->left!=NULL){
			curr=curr->left;
			stack_node.push(curr);
		}
	while(!stack_node.empty()){
		curr=stack_node.top();
		stack_node.pop();
		cout<<" "<<curr->elem;
		if(curr->right!=NULL)
		{
			stack_node.push(curr->right);
			curr=curr->right;
			while(curr->left!=NULL){
				curr=curr->left;
				stack_node.push(curr);
			}
		}
			
	}
}

void Tree::postorder_iterative(Node *&croot){
	cout<<"postorder_iterative order\n";
	std::stack<Node*> stack_node;
	if(croot==NULL)
		return;
	stack_node.push(croot);
	Node * curr=croot;
	while(curr->left!=NULL){
		curr=curr->left;
		stack_node.push(curr);
	}
	while(!stack_node.empty())
	{
		curr=stack_node.top();
		if(curr->right!=NULL){
			stack_node.push(curr->right);
			curr=curr->right;
		}
		while(curr->left!=NULL)
		{
			curr=curr->left;
			stack_node.push(curr);
		}
		curr=stack_node.top();
		cout<<" "<<curr->elem;
		stack_node.pop();
	}
}
void Tree ::levelOrder()
{
	if(root==NULL)
		return;
	Node * curr=root;
	queue<Node*> temp;
	map<Node*,int> level_map;
	temp.push(root);
	int level=0;
	level_map.insert(make_pair(curr,level));
	while(temp.size()>0)
	{
		level++;
		curr=temp.front();
		temp.pop();
		cout<<curr->elem<<"at level "<<level_map[curr]<<"\n";
		if(curr->left!=NULL)
		{
			temp.push(curr->left);
			level_map.insert(make_pair(curr->left,level));
		}if(curr->right!=NULL)
		{
				temp.push(curr->right);
				level_map.insert(make_pair(curr->right,level));
		}		
	}
}
bool Tree::update(int data,Node* &croot){
	//Todo change this to delete the value and then call insert.
	
	bool val=false;
	if(croot==NULL)
		return false;

	else if(croot->elem==data){
		int new_val;
		cout<<"enter new\n";
		cin>>new_val;
		croot->elem=new_val;
		return true;
		
	} 
 	val=update(data,croot->left);
	val=update(data,croot->right);
	return val;
}

void Tree::deleteNode(int data,Node *& croot){
	if(croot==NULL)
		return;
	else if(croot->elem==data){
		deleteNodeHelper(croot);
		return;
	}
	deleteNode(data,croot->left);
	deleteNode(data,croot->right);
}

void Tree::deleteNodeHelper(Node *&croot){
	if(croot->left==NULL && croot->right==NULL)
	{
		cout<<"no child";
		delete croot;
		croot=NULL;
		return;
	}
	else if(croot->left!=NULL && croot->right!=NULL)
	{	
		cout<<"two child";
		deleteTwoChild(croot);
		return;
	}
	else
	{
		cout<<"one child";
		Node * temp=croot;
		if(croot->left!=NULL)
		{
			croot=croot->left;
		}else
		{
			croot=croot->right;
		}
		delete temp;
		temp=NULL;
		return;
	}
		
}

void Tree::deleteTwoChild(Node *&croot)
{
	Node * &iop=IOP(root->left);
	croot->elem=iop->elem;
	deleteNodeHelper(iop);
}
Tree::Node*& Tree::IOP(Node *&croot)
{
	if(croot->right==NULL){
		return croot;
	}
	return IOP(croot->right);	
}
void Tree::LCA(int n1,int n2)
{
	int out=LCA(n1,n2,root);
	cout<<"LCA "<<out<<"\n";
}
int Tree::LCA(int n1,int n2,Node * croot)
{
	if(croot==NULL)
		return 0;
	if(croot->elem==n1 || croot->elem==n2)
		return croot->elem;
	int left_lca=LCA(n1,n2,croot->left);
	int right_lca=LCA(n1,n2,croot->right);
	if (left_lca!=0 && right_lca!=0)
		return croot->elem;
	if(left_lca!=0)
		return left_lca;
	if(right_lca!=0)
		return right_lca;
	return 0;
}
