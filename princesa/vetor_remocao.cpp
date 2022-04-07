#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void mostraVetor(vector<int> &vet, int espada) {
    for (int i = 0; i < (int) vet.size(); i++) {
        if (i == espada%(int)vet.size()) 
            cout << vet[i] << "> ";
        else 
            cout << vet[i] << " ";
    }  
}
void morto(vector<int> &vet, int espada) {
    vet.erase(vet.begin()+espada);
}

int main() 
{
    int size{};
    cout << "Digite a quantidade de pessoas:";
    cin >> size;
    int pos{};
    cout << "Digete quem comeca com a espada:";
    cin >> pos;
    vector<int> vet(size);
    iota(begin(vet), end(vet), 1);
    pos = pos - 1;
    while ((int) vet.size() != 1) {
        mostraVetor(vet, pos);
        pos++;
        pos = pos % (int)vet.size();
        morto(vet, pos);
        cout<<endl;
    }

    for (auto item: vet) {
        cout << item; 
    }  
}