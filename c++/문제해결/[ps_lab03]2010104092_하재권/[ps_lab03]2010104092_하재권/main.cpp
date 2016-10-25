#include <iostream>
#include <string.h>
#include <vector>

//#define MAXLEN 51
//typedef char words[20][MAXLEN];

int case_cnt;
int row, column;
int word_cnt;
char find[20][51];
char matrix[51][51];

//using namespace std;

int matching(int current_row, int current_column, int current_word, int direction) {

	int words_length = strlen(find[current_word]);
	switch(direction) {
	case 0:
		if(current_row+1 - words_length >= 0) {
			//cout<<words_length<<endl;
			int i=0, success=1;
			while(i < words_length-1 && success) {
				i++;
				char upper=0, lower=0;
				if(find[current_word][i] < 'a') {
					upper = find[current_word][i];
					lower = find[current_word][i] + 32;
				} else {
					upper = find[current_word][i] - 32;
					lower = find[current_word][i];
				}
				if(matrix[current_row-i][current_column] != upper && matrix[current_row-i][current_column] != lower) {
					success=0;
				}
				//cout<<matrix[current_row-i][current_column]<<" "<<find[current_word][i]<<endl;
			}
			if(success) {
				std::cout<<current_row+1<<" "<<current_column+1<<"\n";
				return 1;
			}
		}
		break;
	case 1:
		if(current_row+1 - words_length >= 0 && column - current_column >= words_length) {
			//cout<<words_length<<endl;
			int i=0, success=1;
			while(i < words_length-1 && success) {
				i++;
				char upper=0, lower=0;
				if(find[current_word][i] < 'a') {
					upper = find[current_word][i];
					lower = find[current_word][i] + 32;
				} else {
					upper = find[current_word][i] - 32;
					lower = find[current_word][i];
				}
				if(matrix[current_row-i][current_column+i] != upper && matrix[current_row-i][current_column+i] != lower) {
					success=0;
				}
				//cout<<matrix[current_row-i][current_column]<<" "<<find[current_word][i]<<endl;
			}
			if(success) {
				std::cout<<current_row+1<<" "<<current_column+1<<"\n";
				return 1;
			}
		}
		break;
	case 2:
		if(column - current_column >= words_length) {
			//cout<<words_length<<endl;
			int i=0, success=1;
			while(i < words_length-1 && success) {
				i++;
				char upper=0, lower=0;
				if(find[current_word][i] < 'a') {
					upper = find[current_word][i];
					lower = find[current_word][i] + 32;
				} else {
					upper = find[current_word][i] - 32;
					lower = find[current_word][i];
				}
				if(matrix[current_row][current_column+i] != upper && matrix[current_row][current_column+i] != lower) {
					success=0;
				}
				//cout<<matrix[current_row-i][current_column]<<" "<<find[current_word][i]<<endl;
			}
			if(success) {
				std::cout<<current_row+1<<" "<<current_column+1<<"\n";
				return 1;
			}
		}
		break;
	case 3:
		if(column - current_column >= words_length && row - current_row >= words_length) {
			//cout<<words_length<<endl;
			int i=0, success=1;
			while(i < words_length-1 && success) {
				i++;
				char upper=0, lower=0;
				if(find[current_word][i] < 'a') {
					upper = find[current_word][i];
					lower = find[current_word][i] + 32;
				} else {
					upper = find[current_word][i] - 32;
					lower = find[current_word][i];
				}
				if(matrix[current_row+i][current_column+i] != upper && matrix[current_row+i][current_column+i] != lower) {
					success=0;
				}
				//cout<<matrix[current_row-i][current_column]<<" "<<find[current_word][i]<<endl;
			}
			if(success) {
				std::cout<<current_row+1<<" "<<current_column+1<<"\n";
				return 1;
			}
		}
		break;
	case 4:
		if(row - current_row >= words_length) {
			//cout<<words_length<<endl;
			int i=0, success=1;
			while(i < words_length-1 && success) {
				i++;
				char upper=0, lower=0;
				if(find[current_word][i] < 'a') {
					upper = find[current_word][i];
					lower = find[current_word][i] + 32;
				} else {
					upper = find[current_word][i] - 32;
					lower = find[current_word][i];
				}
				if(matrix[current_row+i][current_column] != upper && matrix[current_row+i][current_column] != lower) {
					success=0;
				}
				//cout<<matrix[current_row-i][current_column]<<" "<<find[current_word][i]<<endl;
			}
			if(success) {
				std::cout<<current_row+1<<" "<<current_column+1<<"\n";
				return 1;
			}
		}
		break;
	case 5:
		if(row - current_row >= words_length && current_column+1 >= words_length) {
			//cout<<words_length<<endl;
			int i=0, success=1;
			while(i < words_length-1 && success) {
				i++;
				char upper=0, lower=0;
				if(find[current_word][i] < 'a') {
					upper = find[current_word][i];
					lower = find[current_word][i] + 32;
				} else {
					upper = find[current_word][i] - 32;
					lower = find[current_word][i];
				}
				if(matrix[current_row+i][current_column-i] != upper && matrix[current_row+i][current_column-i] != lower) {
					success=0;
				}
				//cout<<matrix[current_row-i][current_column]<<" "<<find[current_word][i]<<endl;
			}
			if(success) {
				std::cout<<current_row+1<<" "<<current_column+1<<"\n";
				return 1;
			}
		}
		break;
	case 6:
		if(current_column+1 >= words_length) {
			//cout<<words_length<<endl;
			int i=0, success=1;
			while(i < words_length-1 && success) {
				i++;
				char upper=0, lower=0;
				if(find[current_word][i] < 'a') {
					upper = find[current_word][i];
					lower = find[current_word][i] + 32;
				} else {
					upper = find[current_word][i] - 32;
					lower = find[current_word][i];
				}
				if(matrix[current_row][current_column-i] != upper && matrix[current_row][current_column-i] != lower) {
					success=0;
				}
				//cout<<matrix[current_row-i][current_column]<<" "<<find[current_word][i]<<endl;
			}
			if(success) {
				std::cout<<current_row+1<<" "<<current_column+1<<"\n";
				return 1;
			}
		}
		break;
	case 7:
		if(current_column+1 >= words_length && current_row+1 - words_length >= 0) {
			//cout<<words_length<<endl;
			int i=0, success=1;
			while(i < words_length-1 && success) {
				i++;
				char upper=0, lower=0;
				if(find[current_word][i] < 'a') {
					upper = find[current_word][i];
					lower = find[current_word][i] + 32;
				} else {
					upper = find[current_word][i] - 32;
					lower = find[current_word][i];
				}
				if(matrix[current_row-i][current_column-i] != upper && matrix[current_row-i][current_column-i] != lower) {
					success=0;
				}
				//cout<<matrix[current_row-i][current_column]<<" "<<find[current_word][i]<<endl;
			}
			if(success) {
				std::cout<<current_row+1<<" "<<current_column+1<<"\n";
				return 1;
			}
		}
		break;
	}

	return 0;
}

int main() {

	std::cin>>case_cnt;
	while(case_cnt--) {

		std::cin>>row>>column;
		for(int i=0; i<row; i++) 
			std::cin>>matrix[i];

		std::cin>>word_cnt;
		for(int i=0; i<word_cnt; i++) {
			std::cin>>find[i];
		}

		for(int w=0; w<word_cnt; w++) {
			for(int i=0; i<row; i++) {
				for(int j=0; j<column; j++) {
					char upper=0, lower=0;
					if(find[w][0] < 'a') {
						upper = find[w][0];
						lower = find[w][0] + 32;
					} else {
						upper = find[w][0] - 32;
						lower = find[w][0];
					}
					if(matrix[i][j] == upper || matrix[i][j] == lower) {
						for(int d=0; d<8; d++) {
							if(matching(i,j,w,d)) {
								i = 100;
								j = 100;
								break;
							}
						}
					}
				}
			}
		}
		if(case_cnt!=0) {
			std::cout<<"\n";
		}
	}
	return 0;
}