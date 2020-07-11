#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.length();
    string str;
    int i=0;
    while(s[i]=='0'){
        str += '0';
        i++;
        if(i==n)
            break;
    }
    int yes = 0;
    for(i=0; i<n-1; i++){
        if(s[i]=='1' && s[i+1]=='0')
            yes = 1;
    }

    if(yes==1)
        str+='0';
    
    i = n - 1;
    while(s[i]=='1'){
        str+='1';
        i--;
        if(i < 0)
            break;
    }

    cout<<str<<"\n";
    //cout << "new test case\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*

while (flag)
    {
        int isChangePossible = 0;
        int index = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '1' && s[i + 1] == '0')
            {
                index = i;
                isChangePossible = 1;
            }
        }

        if (isChangePossible == 0)
        {
            flag = 0;
            break;
        }
        else
        {
            int zeros_forward = 0;
            for (int i = index + 1; i < len; i++)
            {
                if (s[i] == '0')
                    zeros_forward++;
                else
                {
                    break;
                }
            }

            if (zeros_forward > 1)
            {
                s.erase(index + 1, 1);
                len = s.length();
            }
            else if (zeros_forward == 1)
            {
                s.erase(index, 1);
                len = s.length();
            }

            //cout << "new string is " << s << "\n";

            //cout<<zeros_forward<<"\n";
        }
    }


string s0 = s;
            string s1 = s;

            s0.erase(index + 1, 1);
            s1.erase(index, 1);

            int len0 = s0.length();
            int len1 = s1.length();

            if (s0.compare(s1) < 0)
            {
                //s0 smaller than s1
                s.erase(index + 1, 1);
                len = s.length();
            }
            else
            {
                s.erase(index, 1);
                len = s.length();
            }

            cout<<"new string is"<<s<<"\n";


if(zeros_forward > 1){
                s.erase(index + 1,1);
                len = s.length();
            }else{
                s.erase(index,1);
                len = s.length();
            }

            int zeros_forward=0;
            for(int i=index+1; i<len-1; i++){
                if(s[i]=='0')
                    zeros_forward++;
                else{
                    break;
                }
            }

*/