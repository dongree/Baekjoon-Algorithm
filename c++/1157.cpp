#include <iostream>
#include <string>

using namespace std;

// my answer
// int main()
// {
//     string s;
//     char alphabet[26] = {};
//     for (int i = 0; i < 26; i++)
//     {
//         alphabet[i] = '!';
//     }
//     int alphabetCount[26] = {
//         0,
//     };
//     int max = 0;
//     int maxIndex;
//     int count = 0;

//     cin >> s;

//     // 중복제외 alphabet 찾기
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] >= 'a' && s[i] <= 'z')
//             s[i] = (char)toupper(s[i]);

//         for (int j = 0; j < 26; j++)
//         {
//             if (alphabet[j] == '!')
//             {
//                 alphabet[j] = s[i];
//                 break;
//             }
//             else if (s[i] == alphabet[j])
//                 break;
//         }
//     }

//     // alphabetCount 구하기
//     for (int i = 0; i < 26; i++)
//     {
//         if (alphabet[i] == '!')
//             break;

//         for (int j = 0; j < s.length(); j++)
//         {
//             if (alphabet[i] == s[j])
//                 alphabetCount[i] += 1;
//         }
//     }

//     // alphabetCount maxIndex값 구하기
//     for (int i = 0; i < 26; i++)
//     {
//         if (alphabetCount[i] == 0)
//             break;
//         if (max < alphabetCount[i]){
//             max = alphabetCount[i];
//             maxIndex = i;
//         }
//     }

//     for (int i = 0; i < 26; i++)
//     {
//         if (alphabetCount[i] == 0)
//             break;
//         if (max == alphabetCount[i])
//             count += 1;
//     }

//     if (count == 1)
//         cout << alphabet[maxIndex] << endl;
//     else
//         cout << '?' << endl;

//     return 0;
// }

// other answer
int main()
{
    string s;
    int arr[26] = {0,};
    int index, max = 0;
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    
    cin >> s;
    
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
        arr[alphabet.find(s[i])]++;
    }

    for (int j = 0; j < 26; j++)
    {
        if (arr[j] == 0)
            continue;
        if (max == arr[j]){
            index = 26;
            continue;
        }

        if (arr[j] > max)
        {
            max = arr[j];
            index = j;
        }
    }
    cout << alphabet[index] << endl;

    return 0;
}