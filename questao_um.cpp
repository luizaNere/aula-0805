#include <iostream>
#include <iomanip>
#include <math.h>
#include <locale.h>

#define MAXIMO 100

using namespace std;

float aritmetica(float vetor[], int tamanho) {
    float total = 0;
    for(int i = 0; i <= tamanho; i++) {
        total += vetor[i];    
    }
    return (total/tamanho);
}

float harmonica(float vetor[], int tamanho) {
    float soma = 0;
    for(int i = 0; i< tamanho; i++) {
        soma += (1/vetor[i]);
    }
    return (tamanho/soma);
}

float geometrica(float vetor[], int tamanho) {
    float produto = 1;
    for(int i = 0; i< tamanho; i++) {
        produto *= vetor[i];
    }
    return (pow(produto, (1.0/tamanho)));
}

float maiorValor(float vetor[], int tamanho) {
    float maior, antes = 0;
    for(int i = 0; i<tamanho; i++) {
        if(vetor[i] > antes) {
            maior = vetor[i];
        }
        antes = vetor[i];
    }
    return maior;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    cout << fixed << setprecision(3);
    int n, i;
    float valor, numeros[MAXIMO];

    do {
        cout << "Digite o valor de N: ";
        cin >> n;
    } while((n<1) || (n > 100));

    for(i = 0; i < n; i++){
        do{
            cout << "\n[" << i+1 << "] Digite um valor: ";
            cin >> valor;
        }while (valor <= 0);
        numeros[i] = valor;
    }
    
    cout << "\nMédia aritmética: " << aritmetica(numeros, n);
    cout << "\nMédia geométrica: " << geometrica(numeros, n);
    cout << "\nMédia harmônica: " << harmonica(numeros, n);
    cout << "\nMaior valor: " << maiorValor(numeros, n) << endl;
}