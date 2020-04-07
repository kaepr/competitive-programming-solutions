#include <bits/stdc++.h>
using namespace std;
ifstream f("data.in");
ofstream g("data.out");

int A[100], backInd, frontInd;

void push(int x){
    ++backInd;
    A[backInd] = x;
}

void Pop(){
    A[frontInd] = 0;
    ++frontInd;
}

bool isEmpty(){
    if(backInd < frontInd) return true;
                    else return false;
}

int front(){
    return A[frontInd];
}

int main(){
    backInd = -1;
    frontInd = 0;
    return 0;
}