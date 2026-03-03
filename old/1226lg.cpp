#include <iostream>
//     #include<algorithm>
#include <cmath>

using namespace std;

int main() {
    long long a,b,p;
    cin>>a>>b>>p;
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<(long long)pow(a,b)%p;
    return 0;
}