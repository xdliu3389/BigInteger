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
    BigInt(const BigInt &v);
    BigInt(const string &s);
    BigInt(int n);

    void setSign(bool f);
    string printVal() const;
    string getVal() const;
    bool getSign() const;
    BigInt &operator = (const string &s);
    BigInt &operator = (const BigInt &v);
    bool operator != (const BigInt &v);
    bool operator == (const BigInt &v);
    bool operator > (const BigInt &v);
    bool operator >= (const BigInt &v);
    bool operator < (const BigInt &v);
    bool operator <= (const BigInt &v);
    BigInt operator + (const BigInt &v);
    BigInt operator - (const BigInt &v);
    BigInt operator * (const BigInt &v);

private:
    void clrHeadZero();
    int numCmp(const BigInt &v);
    BigInt add(BigInt v);
    BigInt sub(BigInt v);
    BigInt mul(BigInt v);

    string num;
    bool sign;


};

#endif
