#include <iostream>
#include <list>

using namespace std;

int main() {

	int cases, input, jump, i;
	list<int> result;
	list<int>::iterator it;

	while(cin>>cases) {
		result.clear();
		
		for(i=1; i<=cases; i++) {
			cin>>jump;
			if(result.size()==0) result.push_back(1);
			else {
				it = result.end();
				while(jump) {
					it--;
					jump--;
				}
				result.insert(it, i);
			}
		}

		for(it=result.begin(); it!=result.end(); it++) {
			if(it != result.begin()) cout<<" ";
			cout<<*it;
		}
		cout<<endl;
	}

	return 0;
}