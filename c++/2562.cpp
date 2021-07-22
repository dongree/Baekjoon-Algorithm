#include <iostream>

using namespace std;

int main()
{
    int k, maxIndex;
    int max = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> k;
        if (k > max)
        {
            max = k;
            maxIndex = i;
        }
    }

    cout << max << '\n'
         << maxIndex + 1;
    return 0;
}