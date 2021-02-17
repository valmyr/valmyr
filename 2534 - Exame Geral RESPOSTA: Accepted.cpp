#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int> rank;
    int habitantes, consultas;
    while(cin >> habitantes >> consultas){
        for (int i = 0; i < habitantes; i++) {
            int pontos;
            cin >> pontos;
            rank.push_back(pontos);
        }
        sort(rank.begin(), rank.end(), [](int n1, int n2) { return n1 > n2; });
        for (int i = 0; i < consultas; i++) {
            int posicao;
            cin >> posicao;
            cout << rank[posicao - 1] << endl;
        }
        rank.clear();
    }
}
