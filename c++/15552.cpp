#include <iostream>
#include <cstdio>

using namespace std;

int main()
{   
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, a, b;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}