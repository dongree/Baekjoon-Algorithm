#include <iostream>
#include <vector>

using namespace std;

// my answer
// int main()
// {
//     vector<int> array;
//     for (int i = 0; i < 10; i++)
//     {
//         int a;

//         cin >> a;
//         a %= 42;
//         array.push_back(a);
//         for (int j = 0; j < array.size() - 1; j++)
//         {
//             if (a == array[j])
//             {
//                 array.pop_back();
//                 break;
//             }
//         }
//     }
//     cout << array.size() << endl;

//     return 0;
// }

// other answer
int main()
{
    int input, count = 0;
    int arr[42] = {
        0,
    };

    for (int i = 0; i < 10; i++)
    {
        cin >> input;
        if (!arr[input % 42]++)
            count++;
    }
    cout << count;
}