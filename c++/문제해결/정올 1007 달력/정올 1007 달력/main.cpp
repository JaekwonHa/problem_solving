#include <iostream>
#include <iomanip>

using namespace std;



int isLeap(int y) {
	if(y%400==0) return 1;

	if(y%4 == 0) if(y%100!=0) return 1;

	return 0;
}

int main() {

	int y,m,d, day, total=0, i, j;
	int month[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int sum_day[13]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

	while(cin>>y>>m>>d) {
		
		if(m==2) {
			if(isLeap(y)) day=29;
			else day=28;
		} else day = month[m];
		
		
		if(y<2000 || y>2010 || m<1 || m>12 || d<1 || d>day) {
			cout<<"INPUT ERROR!"<<endl;
			continue;
		}

		total = 365*(y-2000);
		for(i=2000; i<y; i++) {
			if(isLeap(i)) total++;
		}
		total += sum_day[m-1];
		if(m>2 && isLeap(y)) total++;

		cout<<y<<". "<<m<<endl;

		cout<<"sun mon tue wed thu fri sat"<<endl;
		i=1;
		switch(total%7) {
		case 1:
			i=1;
			break;
		case 2:
			i=0;
			break;
		case 3:
			i=-1;
			break;
		case 4:
			i=-2;
			break;
		case 5:
			i=-3;
			break;
		case 6:
			i=-4;
			break;
		case 0:
			i=-5;
			break;
		}
		int count=0;
		for(;i<=day; i++) {
			if(count%7!=0) cout<<" ";
			if(i>0) cout<<setw(3)<<i;
			else cout<<setw(3)<<" ";
			if(count%7==6) cout<<endl;
			count++;
		}
		cout<<endl;


		total += (d-1);

		switch(total%7) {
		case 1:
			cout<<"Sunday";
			break;
		case 2:
			cout<<"Monday";
			break;
		case 3:
			cout<<"Tuesday";
			break;
		case 4:
			cout<<"Wednesday";
			break;
		case 5:
			cout<<"Thursday";
			break;
		case 6:
			cout<<"Friday";
			break;
		case 0:
			cout<<"Saturday";
			break;
		}
		//cout<<endl;
		break;


	
	}

	return 0;
}