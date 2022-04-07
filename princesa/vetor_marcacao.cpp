#include <iostream>
#include <vector>

using namespace std;

void mostraVetor(vector<int> pessoas, int espada) {
    for (int i = 0; i < (int) pessoas.size(); i++) {
        if (i == espada%(int)pessoas.size()) 
            cout << pessoas[i] << "> ";
        else 
            cout << pessoas[i] << " ";
    }
    cout << endl; 
}

int procurar_vivo(vector<int>& v, int pos){
    do{
        pos = (pos + 1);
        if (pos == v.size()){
            pos = 0;
        }
    } while (v[pos] == false);
    return pos;
}


int main(){
    int size {};
    cout << "Digite a quantidade de pessoas:";
    cin >> size;
    int espada{};
    cout << "Digite quem comeca com a espada:";
    cin >> espada;
    vector<int> pessoas(size, true);
    espada -=1;
    int qtd = pessoas.size() - 1;
    while(qtd--){
        mostraVetor(pessoas, espada);
        int pos = procurar_vivo(pessoas, espada);
        pessoas[pos] = false;
        espada = procurar_vivo(pessoas, espada);
    }

}