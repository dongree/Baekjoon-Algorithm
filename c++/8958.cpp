#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, score, total;
    string s;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        score = 0;
        total = 0;
        cin >> s;

        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'O')
            {
                score++;
                total += score;
            }
            else if (s[j] == 'X')
                score = 0;
        }
        cout << total << endl;
    }

    return 0;
}