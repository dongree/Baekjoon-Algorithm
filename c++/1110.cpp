#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 10)
    {
        n *= 10;
    }
    int k = n;
    int count = 0;
    while (true)
    {
        k = (k % 10) * 10 + (k / 10 + k % 10) % 10;
        count += 1;
        if (k == n)
        {
            break;
        }
    }
    cout << count << endl;

    return 0;
}