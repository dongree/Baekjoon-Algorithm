#include <iostream>
#include <vector>

using namespace std;

long long sum(std::vector<int> &a)
{
    long long ans = 0;
    for (auto num : a)
        ans += num;
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    long b = sum(v);

    cout << b << endl;

    return 0;
}
