#include <iostream>
#include <vector>

using namespace std;

string homens_sao_mais_estressados_que_mulheres(vector<int> fila) {
    int somar_homens {}, somar_mulheres {}, homens {}, mulheres {};
    for (int vet : fila) {
        if (vet > 0) {
            somar_homens += abs (vet);
            homens =+ 1;
        } else {
            somar_mulheres += abs (vet);
            mulheres =+ 1;
        }
    }
    return ((somar_homens/homens) > (somar_mulheres/mulheres)) ? "Sim" : "Nao";
}

string qual_metade_eh_mais_estressada(vector<int> fila) {
    int soma1 {}, soma2 {}, size {(int) fila.size()};
    for (int i = 0; i < (size/2); i++)
        soma1 += abs (fila[i]);
    for (int i = (size/2); i < size; i++)
        soma2 += abs (fila[i]);
    if (soma1 == soma2)
        return "Empate";
    return (soma1 > soma2) ? "Primeira" : "Segunda";
}

string mais_homens_ou_mulheres(vector<int> fila) {
    int contar_mulheres {}, contar_homens {};
    for (int vet : fila)
        if (vet > 0)
            contar_homens += 1;
        else
            contar_mulheres += 1;
    if (contar_homens == contar_mulheres)
        return "Empate";
    return (contar_homens > contar_mulheres) ? "Homens" : "Mulheres";
}

int calcular_stress_medio(vector<int> fila) {
    int soma {};
    for (int vet : fila){
        soma += abs (vet);
    }
    return (soma / fila.size());
}

int posicao(vector<int> fila, int comeco, int comparar) {
    int posi {}, size {(int)fila.size()};
    for (int i = comeco; i < size; i++)
        if (fila[i] <= comparar){
            comparar = fila[i];
            posi = i;
        }
    return posi;
}

int procurar_pos_menor_apartir(vector<int> fila, int comeco) {
    int comparar {fila[comeco]}, posi {};
    posi = posicao(fila, comeco, comparar);
    return posi;
}

int procurar_pos_menor(vector<int> fila) {
    int comparar {fila[0]}, posi {};
    posi = posicao(fila, 0, comparar);
    return posi;
}

int procurar_menor(vector<int> fila){
    int comparar {fila[0]};
    for (int vet : fila)
        if (vet < comparar)
            comparar = vet;
    return comparar;
}

int procurar_apartir(vector<int> fila, int x, int comeco) {
    int size {(int)fila.size()};
    for (int i = comeco; i < size; i++)
        if (fila[i] == x)
            return i;
    return -1;
}

int procurar(vector<int> fila, int x) {
    int size {(int)fila.size()};
    for (int i = 0; i < size; i++)
        if (fila[i] == x)
            return i;
    return -1;
}

int procurar_melhor_se(vector<int> vetor)
{
    int contador {-1}, mais_calmo{100};
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0 && vetor[i] < mais_calmo) {
            contador = i;
            mais_calmo = vetor[i];
        }
    }
    return contador;
}

int contar(vector<int> fila, int x) {
    int cont {};
    for (int vet : fila)
        cont += (vet == x) ? 1 : 0;
    return cont;
}

bool existe(vector<int> fila, int x) {
    for (int vet : fila)
        return (vet == x) ? true : false;
    return false;
}

int main() {
    /*Existe*/
    cout << "Teste Existe:" << endl;
    cout << existe({-1, -50, -99}, -1) << endl;
    cout << existe({-1, -50, -99}, 10) << endl;
    cout << endl;
    /*Contar*/
    cout << "Teste Contar:" << endl;
    cout << contar({-1, -50, -1, -99}, -1) << endl;
    cout << contar({-1, -50, -1, -99}, 10) << endl;
    cout << endl; 
    /*Procurar*/
    cout << "Teste Procurar:" << endl;
    cout << procurar({-1, -50, -1, -99}, -50) << endl;
    cout << procurar({-1, -50, -1, -99}, 10) << endl;
    cout << endl;   
    /*Procurar Apartir*/
    cout << "Teste Procurar Apartir:" << endl;
    cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 4) << endl;
    cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 0) << endl;
    cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 3) << endl;
    cout << endl;   
    /*Procurar Menor*/
    cout << "Teste Procurar Menor:" << endl;
    cout << procurar_menor({5, 3, -1, -50, -1, -99}) << endl;
    cout << endl;
    /*Procurar Menor Posição*/
    cout << "Teste Procurar Menor Posição:" << endl;
    cout << procurar_pos_menor({5, 3, -1, -50, -1, -99}) << endl;
    cout << endl;
    /*Procurar Menor Posição Apartir*/
    cout << "Teste Procurar Menor Posição Apartir:" << endl;
    cout << procurar_pos_menor_apartir({5, 3, -1, -50, -1, 10}, 3) << endl;
    cout << endl; 
    /*Procurar Posição do Homem mais Calmo*/
    cout << "Teste Posição Homem mais Calmo:" << endl;
    cout << procurar_melhor_se({5, 3, -1, -50, -1, -99}) << endl;
    cout << procurar_melhor_se({-1, -50, -1, -99}) << endl;
    cout << endl;
    /*Calcular Stress Medio*/
    cout << "Teste Stress Medio:" << endl;
    cout << calcular_stress_medio({5, 3, -1, -50, -1, -99}) << endl;
    /*Mais Homens ou Mulheres*/
    cout << "Teste Mais Homens ou Mulheres:" << endl;
    cout << mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99}) << endl;
    cout << endl;
    /*Metade Mais Estressada*/
    cout << "Teste Metade Mais Estressada:" << endl;
    cout << qual_metade_eh_mais_estressada({5, 3, -1, -50, -1, -99}) << endl;
    cout << qual_metade_eh_mais_estressada({50, 98, 2, -50, -1, -99}) << endl;
    cout << qual_metade_eh_mais_estressada({-51, 99, 1, -50, -1, -99}) << endl;
    cout << endl;
    /*Homens mais Estressados que Mulheres*/
    cout << "Teste se Homens e mais estressado que as Mulheres:" << endl;
    cout << homens_sao_mais_estressados_que_mulheres({5, 3, -1, -50, -1, -99}) << endl;
}