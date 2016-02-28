#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void merge_sort(vector<int> &arr);
void merge_arr(vector<int> &arr,int start,int last,int mid,vector<int> &b);
void merge(vector<int> &arr,int start,int last,vector<int> &b)
{
	int mid=(start+last)/2;
	if(start<last)
	{
		merge(arr,start,mid,b);
		merge(arr,mid+1,last,b);
		merge_arr(arr,start,last,mid,b);
	}
	
}
void merge_arr(vector<int> &arr,int start,int last,int mid,vector<int> &b)
{
	int left_start=start;
	int right_start=mid+1;
	int left_end=mid;
	int right_end=last;
	int index=start;
	/**
	 * First compare and merge upto equal lenghts
	 */
	while(left_start<=left_end && right_start<=right_end)
	{
			if(arr[left_start]>arr[right_start])
			{
				b[index]=arr[right_start];
				right_start++;
			}
			else
			{
				b[index]=arr[left_start];
				left_start++;
			}
			index++;
	}
	//merge the remaining
	while(right_start<=right_end)
	{
		b[index]=arr[right_start];
		index++;
		right_start++;
	}
	//merge the remaining
	while(left_start<=left_end)
	{
		b[index]=arr[left_start];
		index++;
		left_start++;
	}
	//copy for that level else in next iteration changes are lost
	for(int i=0;i<=index;i++)
	{
		arr[right_end]=b[right_end];
		right_end=right_end-1;
	}
}

void binary_search(vector<int> arr,int start,int last,int data){
	int mid=(start+last)/2;
	if(start<=last){
		if(arr[mid]==data)
		{
			cout<<"found at"<<mid<<" "<<data<<endl;
		}
		else if(arr[mid]>data)
		{
			binary_search(arr,start,mid-1,data);
		}
		else
			binary_search(arr,mid+1,last,data);
	}
}
int partition(vector<int> &arr,int start,int last){
	int pivot=arr[last];
	int j=start;
	for(int i=start;i<last;i++)
	{
		//move all elements smaller than pivot to left of pivot
		if(arr[i]<=arr[pivot]){
			//swap the last smallest element with the current element
			// some swaps are on the same index.
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
			j=j+1;
		}
	}
	//now pivot is the smallest element so swap it also
	int temp=arr[j];
	arr[j]=arr[last];
	arr[last]=temp;
	return j;
}
void quick_sort(vector<int> &arr,int start,int last){
	if(start<last){
		int p=partition(arr,start,last);
		quick_sort(arr,start,p-1);
		quick_sort(arr,p+1,last);
	}
}

int main(){
	string line ="6 5 7 10 2 1 4 12";
	cout<<"Enter a numbers\n";
	//std::getline(cin, line);
	std::istringstream iss(line);
	string token;
	vector<int>arr;
	int size=0;
	
	while (std::getline(iss, token, ' '))
	{
		arr.push_back(stoi(token));
		cout << arr[size] << std::endl;
		size++;
	}
	//merge_sort(arr);
	quick_sort(arr,0,arr.size()-1);
	cout<<"\n";
	for(vector<int>::iterator it=arr.begin();it!=arr.end();it++)
	{
		cout<<*it<<" ";
	}
	int data;
	cout<<"\nelement to search\n";
	cin>>data;
	binary_search(arr,0,arr.size()-1,data);
	return 0;
}
void merge_sort(vector<int> &arr)
{
	cout<<"hello\n";
	vector <int> b(arr.size());
	merge(arr,0,arr.size()-1,b);
}

