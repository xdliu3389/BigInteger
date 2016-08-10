//
// Created by sjlxd on 16-8-10.
//

#include <sstream>
#include "BigInteger.h"


BigInt::BigInt(const string &s) {
    sign = (s[0]=='-')?false:true;
    num = s;
    if(s[0]=='-')
        num = num.substr(1);
}

BigInt::BigInt(int n) {
    stringstream ss;
    ss << n;
    if(n >= 0)
        num = ss.str();
    else
        num = ss.str().substr(1);
    sign = (num[0]=='-')?false:true;
}

string BigInt::getVal() const{
    return num;
}

bool BigInt::getSign() const{
    return sign;
}

BigInt &BigInt::operator=(const BigInt &v) {
    num = v.getVal();
    sign = v.getSign();
    return *this;
}

bool BigInt::operator!=(const BigInt &v) {
    if(sign==v.getSign() && num==v.getVal())
        return false;
    return true;
}

bool BigInt::operator==(const BigInt &v) {
    if(sign==v.getSign() && num==v.getVal())
        return true;
    return false;
}

bool BigInt::operator>(const BigInt &v) {
    if(sign==true && v.getSign()==false)
        return true;
    if(sign==v.getSign() && num>v.getVal())
        return true;
    return false;
}

bool BigInt::operator>=(const BigInt &v) {
    if(sign==true && v.getSign()==false)
        return true;
    if (sign==v.getSign() && num>=v.getVal())
        return true;
    return false;
}

bool BigInt::operator<(const BigInt &v) {
    if(sign==false && v.getSign()==true)
        return true;
    if (sign==v.getSign() && num<v.getVal())
        return true;
    return false;
}

bool BigInt::operator<=(const BigInt &v) {
    if(sign==false && v.getSign()==true)
        return true;
    if (sign==v.getSign() && num<=v.getVal())
        return true;
    return false;
}

BigInt &BigInt::operator+(const BigInt &v) {
    add(v);
}

BigInt &BigInt::operator-(const BigInt &v) {
    sub(v);
}

BigInt &BigInt::operator*(const BigInt &v) {

}


int BigInt::numCmp(const BigInt &v) {
    string tmp = v.getVal();
    if(num.size() > tmp.size())
        return 1;
    else if(num.size() < tmp.size())
        return -1;
    else {
        for(int i=0; i<num.size(); i++) {
            if(num[i] > tmp[i])
                return 1;
            else if(num[i] < tmp[i])
                return -1;
        }
        return 0;
    }
}

BigInt &BigInt::add(const BigInt &v) {
    string tmp = v.getVal();
    int len1=num.size(), len2=tmp.size(), len, carry;
    len = len1>len2?len1:len2;
    carry = 0;

    num.insert(0, len-len1, '0');
    tmp.insert(0, len-len2, '0');

    for(int i=len-1; i>=0; i--) {
        int sum = (num[i]-'0') + (tmp[i]-'0') + carry;
        num[i] = sum%10 + '0';
        carry = sum/10;
    }

    if(carry != 0)
        num.insert(0, 1, '1');

    return *this;
}

BigInt &BigInt::sub(const BigInt &v) {
    string tmp = v.getVal();
    int len1=num.size(), len2=tmp.size(), len, carry;
    len = len1>len2?len1:len2;
    carry = 0;

    num.insert(0, len-len1, '0');
    tmp.insert(0, len-len2, '0');
    cout << num << endl;
    cout << tmp << endl;
    for(int i=len-1; i>=0; i--) {
        int diff;
        if(num[i] >= tmp[i]+carry) {
            diff = (num[i]-'0') - (tmp[i]-'0') - carry;
            carry = 0;
        } else {
            diff = 10 + (num[i]-'0') - (tmp[i]-'0') - carry;
            carry = 1;
        }
        num[i] = diff%10 + '0';
    }

    return *this;
}

BigInt &BigInt::mul(const BigInt &v) {

}