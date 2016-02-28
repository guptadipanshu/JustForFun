#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
class List{
	private:
	 struct Node{
		 Node * next;
		 int data;
		 Node (int elem):next(NULL),data(elem){}
	 };
	 Node * head;
	 
	 
	 public:
	 void insert(int data);
	 void print();
	 void reverse();
	 void remove_dups();
};
#endif
