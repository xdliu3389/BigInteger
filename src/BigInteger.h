//
// Created by sjlxd on 16-8-10.
//

#ifndef _BIGINTEGER_H_
#define _BIGINTEGER_H_
#include <iostream>
#include <string>

using namespace std;

class BigInt {
public:
    BigInt() : num(), sign(true){}
    BigInt(const string &s);
    BigInt(int n);

    string getVal() const;
    bool getSign() const;
    BigInt &operator = (const BigInt &v);
    bool operator != (const BigInt &v);
    bool operator == (const BigInt &v);
    bool operator > (const BigInt &v);
    bool operator >= (const BigInt &v);
    bool operator < (const BigInt &v);
    bool operator <= (const BigInt &v);
    BigInt &operator + (const BigInt &v);
    BigInt &operator - (const BigInt &v);
    BigInt &operator * (const BigInt &v);

private:
    int numCmp(const BigInt &v);
    BigInt &add(const BigInt &v);
    BigInt &sub(const BigInt &v);
    BigInt &mul(const BigInt &v);

    string num;
    bool sign;


};

#endif
