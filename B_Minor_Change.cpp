#include <bits/stdc++.h>

using namespace std;

vector<long long>
solve(vector<long long> A, vector<long long int> R,
      vector<long long int> L)
{

    long long n = A.size(), m = L.size(), mo = 1000000007;

    vector<long long> ans(m);

    vector<long long> sum(n + 1);

    sum[0] = 0;

    for (long long i = 0; i < n; i++)

    {

        sum[i + 1] = (sum[i] + A[i]) % mo;
    }

    long long temp;

    for (long long i = 0; i < m; i++)

    {

        L[i]--;

        temp =
            (sum[R[i] % n] - sum[L[i] % n] +
             ((sum[n] * ((R[i] / n - L[i] / n) % mo)))) %
            mo;

        ans[i] = temp;
    }

    return ans;
}

int main()
{

    ios::sync_with_stdio(0);

    cin.tie(0);

    long long T;

    cin >> T;

    for (long long t_i = 0; t_i < T; t_i++)

    {

        long long N;

        cin >> N;

        vector<long long> A(N);

        for (long long i_A = 0; i_A < N; i_A++)

        {

            cin >> A[i_A];
        }

        long long Q;

        cin >> Q;

        vector<long long int> L(Q);

        for (long long i_L = 0; i_L < Q; i_L++)

        {

            cin >> L[i_L];
        }

        vector<long long int> R(Q);

        for (long long i_R = 0; i_R < Q; i_R++)

        {

            cin >> R[i_R];
        }

        vector<long long> out_;

        out_ = solve(A, R, L);

        cout << out_[0];

        for (long long i_out_ = 1; i_out_ < out_.size(); i_out_++)

        {

            cout << " " << out_[i_out_];
        }

        cout << "\n";
    }
}
