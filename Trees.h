#ifndef TREES_H
#define TREES_H
#include <iostream>
using namespace std;
class Tree{
	private:
       struct Node
        {
            int elem;
            Node* left;
            Node* right;
            Node(const int & element):
                elem(element), left(NULL), right(NULL){ /* nothing */ }
        };
        Node * root;
	public :
			void insert(int data);
			void inorder();
			void update(int data);
			void deleteNode(int data);
			void levelOrder();
			void LCA(int n1,int n2);
			
	private:
		void insert(int data,Node * & croot);
		void inorder(Node *croot);
		bool update(int data,Node * &croot);
		void deleteNode(int data,Node *& croot);
		void deleteNodeHelper(Node *&croot);
		void deleteTwoChild(Node *&croot);
		Node *& IOP(Node *&croot);
		void inorder_iterative(Node *&croot);
		void postorder_iterative(Node *&croot);	
		int LCA(int n1,int n2,Node *root);
};
#endif
