#include <iostream>
using namespace std;
const int MOD = 1000000007;

long long int power(long long int base, long long int exponent) {
    long long int result = 1;
    base = base % MOD;

    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % MOD;
        }

        base = (base * base) % MOD;
        exponent >>= 1;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long int a, b;
    cin >> a >> b;

    long long int result = power(a, b);

    cout << result << endl;

    return 0;
}