#ifndef _BIGINTEGER_H_
#define _BIGINTEGER_H_
#include <iostream>
#include <string>

using namespace std;

class BigInt {
public:
	BigInt();
	BigInt(string s) : num(s) {}	
	BigInt(int n) : num(itoa(n)) {}
	
	BigInt operator = (const string &s);
	BigInt operator = (const BigInt &v);
	BigInt operator != (const string &s);
	BigInt operator != (const BigInt &v);
	bool operator == (const string &s);
	bool operator == (const BigInt &v);
	bool operator > (const string &s);
	bool operator > (const BigInt &v);
	bool operator >= (const string &s);
	bool operator >= (const BigInt &v);
	bool operator < (const string &s);
	bool operator < (const BigInt &v);
	bool operator <= (const string &s);
	bool operator <= (const BigInt &v);		
	BigInt operator + (const string &s);
	BigInt operator + (const BigInt &v);		
	BigInt operator - (const string &s);
	BigInt operator - (const BigInt &v);		
	BigInt operator * (const string &s);
	BigInt operator * (const BigInt &v);	

private:
	string num;
	bool sign;

	
};

#endif
