//
// Created by sjlxd on 16-8-10.
//

#include <sstream>
#include <vector>
#include "BigInteger.h"

BigInt::BigInt(const BigInt &v) {
    num = v.getVal();
    sign = v.getSign();
    clrHeadZero();
}

BigInt::BigInt(const string &s){
    sign = s[0]!='-';
    num = s;
    if(s[0]=='-')
        num = num.substr(1);
    clrHeadZero();
}

BigInt::BigInt(int n) {
    stringstream ss;
    ss << n;
    if(n >= 0)
        num = ss.str();
    else
        num = ss.str().substr(1);
    sign = num[0]!='-';
    clrHeadZero();
}

void BigInt::setSign(bool f) {
    sign = f;
}


string BigInt::printVal() const {
    string res = num;
    if(!sign)
        res.insert(0, 1, '-');
    return res;
}

string BigInt::getVal() const{
    return num;
}

bool BigInt::getSign() const{
    return sign;
}

BigInt &BigInt::operator=(const string &s) {
    if(s[0] == '-') {
        num = s.substr(1);
        sign = false;
    } else {
        num = s;
        sign = true;
    }
    clrHeadZero();
    return *this;
}

BigInt &BigInt::operator=(const BigInt &v) {
    num = v.getVal();
    sign = v.getSign();
    clrHeadZero();
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
    if(sign && !v.getSign())
        return true;
    if(sign && v.getSign() && numCmp(v) == 1)
        return true;
    if(!sign && !v.getSign() && numCmp(v) == -1)
        return true;
    return false;
}

bool BigInt::operator>=(const BigInt &v) {
    if(sign && !v.getSign())
        return true;
    if(sign && v.getSign() && numCmp(v) >= 0)
        return true;
    if(!sign && !v.getSign() && numCmp(v) <= 0)
        return true;
    return false;
}

bool BigInt::operator<(const BigInt &v) {
    if (!sign && v.getSign())
        return true;
    if (!sign && !v.getSign() && numCmp(v) == 1)
        return true;
    if (sign && v.getSign() && numCmp(v) == -1)
        return true;
    return false;
}

bool BigInt::operator<=(const BigInt &v) {
    if (!sign && v.getSign())
        return true;
    if (!sign && !v.getSign() && numCmp(v) >= 0)
        return true;
    if (sign && v.getSign() && numCmp(v) <= 0)
        return true;
    return false;
}

BigInt BigInt::operator+(const BigInt &v) {
    BigInt res;
    if(sign == v.getSign()) {
        res = add(v);
        res.setSign(sign);
    } else {
        if(numCmp(v) >= 0) {
            res = sub(v);
            res.setSign(sign);
        } else {
            // can't do v.sub(*this). Because v is a const reference, and it's not allowed to call non-const function.
            res = v;
            res = res.sub(*this);
            res.setSign(v.getSign());
        }
    }
    return res;
}

BigInt BigInt::operator-(const BigInt &v) {
    BigInt res;
    if(sign != v.getSign()) {
        res = add(v);
        res.setSign(sign);
    } else {
        if(numCmp(v) >= 0) {
            res = sub(v);
            res.setSign(sign);
        } else {
            res = v;
            res = res.sub(*this);
            res.setSign(v.getSign());
        }
    }
    return res;
}

BigInt BigInt::operator*(const BigInt &v) {
    BigInt res;
    res = mul(v);
    res.setSign(!(sign ^ v.getSign()));
    return res;
}

// clear all 0 in the front of num
void BigInt::clrHeadZero() {
    for(int i=0; i<num.size(); i++) {
        if(num[i] != '0') {
            num = num.substr(i);
            break;
        }
    }
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

BigInt BigInt::add(BigInt v) {
    BigInt res(*this);
    string tmp = v.getVal(), resStr = res.getVal();
    int len1=resStr.size(), len2=tmp.size(), len, carry;
    len = len1>len2?len1:len2;
    carry = 0;

    resStr.insert(0, len-len1, '0');
    tmp.insert(0, len-len2, '0');

    for(int i=len-1; i>=0; i--) {
        int sum = (resStr[i]-'0') + (tmp[i]-'0') + carry;
        resStr[i] = sum%10 + '0';
        carry = sum/10;
    }

    if(carry != 0)
        resStr.insert(0, 1, '1');
    res = resStr;
    return res;
}

BigInt BigInt::sub(BigInt v) {
    BigInt res(*this);
    string tmp = v.getVal(), resStr = res.getVal();
    int len1=resStr.size(), len2=tmp.size(), len, carry;
    len = len1>len2?len1:len2;
    carry = 0;

    resStr.insert(0, len-len1, '0');
    tmp.insert(0, len-len2, '0');

    for(int i=len-1; i>=0; i--) {
        int diff;
        if(resStr[i] >= tmp[i]+carry) {
            diff = (resStr[i]-'0') - (tmp[i]-'0') - carry;
            carry = 0;
        } else {
            diff = 10 + (resStr[i]-'0') - (tmp[i]-'0') - carry;
            carry = 1;
        }
        resStr[i] = diff%10 + '0';
    }
    res = resStr;
    return res;
}

BigInt BigInt::mul(BigInt v) {
    BigInt res(*this);
    string tmp = v.getVal(), resStr = res.getVal();
    int len1 = resStr.size(), len2=tmp.size(), len, carry;
    len = len1+len2;
    carry = 0;

    vector<int> ans(len-1, 0);
    //for num1*num2.
    // i->index of num1; j->index of num2;
    // (i+j)->index of num1*num2
    // Use vector because char is limited to 255, which is not enough for big number like 9, 8, 7...
    for(int i=len1-1; i>=0; i--) {
        for(int j=len2-1; j>=0; j--) {
            ans[i+j] += (resStr[i]-'0')*(tmp[j]-'0');
        }
    }

    resStr.clear();
    for(int i=ans.size()-1; i>=0; i--) {
        int sum = ans[i]+carry;
        resStr.insert(0, 1, sum%10+'0');
        carry = sum / 10;
    }
    while(carry > 0) {
        resStr.insert(0, 1, carry%10+'0');
        carry = carry / 10;
    }
    res = resStr;
    return res;
}
