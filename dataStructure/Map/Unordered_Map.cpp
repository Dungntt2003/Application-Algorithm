#include <bits/stdc++.h>
using namespace std;
unordered_map<int , string> Student;
int n;
int key;
string value;
// Cấu trúc dữ liệu unordered map
// thường được dùng khi dữ liệu kèm key và value

int main(){
    cin >> n;

    // thêm dữ liệu theo cặp key - value, không thêm trùng key, thứ tự như thứ tự nhập vào
    // thích hợp cho việc tìm kiếm và thêm phần tử nhanh
    // các phương thức y hệt như map 
    for (int i = 0 ; i < n ; i++){
        cin >> key >> value;
        Student.insert({key, value});
    }

    // cung cấp insert thêm theo cặp key - value, nếu .second == 1 thì insert thành công
    // nêú đã tồn tại thì thêm không thành công
    cin >> key >> value;
    auto check = Student.insert({key, value});
    if (check.second) cout << "Insert successfully" << endl;
    else cout << "Failed" << endl;


    // cung cấp phương thức find () , trả về con trỏ đến phần tử tìm thấy, tìm kiếm theo key
    cin >> key;
    auto check1 = Student.find(key);
    if (check1 != Student.end()) cout << "Find" << endl;
    else cout << "Failed" << endl;

    // cung cấp phương thức eraser cho phép xóa phần tử , trả về số lượng phần tử đã xóa
    cin >> key;
    auto check2 = Student.erase(key);
    if (check2 == 1) cout << "Erase" << endl;
    else cout << "Fail" << endl;
    

    // duyệt Map : dùng con trỏ a duyệt từ đầu đến cuối map nó sẽ in theo thứ tự tăng dần key
    for (const auto &a : Student){
        cout << a.first << " : " << a.second << endl;
    }

    // Ngoài ra còn có các phương thức khác như : 
    // map.size() : trả về số lượng phần tử
    // map.count(key) : trả vể số lượng cac phần tử có key là key
    // map.empty() : kiểm tra map có rỗng hay không
    // map.clear(); xóa toàn bộ phần tử của map
    // lower_bound() trả về iterator tới phần tử đầu tiên có key lớn hơn hoặc bằng key đã cho. Nếu không tìm thấy key lớn hơn hoặc bằng, nó sẽ trả về end().
    // Đây là cách tìm một phần tử hoặc vùng dữ liệu bắt đầu từ một key cụ thể.
    // Nếu key tồn tại trong map, lower_bound() sẽ trả về iterator tới phần tử có key đó.
    // upper_bound()
    // upper_bound() trả về iterator tới phần tử đầu tiên có key lớn hơn key đã cho.
    // Nếu không tìm thấy key nào lớn hơn, nó sẽ trả về end().
    // Đây cũng là cách tìm một phần tử hoặc vùng dữ liệu kết thúc trước một key cụ thể.
    // equal_range()
    // equal_range() trả về một cặp iterators. equal_range().first tương đương với lower_bound() và equal_range().second tương đương với upper_bound().


    return 0;
}