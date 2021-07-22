#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int ma = -10000001;
    int mi = 10000001;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k > ma)
        {
            ma = k;
        }
        if (k < mi)
        {
            mi = k;
        }
    }

    cout << mi << " " << ma;

    return 0;
}