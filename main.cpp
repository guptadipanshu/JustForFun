#include <iostream>
using namespace std;
#include "Trees.h"

int main(){
	int choice=1;
	Tree *t = new Tree();
	t->insert(4);
	t->insert(2);
	t->insert(1);
	t->insert(3);
	t->insert(6);
	t->insert(5);
	t->insert(7);
	t->levelOrder();
	
	t->LCA(3,6);
	t->LCA(2,1);
	t->LCA(7,5);
	t->LCA(7,3);
	
	cout<<"Welcome choose an option\n1.Insert\n2.Inorder\n3.Update\n4.Delete\n0.Exit\n";
	while(choice!=0){
		cout<<"select\n";
		cin>>choice;
		switch(choice)
		{
		case 1 :{ 
					int data;
					cout<<"Enter\n";
					cin>>data;
					t->insert(data);
				}
				break;
		case 2: {
					cout<<"inorder\t";
					t->inorder();
				}
				break;
		case 3: {
					int data;
					cout<<"Enter\n";
					cin>>data;
					t->update(data);
					break;
				}
		case 4: {
					int data;
					cout<<"Enter\n";
					cin>>data;
					t->deleteNode(data);
					break;
				}
		default: cout<<"unkown";
		}
	}
}
