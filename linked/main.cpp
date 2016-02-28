#include <iostream>
#include <string>
using namespace std;
#include "List.h"
int main(){
/**
 * use g++ *.cpp to compile the files.
 */
		List *h=new List();
		h->insert(3);
		h->insert(2);
		h->insert(5);
		h->insert(1);
		h->insert(2);
		h->insert(4);
		h->insert(3);
		h->insert(7);
		h->print();
		h->reverse();
		h->print();
		h->remove_dups();
		h->print();
		return 0;
	
}
