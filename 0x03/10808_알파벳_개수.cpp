//
// Created by 서정윤 on 8/15/24.
//
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    string input;
    int alpha[26];
    cin >> input;

    memset(&alpha, 0, sizeof(alpha));
    for (string::iterator it = input.begin(); it != input.end(); it++)
    {
        ++alpha[*it - 'a'];
    }

    for (int i = 0; i < 26; i++)
        cout << alpha[i] << ' ';
    return (0);
}