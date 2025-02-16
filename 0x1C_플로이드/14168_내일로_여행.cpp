//
// Created by 서정윤 on 2025. 2. 16. 오후 7:11
//
#include <bits/stdc++.h>

using namespace std;
unordered_set<string> means = {"S-Train", "V-Train", "ITX-Saemaeul", "ITX-Cheongchun", "Mugunghwa"};
float use_ticket[100][100];
float not_use_ticket[100][100];
int travel_order[200];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R, M, K;
    unordered_map<string, int> city;
    string input;
    cin >> N >> R;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        city[input] = i;
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> input;
        travel_order[i] = city[input];
    }
    for (int i = 0; i < N; ++i) {
        fill(use_ticket[i], use_ticket[i] + N, 0x7fffffff/2);
        fill(not_use_ticket[i], not_use_ticket[i] + N, 0x7fffffff/2);
        use_ticket[i][i] = 0;
        not_use_ticket[i][i] = 0;
    }
    cin >> K;
    float rate = 0, cost;
    string u, v;
    for (int i = 0; i < K; ++i) {
        cin >> input;
        if (means.find(input) == means.end()) {
            rate = 0;
        } else if (input == "S-Train" || input == "V-Train")
            rate = 50;
        else
            rate = 100;
        cin >> u >> v >> cost;
        int city_u = city[u];
        int city_v = city[v];
        float use_ticket_cost = cost * (100 - rate) / 100;
        if (use_ticket[city_u][city_v] > use_ticket_cost) {
            use_ticket[city_u][city_v] = use_ticket_cost;
            use_ticket[city_v][city_u] = use_ticket_cost;
        }
        if (not_use_ticket[city_u][city_v] > cost) {
            not_use_ticket[city_u][city_v] = cost;
            not_use_ticket[city_v][city_u] = cost;
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (use_ticket[i][j] > use_ticket[i][k] + use_ticket[k][j])
                    use_ticket[i][j] = use_ticket[i][k] + use_ticket[k][j];
                if (not_use_ticket[i][j] > not_use_ticket[i][k] + not_use_ticket[k][j])
                    not_use_ticket[i][j] = not_use_ticket[i][k] + not_use_ticket[k][j];
            }
        }
    }
    float total_use = 0, total_not_use = 0;
    int cur = travel_order[0];
    for (int i = 1; i < M; ++i) {
        int next = travel_order[i];
        total_use += use_ticket[cur][next];
        total_not_use += not_use_ticket[cur][next];
        cur = next;
    }
    cout << (total_use + R < total_not_use ? "Yes" : "No");
}