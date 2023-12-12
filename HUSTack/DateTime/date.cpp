#include <bits/stdc++.h>
using namespace std;
int month, year, day, hour, minute, second, second1;
int hour2, minute2, second2;
char c, d, s;
string str;
vector<string> date;

string getString(int number){
    if (number < 10) return "0";
    return "";
}
int getHour(int second){
    return second / 3600;
}

int getMinute(int second){
    return (second - getHour(second) * 3600)/60;
}

int getSecond (int second){
    return (second - getHour(second) * 3600 - getMinute(second) * 60);
}

int ChangeToSecond(int hour, int minute, int second){
    return hour * 3600 + minute * 60 + second;
}


int main(){
    ios_base::sync_with_stdio(0);
    getline(cin, str);
    stringstream ss(str);
    ss >> year >> c >> month >> c >> day >> hour >> s >> minute >> s >> second;
    cout << hour << endl;
    // cout << setw(4) << year << setfill('0') <<  setw(2) << month << setfill('0') << setw(2) <<  day << setfill('0') << setw(2) << hour << setfill('0') << setw(2) << minute << setfill('0') << setw(2) << second;
    do {
        getline(cin , str);
        do {
            if (str.compare("*") == 0) 
            break;
            stringstream ss(str);
            ss >> year >> c >> month >> c >> day;
            string temp = to_string(year) + "-" + getString(month) + to_string(month) + "-" + getString(day) + to_string(day);
            date.push_back(temp);
        }
        while (str.compare("*") != 0);
        if (str.compare("***") == 0)
        break;
        stringstream ss(str);
        ss >> year >> c >> month >> c >> day >> hour >> s >> minute >> s >> second >> second1;
        int hour2 = getHour(second1);
        int minute2 = getMinute(second1);
        int second2 = getSecond(second1);
        string temp2 = to_string(year) + "-" + getString(month) + to_string(month) + "-" + getString(day) + to_string(day);
        if (ChangeToSecond(hour, minute, second) + second1 >= 24 * 3600){
            for (int i = 0 ; i < date.size(); i++){
                if (date[i].compare(temp2) == 0){
                    string temp3 = date[i+1];
                    int hour3 = hour + hour2 - 24;
                    int minute3 = minute + minute2 - 60;
                    int second3 = second + second2 - 60;
                    cout << temp3 << " " << getString(hour3) << to_string(hour3) << ":" << getString(minute3) << to_string(minute3)
                    << ":" << getString(second3) << to_string(second3);
                }
            }
        }
        else {
            int hour3 = hour + hour2;
            int minute3 = minute + minute2;
            int second3 = second + second2;
            cout << temp2 << " " << getString(hour3) << to_string(hour3) << ":" << getString(minute3) << to_string(minute3)
                    << ":" << getString(second3) << to_string(second3);
        }
    }
    while (str.compare("***") != 0);
    

    return 0;
}