#include <iostream>
#include <string>

using namespace std;

// my soulution
// int main()
// {
//     int a, b, c;
//     string str;
//     int array[10] = {0, };

//     cin >> a >> b >> c;

//     str = to_string(a * b * c);

//     for (auto e : str)
//     {
//         array[int(e) - 48] += 1;
//     }

//     for (auto e : array)
//     {
//         cout << e << '\n';
//     }
//     return 0;
// }

// other solution

int main()
{
    int a, b, c, result;
    string str;
    int array[10] = {0, };

    cin >> a >> b >> c;

    result = a*b*c;

    while(result >0){
        array[result%10]++;
        result /= 10;
    }

    for (auto e : array)
    {
        cout << e << '\n';
    }
    return 0;
}