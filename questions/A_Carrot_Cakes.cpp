#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
 
using namespace std;
 
typedef long long LL;
typedef pair<int,int> PII;
 
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
 
#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
 
#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }
 
#define MOD 1000000007
#define INF 2000000000
 
int GLL(LL& x) {
    return scanf("%lld", &x);
}
 
int GI(int& x) {
    return scanf("%d", &x);
}
 
int n, t, k, d;
 
int main() {
    GI(n);
    GI(t);
    GI(k);
    GI(d);
 
    int currt = 0;
 
    while (currt <= d) {
        n -= k;
        currt += t;
    }
 
    if (n > 0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
 
    return 0;
}