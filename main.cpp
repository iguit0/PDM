#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "PDM.h"

using namespace std;

int main()
{
    string nomeArquivo = "SOM-a_1_n25_m2.txt";
    srand(1); // semente fixa
    PDM pdm(nomeArquivo);

    vector<int> aleatoria = pdm.geraSolucaoAleatoria();
    vector<int> gulosa = pdm.geraSolucaoGulosa();

    /*cout << "Solucao Gulosa gerada: " << endl;
    pdm.imprimeSolucao(gulosa);

    cout << "Funcao de avaliacao: " << pdm.funcaoAvaliacao(gulosa) << endl;*/

    cout << "Solucao gerada Aleatoriamente: " << endl;
    pdm.imprimeSolucao(aleatoria);

    cout << "Funcao de avaliacao: " << pdm.funcaoAvaliacao(aleatoria) << endl;

    return 1;
}