#include <bits/stdc++.h>
using namespace std;
unordered_set<int> S;
int n;
int k;

int main(){
    // insert dữ liệu vào set , insert(k)
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> k;
        S.insert(k);
    }

    // nếu đã có, insert.second = false, else true và insert vào trong set
    cin >> k;
    auto check = S.insert(k);
    if (check.second) cout << "OK" << endl;
    else cout << "Fail" << endl;

    // find() nếu tìm thấy trỏ về phấn tử đó, nếu không trỏ đến end
    cin >> k;
    auto check1 = S.find(k);
    if (check1 != S.end()) cout << "OK" << endl;
    else cout << "Fail" << endl;

    // eraser() xóa phần tử ra khỏi set, không kiểm tra được ngoại lệ và lỗi
    cin >> k;
    S.erase(k);

    // duyệt set
    for (const auto &a : S){
        cout << a << " " ;
    }

    return 0;
}