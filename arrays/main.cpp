#include <iostream>
using namespace std;
void print_arr(int a[][100],int row,int col)
{
	for(int i =0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			cout<<a[i][j]<<" ";
			cout<<"\n";
	}
}

void rotate(int a[][100],int row,int col)
{
	
	for(int i =0;i<row/2;i++)
	{
		for(int j=0;j<col/2;j++)
		{
			int temp=a[i][j];
			a[i][j]=a[j][col-i-1];
			a[j][col-i-1]=a[row-i-1][col-j-1];
			a[row-i-1][col-j-1]=a[row-j-1][i];
			a[row-j-1][i]=temp;
		}
			
	}
}
int main()
{
	int row,col;
	cout<<"Enter size";
	cin>>row>>col;
	int k=10;
	int a[row][100];
	for(int i =0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			a[i][j]=k++;
	}
	 print_arr(a,row,col);
	 rotate(a,row,col);
	 cout<<"\n";
	 print_arr(a,row,col);
}
