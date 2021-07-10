#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1,s2;
    cin>>s1>>s2;

    int finalPos = 0;
    for(int i=0; i<s1.length(); i++)
        if(s1[i]=='+')
            finalPos++;
        else
            finalPos--;
    
    int finalPos2 = 0;
    int ques = 0;
    for(int i=0; i<s2.length(); i++)
        if(s2[i]=='+')
            finalPos2++;
        else if(s2[i]=='-')
            finalPos2--;
        else
            ques++;
    
    int dist = finalPos - finalPos2;
    double answer;
    
    if((dist + ques) %2 != 0 || ques < abs(dist))
        answer = 0;
    else{
        int m = (ques + abs(dist))/2;
        int c = 1;
        for(int i=0; i<m; i++)
            c*=(ques - i);
        
        for(int i=2; i<=m; i++)
            c/=i;
        
        answer = (double)c/(1<<ques);
    }
    printf("%.12f\n", answer);
    
    

    

    return 0;
}