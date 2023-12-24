// List khá giống vector cơ mà kiểu nó có thể tìm, chèn, xoá... Nhanh hơn ấy
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> myList{1,2,3,4,5,6};


    list<int>::iterator it = myList.begin();
    advance(it, 2);   // set con trỏ trỏ đến vị trí begin +2 
    myList.insert(it, 10);   // này là chèn 10 vào đấy => 1 2 10 3 4 5 6
    // ngoài ra còn có kiểu insert(it1, it2) là chèn vô từ vị trí trỏ 1 đến 2
    list<int>::iterator it1 = myList.begin();
    advance(it1, 2);          
    myList.erase(it1);       // này là xoá phần tử thứ 2 nè, thì cái phần tử 10 ấy bị xoá
    // ngoài ra còn có kiểu erase(it1, it2) là xoá từ vị trí trỏ 1 đến 2
	for (auto i : myList) {
		cout << i << ' ';     // này là in nè :D
	}
    list<int>::iterator it2 = myList.begin();
    advance(it2, 3); 
    cout << *it2 // này là in cái giá trị ở con trỏ it2 chỉ vào ấy
	return 0;
}

/*
Một số thao tác cơ bản trên std::list
front() – Trả về giá trị của phần tử đầu tiên trong danh sách.
back() – Trả về giá trị của phần tử cuối cùng trong danh sách.
push_front(g) – Thêm phần tử mới 'g' vào đầu danh sách.
push_back(g) – Thêm phần tử mới 'g' vào cuối danh sách.
pop_front() – Xóa phần tử đầu tiên của danh sách và giảm kích thước của danh sách xuống 1.
pop_back() – Xóa phần tử cuối cùng của danh sách và giảm kích thước của danh sách xuống 1.
insert() – Chèn phần tử mới vào danh sách trước phần tử ở vị trí đã chỉ định.
size() – Trả về số phần tử trong danh sách.
begin() – Hàm Begin() trả về một iterator trỏ đến phần tử đầu tiên của danh sách.
end() – Hàm end() trả về một iterator trỏ đến phần tử cuối cùng theo lý thuyết theo sau phần tử cuối cùng.
empty() - Hàm empty() trả về true nếu kích thước là 0, ngược lại là false
clear() - Hàm clear() xoá list => kích thước là 0
*/