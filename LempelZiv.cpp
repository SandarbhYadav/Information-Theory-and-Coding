#include<bits/stdc++.h>
using namespace std;

string ASCIItoBinary(char c) // Function to convert ASCII value to binary
{
	int a;
	a=c;
	string s="";
	for(int i=0;i<7;i++)
	{
		if(a%2)
		{
			s='1'+s;
		}
		
		else
		{
			s='0'+s;
		}
		a/=2;
	}
	return s;
}
string Binarize(int a) // Function to binarize position of prefix
{
	string s="";
	for(int i=0;i<6;i++)
	{
		if(a%2)
		{
			s='1'+s;
		}
		else
		{
			s='0'+s;
		}
		a/=2;
	}
	return s;
}

int main()
{
	ofstream ptr; // ptr denotes file pointer for storing input and output
	ptr.open("LempelZiv.txt",iostream::app);
	string s2; // s2 denotes string to store 2 sentences
	cout<<"Enter any two sentences in English: ";
	getline(cin,s2);
	ptr<<"Sentences: \n"<<s2<<"\n"<<"\nOutput: \n";

	string s1="";
	int l=s2.length();
	for(int i=0;i<l;i++) // for loop converts sentences into binary form
	{
		s1+=ASCIItoBinary(s2[i]);
	}
	map<string,int> m;// To store mapping of prefix and its position
	set<string> s; // To check whether the sequence has already been encountered or not
	l=s1.length(); // Actual length in ASCII Binary to transfer the bits
	string q="",w;
	int p=0,l1=0; // p denotes the number of different phrase encountered till now and l1 stores the length of compressed string
	
	cout<<"\nOutput:\nBefore LempelZiv: \n"<<s1<<endl<<"\nAfter Lempel Ziv: \n";
	ptr<<"Before LempelZiv: \n"<<s1<<endl<<"\nAfter LempelZiv:\n";
	
	for(int i=0;i<l;)
	{
		if(q==""||s.find(q)!=s.end()) // If phrase has already been encountered
		{
			w=q;
			q+=s1[i];
			i++;
		}
		else //If we see a new phrase
		{
			p++;
			cout<<Binarize(m[w])<<q[w.length()];
			ptr<<Binarize(m[w])<<q[w.length()];
			m[q]=p;
			s.insert(q);
			q="";
			l1+=7;
		}
	}
	
	if(q!=""&&s.find(q)!=s.end()) // To print the last phrase
	{
		cout<<Binarize(m[q])<<"\n";
		l1+=6;
		ptr<<Binarize(m[q])<<"\n";
	}
	
	float inilen=l; // inilen denotes initial length
	float finlen=l1; // finlen denotes final length
	cout<<endl<<"Length before LempelZiv encoding: "<<inilen;
	ptr<<endl<<"Length before LempelZiv encoding: "<<inilen;
	cout<<endl<<"Length after LempelZiv encoding: "<<finlen;
	ptr<<endl<<"Length after LempelZiv encoding: "<<finlen;
	cout<<endl<<"Compression Power: "<<inilen/finlen;
	ptr<<endl<<"Compression Power: "<<inilen/finlen<<"\n\n\n\n";
}
