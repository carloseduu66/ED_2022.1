#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void mostrar(vector<string> mapa){
    for (auto linha : mapa)
        cout << linha << '\n';
    getchar();
}

void queimar(vector<string>& mapa, int lpos, int cpos){
    int nl = mapa.size();
    int nc = mapa[0].size();
    if (lpos < 0 || lpos >= nl || cpos < 0 || cpos >= nc)
        return;
    if (mapa[lpos][cpos] != '#')
        return;    
    mapa[lpos][cpos] = 'o';
    mostrar(mapa);

    queimar(mapa, lpos, cpos - 1);
    queimar(mapa, lpos - 1, cpos);
    queimar(mapa, lpos, cpos + 1);
    queimar(mapa, lpos + 1, cpos);
}

int main(){
    vector<string> mapa;
    ifstream arq("input.txt");
    int nl{ }, nc{ }, li{ }, ci{ };
    arq >> nl >> nc >> li >> ci;
    for (int i = 0; i < nl; i++){
        string linha;
        arq >> linha;
        mapa.push_back(linha);
    }
    
    mostrar(mapa);
    queimar(mapa, li, ci);
}