#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a, max = 0;
    int sum = 0;
    double result;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a > max)
            max = a;
        sum += a;
    }

    result = (sum * 100) / (double)(max * n);
    cout << result << endl;
    return 0;
}