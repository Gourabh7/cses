#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int ans = 0;
        for (int i = 1; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                if (x / i == i)
                {
                    ans++;
                }

                else
                {
                    ans = ans + 2;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}