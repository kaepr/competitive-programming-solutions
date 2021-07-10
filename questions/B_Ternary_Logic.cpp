#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int decToTer(int n)
{
    int ter = 0;
    int rem, i = 1;
    while (n != 0)
    {
        rem = n % 3;
        n /= 3;
        ter += rem * i;
        i *= 10;
    }
    return ter;
}

int calc(int a, int b)
{
    int num = 0;
    int i = 1;
    while (a != 0 || b != 0)
    {
        int dig = (a % 10 + b % 10) % 3;
        a /= 10;
        b /= 10;
        num += dig * i;
        i *= 10;
    }
    return num;
}

int terToDec(int n)
{
    int dec = 0, i = 0, rem;
    while (n != 0)
    {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(3, i);
        ++i;
    }
    return dec;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,c,ad[20]={0},an=0,cd[20]={0},cn=0;
    cin>>a>>c;
    while(a!=0){
        ad[an++] = a%3;
        a/=3;
    }

    while (c != 0)
    {
        cd[cn++] = c % 3;
        c /= 3;
    }

    int tor = 0;
    for(int i=max(an,cn); i>=0; i--){
        tor = tor*3 + (cd[i] + 3 - ad[i])%3;
    }
    cout<<tor<<"\n";



    return 0;
}