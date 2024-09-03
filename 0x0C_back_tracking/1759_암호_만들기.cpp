//
// Created by 서정윤 on 2024. 9. 2..
//
#include <iostream>
#include <algorithm>

using namespace std;
int L, C;
char input[16];
char seq[16];
bool issued[16];


bool check_rule() {
    int consonant = 0, vowel = 0;
    for (int i = 0; i < L; ++i) {
        if (seq[i] == 'a' || seq[i] == 'i' || seq[i] == 'o' || seq[i] == 'u' || seq[i] == 'e')
            vowel += 1;
        else
            consonant += 1;
        if (consonant >= 2 && vowel >= 1)
            return true;
    }
    return false;
}

void recursive_comb(int n, int ptr) {
    if (n == L) {
        if (check_rule())
            cout << seq << '\n';
        return ;
    }

    for (int i = ptr; i < C; ++i) {
        if (issued[i])
            continue ;

        seq[n] = input[i];
        issued[i] = true;
        recursive_comb(n + 1, i);
        issued[i] = false;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;

    for (int i = 0; i < C; ++i) {
        cin >> input[i];
    }
    sort(input, input + C);

    recursive_comb(0, 0);

    return 0;
}