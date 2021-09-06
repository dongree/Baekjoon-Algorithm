#include <iostream>

using namespace std;

int main()
{
    int c, count, stuNum, sum;
    int score[1000];
    double mean, result;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        sum = 0;
        count = 0;
        cin >> stuNum;
        for (int j = 0; j < stuNum; j++)
        {
            cin >> score[j];
            sum += score[j];
        }
        mean = sum / (double)stuNum;
        for (int j = 0; j < stuNum; j++)
        {
            if (score[j] > mean)
                count++;
        }
        result = count / (double)stuNum * 100;
        cout << fixed;
        cout.precision(3);
        cout << result << '%' << endl;
    }

    return 0;
}