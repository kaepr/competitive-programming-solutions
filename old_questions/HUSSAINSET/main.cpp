#include<iostream>

#include<bits/stdc++.h>

using namespace std;

int n,m,x;

unsigned long long int a[1000001];

unsigned long long int res[64000001];

stack<unsigned long long int> s;

queue<unsigned long long int> q;

int main(){

	cin>>n>>m;

for(int i=0;i<n;i++){

	cin>>a[i];

}

	sort(a,a+n);

for(int i=0;i<n;i++){

			s.push(a[i]);

}

int j=1;

	res[j++]=s.top();

	q.push(s.top()/2);

	s.pop();

while(!s.empty()){

if(s.top()>=q.front()){

if(s.top()/2 > 0){

				q.push(s.top()/2);

}

			res[j++]=s.top();

			s.pop();

}

else{

if(q.front()/2  > 0){

			q.push(q.front()/2);	

}

			res[j++]=q.front();

			q.pop();

}

}

while(!q.empty()){

		res[j++]=q.front();

if(q.front()/2  > 0){

			q.push(q.front()/2);	

}

				q.pop();

}

for(int i=0;i<m;i++){

		cin>>x;

		cout<<res[x]<<"\n";

}

}