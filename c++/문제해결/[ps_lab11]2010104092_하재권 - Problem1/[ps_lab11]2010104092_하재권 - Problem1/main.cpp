
#include <iostream>

using namespace std;

#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 100

typedef struct {
	int cost;
	int parent;
} cell;
cell m[MAXLEN+1][MAXLEN+1];
char *ch1, *ch2;

int string_compare(char *s, char *t);
void reconstruct_path(char *s, char *t, int i, int j);
void row_init(int i);
void column_init(int i);
int match(char c, char d);
int indel(char c);
void goal_cell(char *s, char *t, int *i, int *j);
void insert_out(char *t, int j);
void delete_out(char *s, int i);
void match_out(char *s, char *t, int i, int j);

int main() {
	char *temp = new char[100];
	ch1 = new char[100];
	memset(ch1, 0, 100*sizeof(char));
	ch2 = new char[100];
	memset(ch2, 0, 100*sizeof(char));
	cin.getline(temp, 100);
	ch1[0]=' ';
	for(int i=0; i<strlen(temp); i++)
		ch1[i+1]=temp[i];

	cin.getline(temp, 100);
	ch2[0]=' ';
	for(int i=0; i<strlen(temp); i++)
		ch2[i+1]=temp[i];
	int cost = string_compare(ch1, ch2);
	cout<<"cost : "<<cost<<endl;
	cout<<"move : ";
	reconstruct_path(ch1,ch2,strlen(ch1), strlen(ch2));

	return 0;
}

int string_compare(char *s, char *t) {
	int i,j,k;
	int opt[3];	

	for(i=0; i<MAXLEN; i++) {
		row_init(i);
		column_init(i);
	}
	for(i=1; i<strlen(s); i++)
		for(j=1; j<strlen(t); j++) {
			opt[MATCH] = m[i-1][j-1].cost + match(s[i],t[j]);
			opt[INSERT] = m[i][j-1].cost + indel(t[j]);
			opt[DELETE] = m[i-1][j].cost + indel(s[i]);
			m[i][j].cost = opt[MATCH];
			m[i][j].parent = MATCH;
			for(k=INSERT; k<=DELETE; k++) {
				if(opt[k] < m[i][j].cost) {
					m[i][j].cost = opt[k];
					m[i][j].parent = k;
				}
			}
		}
	goal_cell(s,t,&i,&j);
	return (m[i][j].cost);
}
void reconstruct_path(char *s, char *t, int i, int j) {
	if(m[i][j].parent == -1) return;
	if(m[i][j].parent == MATCH) {
		reconstruct_path(s,t,i-1,j-1);
		match_out(s,t,i,j);
		return;
	}
	if(m[i][j].parent == INSERT) {
		reconstruct_path(s,t,i,j-1);
		insert_out(t,j);
		return;
	}
	if(m[i][j].parent == DELETE) {
		reconstruct_path(s,t,i-1,j);
		delete_out(s,i);
		return;
	}
}
void row_init(int i) {
	m[0][i].cost = i;
	if(i>0)
		m[0][i].parent = INSERT;
	else
		m[0][i].parent = -1;
}
void column_init(int i) {
	m[i][0].cost = i;
	if(i>0)
		m[i][0].parent = DELETE;
	else
		m[i][0].parent = -1;
}
int match(char c, char d) {
	if(c==d) return 0;
	else return 1;
}
int indel(char c) {
	return 1;
}

void goal_cell(char *s, char *t, int *i, int *j) {
	*i = strlen(s)-1;
	*j = strlen(t)-1;
}
void insert_out(char *t, int j) {
	cout<<"I";
}
void delete_out(char *s, int i) {
	cout<<"D";
}
void match_out(char *s, char *t, int i, int j) {
	if(s[i]==t[j]) cout<<"M";
	else cout<<"S";
}