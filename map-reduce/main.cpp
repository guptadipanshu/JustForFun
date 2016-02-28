//http://www.gutenberg.org/cache/epub/28885/pg28885.txt
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <fstream>
using namespace std;
void print_out(vector<string> &word_list,int key,ofstream & outfile)
{
	for(int i=0;i<word_list.size();i++)
	{
		outfile<<key<<" "<<word_list[i]<<"\n";
		cout<<key<<" "<<word_list[i]<<"\n";
	}
}
int main()
{
	string word;
	map<string,int> frequency;
	ifstream file_ptr("Alice.txt");
	//add word to map key= word value=count
	while(file_ptr>>word)
	{
		
		if(frequency[word]==0){
			frequency[word]=1;
		}
		else
		{
			int val=frequency[word];
			val+=1;
			frequency[word]=val;
		}
	}
	
	//remap to key=count value=word
	map<int,vector<string> > final_map; 
	map<string,int>::iterator it;
	for(it=frequency.begin();it!=frequency.end();it++)
	{
		//cout<<it->first<<it->second<<"\n";
		vector<string> words=final_map[it->second];
		words.push_back(it->first);
		final_map[it->second]=words;
	}
	
	//print the output
	map<int,vector<string> >::iterator it_final;
	ofstream outfile;
	int key;
	outfile.open ("output.txt");
	for(it_final=final_map.end();it_final!=final_map.begin();it_final--)
	{
		key=it_final->first;
		print_out(final_map[it_final->first],key,outfile);
	}
	key=it_final->first;
	print_out(final_map[it_final->first],key,outfile);
	outfile.close();
return 0; 
}
