#include <iostream>
#include <string>

//using namespace std;

int row, column;
int word_cnt;
char find[20][51];
char matrix[51][51];
int Di[8]={-1,-1,-1,0,1,1,1,0};
int Dj[8]={-1,0,1,1,1,0,-1,-1};

int Match(int c, int i, int j) {
	int f=1;
	int d_count=0;
	for(int d=0; d<8; d++) {
		f=1, d_count=0;
		while(i+(find[c][0]-1)*Di[d]>=0 && i+(find[c][0]-1)*Di[d]<=row && j+(find[c][0]-1)*Dj[d]>=0 && j+(find[c][0]-1)*Dj[d]<=column && f<=find[c][0]) {
			if(matrix[i+d_count*Di[d]][j+d_count*Dj[d]] == find[c][f]) {
				if(f==find[c][0]) {
					return 1;
				}
				d_count++;
				f++;
			} else break;
		}
	}
	return 0;
}

int main() {

	int case_cnt,i,j,c;
	char input;
	std::cin>>case_cnt;
	while(case_cnt--) {

		std::cin>>row>>column;
		for(i=0; i<row; i++) {
			for(j=0; j<column; j++) {
				std::cin>>input;
				if(input < 'a') matrix[i][j]=input+32;
				else matrix[i][j]=input;
			}
		}
		std::cin>>word_cnt;
		std::string input_word;
		for(i=0; i<word_cnt; i++) {
			std::cin>>input_word;
			find[i][0]=input_word.size();
			for(j=0; j<input_word.size(); j++) {
				if(input_word[j] < 'a') find[i][j+1]=input_word[j]+32;
				else find[i][j+1]=input_word[j];
			}
		}
		for(c=0; c<word_cnt; c++) {
			for(i=0; i<row; i++) {
				for(j=0; j<column; j++) {
					if(Match(c,i,j)) {
						std::cout<<i+1<<" "<<j+1<<std::endl;
						j=column;
					}
				}
				if(j==column+1) break;
			}
		}
		if(case_cnt!=0) {
			std::cout<<"\n";
		}
	}

	return 0;
}