#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct _Card {
	int pattern;
	int value;
};
typedef struct _Card Card;

Card setCard(char value, char pattern) {
	Card card;
	switch(pattern) {
	case 'S':
		card.pattern = 4;
		break;
	case 'C':
		card.pattern = 3;
		break;
	case 'D':
		card.pattern = 2;
		break;
	case 'H':
		card.pattern = 1;
		break;
	default:
		card.pattern = 1;
		break;
	}
	switch(value) {
	case 'A':
		card.value = 14;
		break;
	case 'K':
		card.value = 13;
		break;
	case 'Q':
		card.value = 12;
		break;
	case 'J':
		card.value = 11;
		break;
	case 'T':
		card.value = 10;
		break;
	case '9':
		card.value = 9;
		break;
	case '8':
		card.value = 8;
		break;
	case '7':
		card.value = 7;
		break;
	case '6':
		card.value = 6;
		break;
	case '5':
		card.value = 5;
		break;
	case '4':
		card.value = 4;
		break;
	case '3':
		card.value = 3;
		break;
	case '2':
		card.value = 2;
		break;
	default:
		card.value = 1;
		break;
	}
	return card;
}

long long int isStraightflush(vector<Card> set) {
	long long int score = 0;

	Card temp, temp2;
	temp = set.at(0);

	for(int i=1; i<set.size(); i++) {
		temp2 = set.at(i);
		if(temp.pattern != temp2.pattern) {
			return score;
		}
	}
	for(int i=1; i<set.size(); i++) {
		temp2 = set.at(i);
		if((temp.value-i) != temp2.value) {
			return 0;
		}
	}	
	score = 80000;
	score *= 1000000;
	score += temp.value;
	return score;
}
long long int isFourcard(vector<Card> set) {
	long long int score = 0;

	Card temp, temp2;
	
	int count=0;

	for(int i=0; i<set.size(); i++) {
		temp = set.at(i);
		for(int j=0; j<set.size(); j++) {
			temp2 = set.at(j);
			if((temp.value == temp2.value)) count++;
		}
		if(count==4) {
			score = 70000;
			score *= 1000000;
			score += temp.value;
			return score;
		}
		count=0;
	}
	return score;
}
long long int isFullhouse(vector<Card> set) {
	long long int score = 0;

	Card temp, temp2;
	
	int count=0;
	int three=0, two=0;

	for(int i=0; i<set.size(); i++) {
		temp = set.at(i);
		for(int j=0; j<set.size(); j++) {
			temp2 = set.at(j);
			if((temp.value == temp2.value)) count++;
		}
		if(count==3) {
			three = temp.value;
		}
		if(count==2) {
			two = temp.value;
		}
		count=0;
	}
	if(three && two) {
		score = 60000;
		score *= 1000000;
		score += three;
		return score;
	}
	return score;
}
long long int isFlush(vector<Card> set) {
	long long int score = 0;

	Card temp, temp2;
	temp = set.at(0);
	int count=0;

	for(int i=1; i<set.size(); i++) {
		temp2 = set.at(i);
		if(temp.pattern == temp2.pattern) count++;
	}
	if(count == 4) {
		score = 50000000000;

		temp = set.at(0);
		score += temp.value*100000000;
		temp = set.at(1);
		score += temp.value*1000000;
		temp = set.at(2);
		score += temp.value*10000;
		temp = set.at(3);
		score += temp.value*100;
		temp = set.at(4);
		score += temp.value*1;

		return score;
	}
	return score;
}
long long int isStraight(vector<Card> set) {
	long long int score = 0;

	Card temp, temp2;
	temp = set.at(0);
	for(int i=1; i<set.size(); i++) {
		temp2 = set.at(i);
		if((temp.value-i) != temp2.value) {
			return 0;
		}
	}
	score = 40000;
	score *= 1000000;
	score += temp.value;
	return score;
}
long long int isThree(vector<Card> set) {
	long long int score = 0;

	Card temp, temp2;
	
	int count=0;
	int three=0, two =0, one=0;

	for(int i=0; i<set.size(); i++) {
		temp = set.at(i);
		for(int j=0; j<set.size(); j++) {
			temp2 = set.at(j);
			if((temp.value == temp2.value)) count++;
		}
		if(count==3) {
			three = temp.value;
		}
		else if(!two) two = temp.value;
		else if(!one) one = temp.value;
		count=0;
		
	}
	if(three) {
		score = 30000;
		score *= 1000000;
		score += three*10000;
		score += two*100;
		score += one*1;

		return score;
	}
	return score;
}
long long int isTwopair(vector<Card> set) {
	long long int score = 0;

	Card temp, temp2;
	
	int count=0;
	int pair_count=0;
	int one_value=0, two_value=0, three_value=0;

	for(int i=0; i<set.size(); i++) {
		temp = set.at(i);
		for(int j=0; j<set.size(); j++) {
			temp2 = set.at(j);
			if((temp.value == temp2.value)) count++;
		}
		if(count==2) {
			pair_count++;
			if(pair_count==2) {
				one_value = temp.value;
			} else if (pair_count==4) {
				two_value = temp.value;
			}
		} else {
			three_value = temp.value;
		}
		count=0;
	}
	if(pair_count==4) {
		if(one_value < two_value) {
			int temp_value=two_value;
			two_value = one_value;
			one_value = temp_value;
		}
		score = 20000;
		score *= 1000000;
		score += one_value*10000;
		score += two_value*100;
		score += three_value;
		return score;
	}
	return score;
}
long long int isOnepair(vector<Card> set) {
	long long int score = 0;

	Card temp, temp2;
	
	int count=0;
	int pair_value=0;
	int one_value=0, two_value=0, three_value=0;

	for(int i=0; i<set.size(); i++) {
		temp = set.at(i);
		for(int j=0; j<set.size(); j++) {
			temp2 = set.at(j);
			if(temp.value == temp2.value) count++;
		}
		if(count == 2) {
			pair_value = temp.value;
		} else {
			if(!one_value) {
				one_value = temp.value;
			} else if(!two_value) {
				two_value = temp.value;
			} else if(!three_value) {
				three_value = temp.value;
			}
		}
		count=0;
	}
	if(pair_value) {
		score = 10000;
		score *= 1000000;
		score += pair_value*1000000;
		score += one_value*10000;
		score += two_value*100;
		score += three_value*1;

		return score;
	}
	return score;
}
long long int isHighcard(vector<Card> set) {

	long long int score = 0;

	Card temp;
	temp = set.at(0);
	score += temp.value*100000000;
	temp = set.at(1);
	score += temp.value*1000000;
	temp = set.at(2);
	score += temp.value*10000;
	temp = set.at(3);
	score += temp.value*100;
	temp = set.at(4);
	score += temp.value*1;

	return score;
}

