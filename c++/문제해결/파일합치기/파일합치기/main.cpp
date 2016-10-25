#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int files[501];
vector<int> total_price;
int min_price;

void recursive(int *files, int length, int total) {

	if(length==2) {
		total += files[0]+files[1];
		if(total_price.size()==0) {
			total_price.push_back(total);
			min_price=total;
		}
		else {
			if(total_price.at(0) > total) {
				total_price.clear();
				total_price.push_back(total);
				min_price=total;
			}
		}
		return;
	}

	int count=length;
	int max_loop=1;

	if(length%2 == 0) {

		int *result;
		result = new int[length/2];
		bool *check;
		check = new bool[length/2];
		
		while(count) {
			max_loop = max_loop*(count*(count-1)/2);
			count = count-2;
		}
		int init, count, cur_total;
		for(int z=0; z<max_loop; z++) {

			count=0;
			cur_total=total;
			for(init=0; init<length/2; init++) result[init]=0;
			for(init=0; init<length; init++) check[init]=true;
			
			while(count!=length/2) {
				for(int i=0; i<length; i++) {
					for(int j=0; j<length; j++) {
						if(i != j && (check[i]==true && check[j]==true)) {
							check[i]=false;
							check[j]=false;
							result[count] = files[i] + files[j];
							cur_total += files[i] + files[j];
							count++;
							break;
						}
					}
				
				}
			}
			recursive(result, length/2, cur_total);
		}
	} else {

		int *result;
		result = new int[(length+1)/2];
		bool *check;
		check = new bool[(length+1)/2];

		for(int t=0; t<length; t++) {

			count=length-1;
			while(count) {
				max_loop = (max_loop*(count*(count-1)/2));
				count = count-2;
			}
			int init, count_2, cur_total;
			for(int z=0; z<max_loop; z++) {

				count_2=1;
				cur_total=total;
				for(init=0; init<(length+1)/2; init++) result[init]=0;
				for(init=0; init<length; init++) check[init]=true;
				result[0]=files[t];
				check[t]=false;
			
				while(count_2!=(length+1)/2) {
					for(int i=0; i<length; i++) {
						for(int j=0; j<length; j++) {
							if(i != j && (check[i]==true && check[j]==true)) {
								check[i]=false;
								check[j]=false;
								result[count_2] = files[i] + files[j];
								cur_total += files[i] + files[j];
								count_2++;
								break;
							}
						}
				
					}
				}
				if(min_price!=0) {
					if(cur_total > min_price) return;
				}
				recursive(result, (length+1)/2, cur_total);
			}
		}

	}
}

int main() {

	int i,j;
	int cases;
	int file_count;

	cin>>cases;

	for(j=0; j<cases; j++) {
		min_price=0;
		memset(files, 0, 501*sizeof(int));
		total_price.clear();
		
		cin>>file_count;
		for(i=0; i<file_count; i++) cin>>files[i];

		recursive(files, file_count, 0);

		cout<<min_price<<endl;
	}


	return 0;
}