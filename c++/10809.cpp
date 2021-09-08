#include <iostream>
#include <string>

using namespace std;

// my answer
// int main()
// {

//     string s;
//     cin >> s;

//     for (int i = 0; i < 26; i++)
//     {
//         for (int j = 0; j < s.length(); j++)
//         {
//             if (char('a' + i) == s[j])
//             {
//                 cout << j << ' ';
//                 break;
//             }
//             if (j == s.length() - 1)
//                 cout << -1 << ' ';
//         }
//     }
//     return 0;
// }

// other answer
int main()
{
    string s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;

    for (int i = 0; i < alphabet.length(); i++)
    {
        cout << (int)s.find(alphabet[i]) << " ";
    }

    return 0;
}