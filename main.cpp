#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "PDM.h"

using namespace std;

int main()
{
    string nomeInstacia = "instancia.txt";
    srand(1); // semente fixa
    PDM pdm(nomeInstacia);

    vector<int> somaIndicesGulosa = pdm.geraSolucaoGulosaSomaIndices();
    //vector<int> aleatoria = pdm.geraSolucaoAleatoria();
    //vector<int> mediaIndicesGulosa = pdm.geraSolucaoGulosaMediaIndices();

    cout << endl;
    cout << endl;

    /*cout << "Solucao Gulosa (soma dos indices): " << endl;
    pdm.imprimeSolucao(somaIndicesGulosa);

    cout << "Funcao de avaliacao: " << pdm.funcaoAvaliacao(somaIndicesGulosa) << endl;

    cout << endl;

    cout << "Solucao Gulosa (media dos indices): " << endl;
    pdm.imprimeSolucao(mediaIndicesGulosa);

    cout << "Funcao de avaliacao: " << pdm.funcaoAvaliacao(mediaIndicesGulosa) << endl;

    cout << endl;

    cout << "Solucao Aleatoria: " << endl;
    pdm.imprimeSolucao(aleatoria);

    cout << "Funcao de avaliacao: " << pdm.funcaoAvaliacao(aleatoria) << endl;

    cout << endl;*/

    return 1;
}