int main() {
	long long int black_score=0;
	long long int white_score=0;

	int i,j;

	while(1)  {
		vector<Card> black;
		vector<Card> white;

		string buffer;
		getline(cin, buffer);
		if(buffer.empty()) break;

		stringstream ss(buffer);
		string strCard;
		for (i = 0; i < 5; ++i) {
			ss >> strCard;
			black.push_back(setCard(strCard[0], strCard[1]));
		}
		for (i = 0; i < 5; ++i) {
			ss >> strCard;
			white.push_back(setCard(strCard[0], strCard[1]));
		}

		Card temp, card1, card2;
		for(i=0; i < 5; i++){
			
			for(j =i+1; j < 5; j++){
				card1 = black.at(i);
				card2 = black.at(j);
				if(card1.value < card2.value) {
					temp = black.at(i);
					black.at(i) = black.at(j);
					black.at(j) = temp;
				}
			}
		}
		for(i=0; i < 5; i++){
			
			for(j =i+1; j < 5; j++){
				card1 = white.at(i);
				card2 = white.at(j);
				if(card1.value < card2.value) {
					temp = white.at(i);
					white.at(i) = white.at(j);
					white.at(j) = temp;
				}
			}
		}

		if(black_score = isStraightflush(black)) {}
		else if(black_score = isFourcard(black)) {}
		else if(black_score = isFullhouse(black)) {}
		else if(black_score = isFlush(black)) {}
		else if(black_score = isStraight(black)) {}
		else if(black_score = isThree(black)) {}
		else if(black_score = isTwopair(black)) {}
		else if(black_score = isOnepair(black)) {}
		else if (black_score = isHighcard(black)) {}

		if(white_score = isStraightflush(white)) {}
		else if(white_score = isFourcard(white)) {}
		else if(white_score = isFullhouse(white)) {}
		else if(white_score = isFlush(white)) {}
		else if(white_score = isStraight(white)) {}
		else if(white_score = isThree(white)) {}
		else if(white_score = isTwopair(white)) {}
		else if(white_score = isOnepair(white)) {}
		else if (white_score = isHighcard(white)) {}

		//cout<<black_score<<endl;
		//cout<<white_score<<endl;

		if(black_score>white_score) cout<<"Black wins.\n";
		else if(black_score<white_score) cout<<"White wins.\n";
		else if(black_score==white_score) cout<<"Tie.\n";


	}
	return 0;
}


