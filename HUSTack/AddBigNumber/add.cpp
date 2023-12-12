#include <bits/stdc++.h>
using namespace std;
string s1, s2;


string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    int result[len1 + len2] = {0};
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j] += sum / 10; 
            result[i + j + 1] = sum % 10; 
        }
    }

    string resultStr = "";
    for (int i = 0; i < len1 + len2; ++i) {
        if (!(resultStr.empty() && result[i] == 0)) {
            resultStr += (result[i] + '0');
        }
    }
    return resultStr.empty() ? "0" : resultStr;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s1;
    cin >> s2;
    cout << multiply(s1,s2) << endl;

    return 0;
}
