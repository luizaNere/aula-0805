#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string transcricao(string dna, int tamanho) {
    string resp;
    for(int i = 0; i < tamanho; i++) {
        if (dna[i] == 'A') {
            resp += 'U';
        } else if (dna[i] == 'G') {
            resp += 'C';
        } else if (dna[i] == 'C') {
            resp += 'G';
        } else if (dna[i] == 'T') {
            resp += 'A';
        } else {
            resp += dna[i];
        }
    }
    return resp;
}

bool startCodon(string rna, int tamanho) {
    bool tem = false;

    if (rna[0] == 'A' && rna[1] == 'U' && rna[2] == 'G'){
        tem = true;
    }

    return tem;
}
bool stopCodon(string rna, int tamanho) {
    bool tem = false;

    if (rna[tamanho-3] == 'U' && rna[tamanho-2] == 'A' && rna[tamanho-1] == 'G'){
        tem = true;
    } else if (rna[tamanho-3] == 'U' && rna[tamanho-2] == 'A' && rna[tamanho-1] == 'A') {
        tem = true;
    } else if (rna[tamanho-3] == 'U' && rna[tamanho-2] == 'G' && rna[tamanho-1] == 'A') {
        tem = true;
    }

    return tem;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    string dna, rna;
    int tamanho, u=0, a=0, g=0, c=0;
    bool start, stop;
    cout << "\nDigite a sequência de DNA: ";
    getline(cin, dna);
    tamanho = dna.size();
    rna = transcricao(dna, tamanho);
    for(int i = 0; i < tamanho; i++) {
        if(rna[i] == 'U') {
            u++;
        } else if (rna[i] == 'A') {
            a++;
        } else if (rna[i] == 'G') {
            g++;
        } else if (rna[i] == 'C') {
            c++;
        }
    }

    start = startCodon(rna, tamanho);
    stop = stopCodon(rna, tamanho);

    cout << "\nSequência de DNA: " << dna << endl;
    cout << "\nSequência de RNA: " << rna << endl;
    cout << "\nTamanho da sequência: " << tamanho << endl;
    cout << "\nQuantidade de 'U': " << u << endl 
         << "Quantidade de 'A': " << a << endl 
         << "Quantidade de 'G': " << g << endl
         << "Quantidade de 'C': " << c << endl;

    cout << setprecision(2) << "Proporção de cada aminoácido:" << endl
         << "'U' ≈ " << (100.0*u)/tamanho << "%" << endl
         << "'A' ≈ " << (100.0*a)/tamanho << "%" << endl
         << "'G' ≈ " << (100.0*g)/tamanho << "%" << endl
         << "'C' ≈ " << (100.0*c)/tamanho << "%" << endl;
    
    if(start) {
        cout << endl << "A sequência possui start códon!" << endl;
    } else {
        cout << endl << "A sequência não possui start códon!" << endl;
    }

    if(stop) {
        cout << endl << "A sequência possui stop códon!" << endl;
    } else {
        cout << endl << "A sequência não possui stop códon!" << endl;
    }
}