#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct _Job {
	//int day;
	//int fine;
	int number;
	double ratio;
};
typedef struct _Job Job;

int main() {

	vector<Job> jobs;

	int cases;
	cin>>cases;

	string line;
	cin.ignore();
	getline(cin, line);

	while ((cases--)>0) {
		

		int number_of_job;
		cin>>number_of_job;
		jobs.clear();
		for(int i=0; i<number_of_job; i++) {
			int day,fine;
			cin>>day>>fine;
			Job job;
			//job.day = day;
			//job.fine = fine;
			job.number = i+1;
			job.ratio = (double)day/(double)fine;
			jobs.push_back(job);
		}
		int i,j;
		for(i=1; i<jobs.size(); i++) {
			j=i;
			while((j>0) && (jobs.at(j).ratio < jobs.at(j-1).ratio)) {
				Job temp = jobs.at(j);
				jobs.at(j) = jobs.at(j-1);
				jobs.at(j-1) = temp;
				j = j-1;
			}
		}
		//cout<<"\n";
		for(int i=0; i<jobs.size(); i++) {
			cout<<jobs.at(i).number;
			if(i != jobs.size()-1) cout<<" ";
			else cout<<"\n";
		}

		if(cases>0)
			cout<<endl;
	}


	return 0;
}
