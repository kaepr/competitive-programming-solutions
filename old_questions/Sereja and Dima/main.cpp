#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int S=0,D=0;
    int n; cin>>n;
    vector <int> cards(n);
    for(int i=0;i<n;i++)
        cin>>cards[i];
    int inner=0,outer=n-1;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(cards[inner]>cards[outer]){
                S+=cards[inner]; inner++;
            }
            else {S+=cards[outer]; outer--;}
        }
        else
        {
            if(cards[inner]>cards[outer]){
                D+=cards[inner]; inner++;
            }
            else {D+=cards[outer]; outer--;}
        }
    }
    cout<<S<<' '<<D<<endl;
}