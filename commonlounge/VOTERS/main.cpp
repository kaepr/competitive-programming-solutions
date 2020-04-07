#include <iostream>

#include <algorithm>

#include <vector>

 

using namespace std;

 

int main(){

int n1,n2,n3;

cin >> n1 >> n2 >> n3;

int total = n1 + n2 + n3;

int a[total];

for (int i = 0;i < total;i++)

{

    cin >> a[i];

}

sort(a,a+total);

int prev,cont = 1;

prev = a[0];

vector<int> voters;

for (int i = 1;i < total + 1;i++)

{

    if (prev == a[i])

    {

        cont++;

    }

    else{

        if (cont >= 2)

        {

            voters.push_back(prev);

        }

        prev = a[i];

        cont = 1;

    }

}

int x = voters.size();

cout << x  << endl;

for (int c = 0;c < x;c++)

    cout << voters[c] << endl;

        return 0;

}