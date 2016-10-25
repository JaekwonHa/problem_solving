#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

void merge(vector<string>* file, int length) {

	vector<string> merge_file;

	for(int i=0; i<file->size(); i++) {
		for(int j=0; j<file->size(); j++) {
			if(i==j) break;
			if (file->at(i).length() + file->at(j).length() == length) {
				if(i<=j) merge_file.push_back(file->at(i)+file->at(j));
				else merge_file.push_back(file->at(j)+file->at(i));
			}
		}
	}
	int* result;
	result = new int[merge_file.size()];
	for(int i=0; i<merge_file.size(); i++)
		result[i]=0;
	int max_result=0;
	for(int i=0; i<merge_file.size(); i++) {
		for(int j=0; j<merge_file.size(); j++) {
			if(i==j) break;
			if(merge_file.at(i)==merge_file.at(j)) {
				result[i]++;
				if(max_result < result[i]) max_result=result[i];
			}
		}
	}
	cout<<merge_file.at(max_result)<<"\n";
}

int main() {

	int cases;
	vector<string>file;
	string line;

	cin>>cases;
	cin.ignore();  
	getline(cin, line);  

	while ((cases--)>0) {  
		int shortest = 10000;
		int longest = 0;
		file.clear();
		while (getline(cin, line),line.length()>0) {
			file.push_back(line);
			if(shortest > line.length()) shortest = line.length();
			else if(longest < line.length()) longest = line.length();
		}

        if (file.size()==2)
			cout<<(file[0]+file[1])<<endl;
		else
			merge(&file, shortest+longest);
		
		file.clear();

		if(cases>0)
			cout<<endl;
	}
	return 0;
}