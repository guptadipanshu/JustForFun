#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

void print_combination(string line,int index)
{
	if(index==line.length())
	{
			cout<<line<<"\n";
			return;
	}
	for(int i=1;i<line.length();i++)
	{
		string temp_line=line;
		if(i!=index && i>index)
		{
			char temp=temp_line[i];
			temp_line[i]=temp_line[index];
			temp_line[index]=temp;
			cout<<temp_line<<"\n";
		}
		
	}
	print_combination(line,index+1);
}

void power_set(int number)
{
	vector< vector<int> > set;
	for(int i=1;i<=number;i++)
	{
		int size=set.size();
		for(int j=0;j<size;j++)
		{
			vector<int> temp=set[j];
			temp.push_back(i);
			set.push_back(temp);
		}
		vector<int> temp;
		temp.push_back(i);
		set.push_back(temp);
	}
	//print the power set
	for(int j=0;j<set.size();j++)
	{
		vector<int> temp=set[j];
		for(int i=0;i<temp.size();i++)
			cout<<temp[i]<<" ";
		cout<<"\n";
	}
}

void check_anagrams(string s1,string s2)
{
	 std::sort (s1.begin(), s1.end());
	 std::sort (s2.begin(),s2.end());
	 if (s1.compare(s2)==0)
		cout<<"anagrams\n";
	else
		cout<<"no anagrams\n";
		
}

void check_anagrams_map(string s1,string s2)
{
	 map<char,int> test_map;
	 for(int i =0;i<s1.length();i++)
	 {
		 int val=test_map.find(s1[i])->second;
		 val=val+1;
		 test_map.insert(std::make_pair(s1[i],val));
	}
	for(int i =0;i<s2.length();i++)
	 {
		 int val=test_map.find(s2[i])->second;
		 if(val==0){
		 cout<<"not anagram"<<"\n";
		 return;
		 }if(val>0)
			val=val-1;
		 test_map.insert(std::make_pair(s2[i],val));
		 
	}
	cout<<"anagram"<<"\n";
		
}
void reverse(string line)
{
	for(int i=0,j=line.length()-1;i<j;i++,j--)
	{
		char s=line[i];
		line[i]=line[j];
		line[j]=s;
	}
	cout<<line<<"\n";
}

int main(){
	string line;
	string line2 ,test;
	cout<<"Enter a line\n";
	//cin>>line2>>test;
	std::getline(std::cin,line);
	//cout<<line<<"\n";
	cout<<"Enter second line\n";
	std::getline(std::cin,line2);
	//cout<<line2<<"\n";
	check_anagrams(line,line2);
	check_anagrams_map(line,line2);
	reverse(line2);
	cout<<"combinations are:\n";
	
	for(int i=0;i<line.length();i++)
	{
		string temp=line;
		char s=temp[i];
		temp[i]=temp[0];
		temp[0]=s;
		print_combination(temp,1);
		cout<<"\n";
	}	
	
	string s3="abc";
	bool exists = line.find(s3) != std::string::npos;
	cout<<exists<<"\n";
	
	int number;
	cout<<"enter for power set";
	cin>>number;
	power_set(number);
	return 0;
	
}
