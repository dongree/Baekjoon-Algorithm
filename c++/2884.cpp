#include <iostream>

using namespace std;

int main()
{
    int h, m;

    cin >> h >> m;

    if (m < 45)
    {
        if (h == 0)
        {
            h = 23;
        }
        else
        {
            h -= 1;
        }
    }
    m = (m + 15) % 60;

    cout << h << " " << m << endl;
    return 0;
}