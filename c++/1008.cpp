// 올바른 실수 자료형 적용해야 하는 문제
// float(4 byte) vs double(8 byte)
// float의 오차범위 10e-7 전후  double의 오참범위 10e-15

#include <iostream>

using namespace std;

int main()
{

    double a, b;
    cin >> a >> b;

    cout.precision(10);
    cout << a / b << endl;
    return 0;
}
