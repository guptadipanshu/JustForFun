#include <iostream>
#include <stack>
using namespace std;
 void push_elem(int i , std::stack<int> &s1,std::stack<int> &s2)
{
	while(s2.size()!=0)
	{
		int top=s2.top();
		s2.pop();
		s1.push(top);
	}
	s1.push(i);
}

 void pop_elem(std::stack<int> &s1,std::stack<int> &s2)
{
	while(s1.size()!=0)
	{
		int top=s1.top();
		s1.pop();
		s2.push(top);
	}
	if(s2.size()==0)
	{
		cout<<"empty\n";
		return;
	}
	int n=s2.top();
	s2.pop();
	cout<<" "<<n<<"\n";
}
void push_sort(int data,std::stack<int> &s3)
{
	std::stack<int>temp;
	int top=data;
	while(s3.size()>0)
	{
		if(top>s3.top())
		{
			temp.push(s3.top());
			s3.pop();
		}
		else
			break;
	}
	s3.push(top);
	while(temp.size()>0)
	{
		s3.push(temp.top());
		temp.pop();
	}
}
void display_stack(std::stack<int> s3)
{
	while(s3.size()!=0)
	{
		cout<<" "<<s3.top();
		s3.pop();
	}
	cout<<endl;
}
int main(){
	std::stack<int> s1;
	std::stack<int> s2;
	for(int i=1;i<6;i++)
	{
		push_elem(i,s1,s2);
	}
	for(int i=1;i<3;i++)
	{
		pop_elem(s1,s2);
	}
	push_elem(7,s1,s2);
	push_elem(9,s1,s2);
	pop_elem(s1,s2);
	pop_elem(s1,s2);
	std::stack<int> s3;
	push_sort(8,s3);
	push_sort(5,s3);
	push_sort(11,s3);
	push_sort(12,s3);
	push_sort(4,s3);
	push_sort(7,s3);
	push_sort(2,s3);
	push_sort(13,s3);
	display_stack(s3);

return 0;

}
