#include <iostream>
#include <vector>

using namespace std;

// my soultion using vector
int main()
{

    int n, x;

    cin >> n >> x;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] < x)
        {
            cout << v[i] << ' ';
        }
    }
    return 0;
}

// other solution
// int main()
// {

//     int n, x, y;

//     cin >> n >> x;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> y;
//         if (y < x)
//         {
//             cout << y << ' ';
//         }
//     }
//     return 0;
// }