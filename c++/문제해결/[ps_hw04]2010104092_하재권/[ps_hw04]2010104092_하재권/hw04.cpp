#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct _Photo {
	int day, hour, min;
	int dist;
	bool enter_exit;
};
typedef struct _Photo Photo;
bool comparePhotos(Photo p1, Photo p2)
{
	return p1.day*24*60 + p1.hour*60 + p1.min < p2.day*24*60 + p2.hour*60 + p2.min;
}

int main() {

	int time[24];
	map< string, vector<Photo> > photos;

	int cases;
	cin>>cases;

	char input[5000];
	cin.ignore();

	gets(input);
	while ((cases--)>0) {
		photos.clear();
		
		gets(input);
		stringstream ss(input);
		for(int i=0; i<24; i++) ss >> time[i];

		while(fgets(input,5000,stdin)) {
			ss.str("");
			ss.clear();

			if(input[0] == '\n') break;
			ss << input;

			string license;
			Photo newdata;
			int month;
			char buff;
			string action;
			ss >> license >> month >> buff >> newdata.day >> buff >> newdata.hour >> buff >> newdata.min >> action >> newdata.dist;
			newdata.enter_exit = (action == "enter") ? (true) : (false);
			photos[license].push_back(newdata);
		}
		for(map< string, vector<Photo> >::iterator it = photos.begin(); it != photos.end(); ++it) {
			sort(it->second.begin(), it->second.end(), comparePhotos);
			double bill=0;
			for(int j=0; j<it->second.size(); j++) {
				if(it->second[j].enter_exit) {
					if(j < it->second.size()-1 && it->second[j+1].enter_exit == false ) {
						int dist = abs(it->second[j].dist - it->second[j+1].dist);
						bill += (double)time[it->second[j].hour]*(double)dist/100.00 + 1.00;
					}
				}
			}
			cout << fixed;
			cout.precision(2);
			if(bill != 0) cout<<it->first<<" $"<<bill+2<<"\n";
		}

		if(cases>0)
			cout<<endl;
	}

	return 0;
}