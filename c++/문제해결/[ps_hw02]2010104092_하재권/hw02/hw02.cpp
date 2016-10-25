#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int input_cnt = 0;
char word[1000][17];
char sentence[81];

struct _Node {
	char key['z'+1];
	char inv['z'+1];
	int i;
};
typedef struct _Node node;

void copy(node *left, node *right) {
	for(int i='a'; i<='z'; i++) {
        left->key[i] = right->key[i];
        left->inv[i] = right->inv[i];
    }
	left->i = right->i;
}

std::stack<node> dic;

void matching() {
	
	int current_len = 0;
	char find[17];
	register int i=0,k=0;

	node newnode;
    memset(&newnode, 0, sizeof(node));

	dic.push(newnode);

	while(!dic.empty()) {

		node temp = dic.top();
        dic.pop();

		while(sentence[temp.i] == ' ')
            temp.i++;
		if(temp.i == strlen(sentence)) {
			for(i=0; i<strlen(sentence); i++) {
			if(sentence[i] == ' ') {
				cout<<" ";
			} else {
				char c = temp.key[sentence[i]];
				cout<<(char)c;
			}
			}
			cout<<"\n";
			return;
		}
		
		k=0;
		for(i=temp.i; (sentence[i] >= 'a' && sentence[i] <= 'z'); i++, k++) {
            find[k] = sentence[i];
        }
		find[k] = '\0';
		int find_len = strlen(find);
		for(int j=0; j<input_cnt; j++) {
			
			if(find_len == strlen(word[j])) {

				node temp2;
				copy(&temp2, &temp);

				bool success = true;
				for(k=0; k<find_len; k++) {
					if(temp2.key[find[k]] && temp2.key[find[k]] != word[j][k] || temp2.inv[word[j][k]] && temp2.inv[word[j][k]] != find[k]) {
						success = false;
						break;
					} else {
						temp2.key[find[k]] = word[j][k];
						temp2.inv[word[j][k]] = find[k];
					}
				}
				if(success) {
					temp2.i += find_len;
					dic.push(temp2);
					//break;
				}
			}
		}
	}
	for(int i=0; i<strlen(sentence); i++) {
		if(sentence[i] == ' ') {
			cout<<" ";
		} else {
			cout<<"*";
		}
	}
	cout<<"\n";
	return;
}

int main() {
    cin>>input_cnt;
    for(int i=0; i<input_cnt; i++) 
        cin>>word[i];
    cin.ignore(2147483647, '\n');

	while(cin.getline(sentence, sizeof(char) * 81)) {
		if(input_cnt > 0) matching();
		else {
			for(int i=0; i<strlen(sentence); i++) {
				if(sentence[i] == ' ') {
					cout<<" ";
				} else {
					cout<<"*";
				}
			}
			cout<<"\n";
		}
	}
	return 0;
}