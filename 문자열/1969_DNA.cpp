//
// Created by 서정윤 on 2024. 11. 20. 오후 7:42
//
#include <bits/stdc++.h>

using namespace std;
//  N은 1,000보다 작거나 같은 자연수이고, M은 50
enum {
    A,
    C,
    G,
    T,
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, dna[4], distance = 0;
    char input[2001][51];
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < M; ++i) {
        int mx = 0;
        memset(dna, 0, sizeof(dna));
        for (int j = 0; j < N; ++j) {
            if (input[j][i] == 'A')
                dna[A] += 1;
            else if (input[j][i] == 'C')
                dna[C] += 1;
            else if (input[j][i] == 'G')
                dna[G] += 1;
            else
                dna[T] += 1;
        }
        mx = max({dna[A], dna[C], dna[G], dna[T]});
        if (mx == dna[A])
            cout << 'A';
        else if (mx == dna[C])
            cout << 'C';
        else if (mx == dna[G])
            cout << 'G';
        else
            cout << 'T';
        distance += N - mx;
    }
    cout << '\n' << distance;
}