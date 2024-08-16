//
// Created by 서정윤 on 8/15/24.
//
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) {
    string input;
    list<char> input_list;
    list<char>::iterator offset;
    list<char>::iterator temp;
    int count = 0;

    cin >> count;
    while (count--) {
        cin >> input;
        input_list.clear();
        offset = input_list.begin();
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '<') {
                if (offset != input_list.begin())
                    --offset;
            }
            else if (input[i] == '>'){
                if (offset != input_list.end())
                    ++offset;
            }
            else if (input[i] == '-') {
                if (offset != input_list.begin()) {
                    temp = --offset;
                    input_list.erase(temp);
                }
            }
            else {
                input_list.insert(offset, input[i]);
            }
        }
        for (list<char>::iterator it = input_list.begin(); it != input_list.end(); ++it) {
            cout << *it;
        }
        cout << "\n";
    }
    return (0);
}