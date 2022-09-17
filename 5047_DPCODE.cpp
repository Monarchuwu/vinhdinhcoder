#include <iostream>
#include <string>

using namespace std;

string dp[5000], s;

string operator * (string s1, string s2)
{
    while (s1.size() < s2.size()) s1.push_back('0');
    while (s1.size() > s2.size()) s2.push_back('0');
    s1.push_back('0');
    s2.push_back('0');

    int rem = 0;
    for (int i = 0, n = s1.size(); i < n; ++i)
    {
        int tmp = s1[i] + s2[i] - 96 + rem;
        rem = tmp / 10;
        tmp %= 10;
        s1[i] = tmp + 48;
    }

    while (s1.back() == '0') s1.pop_back();

    return s1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    while (cin >> s)
    {
        if (s[0] == '0') break;

        int n = s.size();
        
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }

        dp[0] = "1";
        dp[1] = (s[1] == 48 ? "0" : "1");
        if ((s[0] - 48) * 10 + (s[1] - 48) < 27) dp[1] = dp[1] * "1";

        for (int i = 2; i < n; ++i)
        {
            dp[i] = (s[i] == 48 ? "0" : dp[i - 1]);
            if (s[i - 1] != 48 && (s[i - 1] - 48) * 10 + (s[i] - 48) < 27) dp[i] = dp[i] * dp[i - 2];
        }

        string& tmp = dp[n - 1];
        for (int i = tmp.size() - 1; i >= 0; --i) cout << tmp[i];
        cout << '\n';
    }

    return 0;
}
