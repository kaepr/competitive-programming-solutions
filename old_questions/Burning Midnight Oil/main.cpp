#include<iostream>
using namespace std;
typedef  long long  ll;
ll sum ;
ll test(ll j,ll k);
ll  binarySearch(ll k, ll key, ll start, ll end)
{
	ll x;
	ll i = -1;
	while (start < end)
	{
		ll mid = start + (end - start) / 2;
		x = test(mid,k);
		//cout << x << endl;
		if (x < key && mid != x)
		{
			//cout << "one" << endl;
			//if(test((mid+ 1),k) > key)
 
			start = mid + 1;
		}
		else if (mid == x && mid<key )
		{
			//cout << "deux" << endl;
			end = mid;
		}
		else if(x>=key)
		{
			//cout << "trois" << endl;
			i = mid;
			end = mid;
		}
		//cout << start << " " << end << " " << i << endl;
		/*if (start == end )
		{
			start = k;
		}*/
	}
	return i;
}
int main()
{
	ll n,k;
	cin >> n >> k;
	if (n <= k)
		cout << n << endl;
	else
	{
		//cout << test(376, k) << endl;
		cout << binarySearch(k, n, k, n) << endl;
	}
}
ll test(ll j,ll k)
{
	sum = j;
	ll temp = k;
	while (j / k)
	{
		sum += j / k;
		k *= temp;
	}
	return sum;
}