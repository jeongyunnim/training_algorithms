//
// Created by 서정윤 on 8/15/24.
//
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    string input_string;
    list<char> list_input;
    int input_count = 0;
    char input_char;
    list<char>::iterator temp;
    list<char>::iterator cursor;

    cin >> input_string;
    cin >> input_count;
    cursor = list_input.end();
    for (int i = 0; i < input_string.size(); ++i) {
        list_input.push_back(input_string[i]);
    }
    for (int i = 0; i < input_count; i++) {
        cin >> input_char;
        if (input_char == 'L' && cursor != list_input.begin())
            cursor--;
        else if (input_char == 'D' && cursor != list_input.end())
            cursor++;
        else if (input_char == 'B') {
            if (cursor != list_input.begin()) {
                temp = --cursor;
                ++cursor;
                list_input.erase(temp);
            }
        }
        else if (input_char == 'P') {
            cin >> input_char;
            list_input.insert(cursor,input_char);
        }
    }
    for (list<char>::iterator it = list_input.begin(); it != list_input.end(); it++) {
        cout << *it;
    }
    return (0);
}
