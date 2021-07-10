#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    while(n>0){
        char word[102];
        scanf("%s",word);
        int len = strlen(word);
        if(len<=10)
            printf("%s\n",word);
        else if(len>10){
            int a = len -2;
            printf("%c%d%c\n",word[0],a,word[len-1]);
        }
        n--;
    }
    return 0;
}