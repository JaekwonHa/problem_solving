#include <iostream>
#include <iomanip>
#define NUMBERLENGTH 2500
#define ONEDIGIT 10000

using namespace std;

typedef struct _longlong {
	unsigned int h[NUMBERLENGTH];
} longlong;

static int k,d;
//static longlong result;
//static longlong fac[22];

longlong assign(unsigned int b) {
	int i;
	longlong temp;
	for(i=0; i<NUMBERLENGTH; i++) {
		temp.h[i] = b%ONEDIGIT;
		b /= ONEDIGIT;
	}
	return temp;
}
longlong add(const longlong *a, const longlong *b) {
	int i,carry;
	longlong result = assign(0);
	carry = 0;
	for(i=0; i<NUMBERLENGTH; i++) {
		result.h[i] = a->h[i] + b->h[i] + carry;
		carry = result.h[i]/ONEDIGIT;
		result.h[i] %= ONEDIGIT;
	}
	return result;
}
longlong sub(const longlong *a, const longlong *b) {
	int i,carry;
	longlong result = assign(0);
	carry=0;
	for(i=0; i<NUMBERLENGTH; i++) {
		if(a->h[i] >= b->h[i]+carry) {
			result.h[i] = a->h[i] - b->h[i] - carry;
			carry=0;
		} else {
			result.h[i] = (ONEDIGIT+a->h[i]) - b->h[i] - carry;
			carry = 1;
		}
	}
	return result;
}
longlong mul(const longlong *a, const longlong *b) {
	int i,j,carry;
	longlong result = assign(0);
	unsigned int temp;
	int in,jn;
	longlong d;

	for(i=0; i<NUMBERLENGTH; i++)
		d.h[i]=0;
	in = jn = NUMBERLENGTH-1;

	while(a->h[in] == 0)
		in--;
	in++;
	while(b->h[jn] == 0)
		jn--;
	jn++;

	for(i=0; i< in+1; i++) {
		carry=0;
		for(j=0; j< jn+1; j++)
			if(i+j<NUMBERLENGTH) {
				temp = (d.h[i+j]+a->h[i]*b->h[j] + carry)%ONEDIGIT;
				carry = (d.h[i+j]+a->h[i]*b->h[j] + carry)/ONEDIGIT;
				d.h[i+j] = temp;
			}
	}
	for(i=0; i< NUMBERLENGTH; i++)
		result.h[i] = d.h[i];
	return result;
}

int gcd(int a, int b) {
	int r;
	if(a>b) {
		r = a%b;
		if(r==0)
			return b;
		else
			return gcd(b,r);
	} else {
		r = b%a;
		if(r==0)
			return a;
		else
			return gcd(a,r);
	}
}
longlong combi(int n, int k) {
	int a[3000];
	int i,j;
	int ii;
	longlong t1;
	int i1;

	for(i=0; i<k; i++)
		a[i] = n-i;
	for(i=2; i<=k; i++) {
		ii = i;
		j = 0;
		while(ii > 1) {
			i1 = gcd(a[j], ii);
			a[j] = a[j]/i1;
			ii = ii/i1;
			j++;
		}
	}
	longlong com = assign(1);
	for(i=0; i<k; i++) {
		t1 = assign(a[i]);
		com = mul(&com,&t1);
	}
	return com;
}
void print(const longlong *a) {
	int i;
	int sw=0;
	for(i=NUMBERLENGTH -1; i>=0; i--) {
		if(!(sw==0 && a->h[i]==0)) {
			if(sw==0) {
				cout<<a->h[i];
				sw=1;
			} else {
				cout<<setfill('0')<<setw(4)<<a->h[i];
			}
		}
	}
	if(sw==0)
		cout<<0;
}
int main() {

	while(cin>>k>>d) {

		longlong c[22];
		int i,j;
		int power;
		int nodeSum;

		int dk;
		int temp;

		longlong com;

		nodeSum = 1;
		power = 1;
		c[0] = assign(1);
		for(i=1; i<=d; i++) {
			power = power*k;
			nodeSum = nodeSum + power;
			temp = nodeSum - 1;
			dk = temp / k;
			c[i] = assign(1);
			for(j=temp; j>=dk; j=j-dk) {
				com = combi(j,dk);
				c[i] = mul(&c[i],&com);
				c[i] = mul(&c[i],&c[i-1]);

			}
		}
		
		print(&c[d]);
		cout<<endl;
	}

	return 0;
}