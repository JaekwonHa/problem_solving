#include <iostream>
#include <string>

using namespace std;

#define MAXDIGITS 200
#define PLUS 1
#define MINUS -1

struct bignum {
	char digits[MAXDIGITS];
	int signbit;
	int lastdigit;
};
void initialize_bignum(bignum *a);
void zero_justify(bignum *n);
void add_bignum(bignum *a, bignum *b, bignum *c);
void subtract_bignum(bignum *a, bignum *b, bignum *c);
int compare_bignum(bignum *a, bignum *b);
void multiply_bignum(bignum *a, bignum *b, bignum *c);
void digit_shift(bignum *n, int d);
void divide_bignum(bignum *a, bignum *b, bignum *c);
bignum input_bignum(string input);

int main() {

	int cases, i,j;
	bignum input;
	cin>>cases;
	for(j=0; j<cases; j++) {
	
		string input;
		cin>>input;
		if(input=="0") cout<<"1"<<endl;
		else if(input=="1") cout<<"1"<<endl;
		else if(input=="2") cout<<"2"<<endl;
		else if(input=="3") cout<<"4"<<endl;
		else {
			bignum a,b,c,d,e,f;
			a = input_bignum(input);
			string z = "1";
			b = input_bignum(z);
			subtract_bignum(&a, &b, &c);
			multiply_bignum(&a, &c, &d);
			z = "2";
			b = input_bignum(z);
			subtract_bignum(&a, &b, &e);
			z = '3';
			b = input_bignum(z);
			subtract_bignum(&a, &b, &c);
			multiply_bignum(&e, &c, &f);

			multiply_bignum(&d, &f, &c);
			z = "2";
			b = input_bignum(z);
			divide_bignum(&d, &b, &f);
			z = "24";
			b = input_bignum(z);
			divide_bignum(&c, &b, &d);
			z = "1";
			b = input_bignum(z);
			add_bignum(&d, &f, &e);
			add_bignum(&e, &b, &a);

			int x;
			for(i=a.lastdigit-1; i>=0; i--) {
				x = a.digits[i];
				cout<<x;
			}
			cout<<endl;
		}
	}

	return 0;
}

void initialize_bignum(bignum *a) {
	
	for(int i=0; i<MAXDIGITS; i++)
		a->digits[i] = 0;
	a->signbit=PLUS;
	a->lastdigit=0;
}
void zero_justify(bignum *n) {
	while((n->lastdigit>0) && (n->digits[n->lastdigit-1]==0))
		n->lastdigit--;
	if((n->lastdigit==0) && (n->digits[0]==0))
		n->signbit = PLUS;
}
void add_bignum(bignum *a, bignum *b, bignum *c) {
	int carry;
	int i;
	initialize_bignum(c);
	if(a->signbit == b->signbit) c->signbit = a->signbit;
	else {
		if(a->signbit == MINUS) {
			a->signbit = PLUS;
			subtract_bignum(b,a,c);
			a->signbit = MINUS;
		} else {
			b->signbit = PLUS;
			subtract_bignum(a,b,c);
			b->signbit = MINUS;
		}
		return;
	}
	c->lastdigit = max(a->lastdigit, b->lastdigit)+1;
	carry=0;
	for(i=0; i<=(c->lastdigit); i++) {
		c->digits[i] = (char) (carry+a->digits[i]+b->digits[i]) % 10;
		carry = (carry + a->digits[i] + b->digits[i]) / 10;
	}
	zero_justify(c);
}
void subtract_bignum(bignum *a, bignum *b, bignum *c) {
	int borrow;
	int v;
	int i;
	initialize_bignum(c);
	if((a->signbit==MINUS) || (b->signbit==MINUS)) {
		b->signbit = -1 * b->signbit;
		add_bignum(a,b,c);
		b->signbit = -1 * b->signbit;
		return;
	}
	if(compare_bignum(a,b) == PLUS) {
		subtract_bignum(b,a,c);
		c->signbit = MINUS;
		return;
	}
	c->lastdigit = max(a->lastdigit, b->lastdigit);
	borrow = 0;
	for(i=0; i<=(c->lastdigit); i++) {
		v=(a->digits[i] - borrow - b->digits[i]);
		if(a->digits[i]>0)
			borrow =0;
		if(v<0) {
			v = v+10;
			borrow = 1;
		}
		c->digits[i] = (char) v%10;
	}
	zero_justify(c);
}
int compare_bignum(bignum *a, bignum *b) {
	int i;

	//if(a->digits[a->lastdigit-1] == 0) return PLUS;

	if((a->signbit==MINUS) && (b->signbit==PLUS)) return (PLUS);
	if((a->signbit==PLUS) && (b->signbit==MINUS)) return (MINUS);
	if((b->lastdigit > a->lastdigit)) return (PLUS * a->signbit);
	if((a->lastdigit > b->lastdigit)) return (MINUS * a->signbit);

	

	for(i=a->lastdigit; i>=0; i--) {
		if(a->digits[i] > b->digits[i])
			return(MINUS * a->signbit);
		if(b->digits[i] > a->digits[i])
			return(PLUS * a->signbit);
	}
	return(0);
}
void multiply_bignum(bignum *a, bignum *b, bignum *c) {
	bignum row;
	bignum tmp;
	int i,j;

	initialize_bignum(c);
	row = *a;
	for(i=0; i<=b->lastdigit; i++) {
		for(j=1; j<=b->digits[i]; j++) {
			add_bignum(c, &row, &tmp);
			*c = tmp;
		}
		digit_shift(&row,1);
	}
	c->signbit = a->signbit * b->signbit;
	zero_justify(c);
}
void digit_shift(bignum *n, int d) {
	int i;
	if((n->lastdigit==0) && (n->digits[0]==0)) return;
	for(i=n->lastdigit; i>=0; i--) 
		n->digits[i+d] = n->digits[i];
	for(i=0; i<d; i++) n->digits[i]=0;
	n->lastdigit = n->lastdigit+d;
}
void divide_bignum(bignum *a, bignum *b, bignum *c) {
	/*
	initialize_bignum(c);

	bignum row=*a;
	bignum tmp;
	string number="0";
	bignum count = input_bignum(number);
	number = "1";
	bignum one = input_bignum(number);
	while(row.lastdigit>0) {
		subtract_bignum(&row,b,&tmp);
		row = tmp;
		add_bignum(&count,&one,c);
		count = *c;
	}
	*/
	
	
	bignum row;
	bignum tmp;
	int asign, bsign;
	int i,j;

	initialize_bignum(c);

	c->signbit = a->signbit * b->signbit;
	asign = a->signbit;
	bsign = b->signbit;
	a->signbit = PLUS;
	b->signbit = PLUS;

	initialize_bignum(&row);
	initialize_bignum(&tmp);
	c->lastdigit = a->lastdigit;

	for(i=a->lastdigit-1; i>=0; i--) {
		
		
		digit_shift(&row, 1);
		row.digits[0] = a->digits[i];
		if(row.lastdigit==0) row.lastdigit++;
		c->digits[i]=0;
		zero_justify(&row);
		while(compare_bignum(&row,b) != PLUS) {
			c->digits[i]++;
			subtract_bignum(&row,b,&tmp);
			row = tmp;
		}
	}
	zero_justify(c);

	a->signbit = asign;
	b->signbit = bsign;
	
}
bignum input_bignum(string input)
{
	bignum temp;
	initialize_bignum(&temp);

	

	for(int i=0; i<input.length(); i++) {
		temp.digits[i]=input[input.length()-1-i]-'0';
	}
	temp.lastdigit = input.length();

	return temp;
}