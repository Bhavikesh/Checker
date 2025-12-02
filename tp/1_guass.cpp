#include<bits/stdc++.h>
using namespace std;

long long recursiveCallGauss = 0, mulCountGauss = 0, addCountGauss = 0;
long long recursiveCallKar = 0, mulCountKar = 0, addCountKar = 0;

long long gaussMultiply(long long x, long long y){
    recursiveCallGauss++;

    string a = to_string(x);
    string b = to_string(y);
    int n = max(a.size(), b.size());

    if(n == 1){
        mulCountGauss++;
        return (x*y);
    }

    int m = n/2;
    long long x1 = stoll(a.substr(0, n-m));
    long long x0 = stoll(a.substr(n-m));
    long long y1 = stoll(b.substr(0,n-m));
    long long y0 = stoll(b.substr(n-m));

    long long p1 = x1*y1; mulCountGauss++;
    long long p2 = x0*y0; mulCountGauss++;
    long long p3 = (x1+x0) * (y1+y0); mulCountGauss++; addCountGauss+=2;

    return (p1*(long long)(pow(10,2*m))) + ((p3-p1-p2)*(long long)(pow(10,m)))+ p2;

}


int main(){
    long long a = 123456789;
    long long b = 987654321;

    cout<<"Gauss's Multiplicattion : "<<gaussMultiply(a,b)<<endl;
    cout<<"Multiplication : "<<mulCountGauss<<endl;
    cout<<"Addition : "<<addCountGauss<<endl;
    cout<<"Recursive Call : "<<recursiveCallGauss<<endl;
}