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
    vector<int> somaIndicesGulosa = pdm.geraSolucaoGulosaSomaIndices();
    vector<int> mediaIndicesGulosa = pdm.geraSolucaoGulosaMediaIndices();


    cout << "Solucao Gulosa (soma dos indices): " << endl;
    pdm.imprimeSolucao(somaIndicesGulosa);

    cout << "Funcao de avaliacao: " << pdm.funcaoAvaliacao(somaIndicesGulosa) << endl;

    cout << "Solucao Gulosa (media dos indices): " << endl;
    pdm.imprimeSolucao(mediaIndicesGulosa);

    cout << "Funcao de avaliacao: " << pdm.funcaoAvaliacao(mediaIndicesGulosa) << endl;

    cout << "Solucao Aleatoria: " << endl;
    pdm.imprimeSolucao(aleatoria);

    cout << "Funcao de avaliacao: " << pdm.funcaoAvaliacao(aleatoria) << endl;

    return 1;
}