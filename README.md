# Description
BigInteger is a lightweight library for BigInteger in C++. It's based on string and vector.

# How to use
## Init from int
```C
int n = 1024;
BigInt b(n);
```

## Init from string
```C
string s = "1024";
BigInt b(s);
BigInt b = s;
```

## Init from BigInteger
```C
BigInt a(1024);
BigInt b(a);
BigInt c = a;
```

## value with sign
```C
BigInt b(-1024);
std::cout << b.printVal() << std::endl;    //-1024
```
## value without sign
```C
BigInt b(-1024);
std::cout << b.getVal() << std::endl;      //1024
```

## get sign
```C
//true for positive, false for negative. 0 is positive in BigInteger
BigInt b(-1024);
std::cout << b.getSign() << std::endl;      //false;
```

## add, sub, mul
```C
BigInt a(-10), b(12);
BigInt c = a + b;
BigInt d = a - b;
BigInt e = a * b;
std::cout << c.printVal() << " " << d.printVal() << " " << e.printVal() << std::endl;
//2 -22 -120
```
