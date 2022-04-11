#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; // n denotes the number of strings to be encoded
	cout<<"Enter the number of strings to be encoded: ";
	cin>>n;
	
	ofstream ptr; // ptr denotes the file pointer for storing input and output
	ptr.open("Huffman.txt",ios::app);
	ptr<<"Number of strings to be encoded: "<<n<<"\n";
	
	vector<pair<string,float> > Probabilities; // Probabilities denote vector to store strings with their respective probabilities
	float entropy=0;
	set<pair<float,vector<string> > > s; // s acts as node of the tree
	
	ptr<<"Strings with their probablities: \n";
	for(int i=0;i<n;i++) // for loop for taking input and storing it
	{
		float prob; // prob denotes probability of string
		string str; // str denotes string
		cout<<"Enter string "<<i+1<<": ";
		cin>>str;
		cout<<"Enter the probability of string "<<i+1<<": ";
		cin>>prob;
		ptr<<str<<" "<<prob<<"\n";
		Probabilities.push_back(make_pair(str,prob));
		vector<string> v;
		v.push_back(str);
		s.insert(make_pair(prob,v));
		entropy-=prob*(log2(prob)); // calculation of entropy	
	}
	
	map<string, string> m; // m stores strings and their corresponding Huffman codes
	set<pair<float,vector<string> > >::iterator it; // Set to get two nodes with lowest probability
	
	for(int i=1;i<n;i++)  // for loop for combining 2 nodes with least probabilities
	{
		it=s.begin();
		float f1=(*it).first; 
		vector<string> v2,v1;
		v1=(*it).second;
		s.erase(*it);
		it=s.begin();
		f1+=(*it).first;
		v2=(*it).second;
		s.erase(*it);
		for(int i=0;i<v1.size();i++)
		{	
			m[v1[i]]='0'+m[v1[i]];
		}
		for(int i=0;i<v2.size();i++)
		{
			v1.push_back(v2[i]);
			m[v2[i]]='1'+m[v2[i]];
		}
		s.insert(make_pair(f1,v1));
	}
	
	float avglen=0; // avglen denotes average length of Huffman codes
	cout<<"\nOutput:\n";
	ptr<<"\nOutput:\n";
	for(int i=0;i<n;i++) // for loop to print strings and corresponding Huffman codes
	{
		cout<<Probabilities[i].first<<" "<<m[Probabilities[i].first]<<endl;
		ptr<<Probabilities[i].first<<" "<<m[Probabilities[i].first]<<"\n";
		avglen+=(Probabilities[i].second* m[Probabilities[i].first].length()); // To calculate average length of Huffman codes
	}
	
	cout<<"Entropy: "<<entropy<<endl; // printing entropy
	ptr<<"Entropy: "<<entropy<<"\n";
	cout<<"Average Length: "<<avglen<<endl; // printing average length
	ptr<<"Average Length: "<<avglen<<"\n";
	cout<<"Efficiency="<<entropy/avglen<<endl; // printing efficiency
	ptr<<"Efficiency="<<entropy/avglen<<"\n";
	ptr.close();
	return 0;
}
