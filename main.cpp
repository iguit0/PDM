#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "PDM.h"

using namespace std;

int main()
{
    string nomeInstacia = "SOM-b_17_n500_m50.txt";
    srand(0); // semente fixa
    PDM pdm(nomeInstacia);

    vector<int> semigulosa = pdm.geraSolucaoSemiGulosa();
    vector<int> somaIndicesGulosa = pdm.geraSolucaoGulosaSomaIndices();
    vector<int> aleatoria = pdm.geraSolucaoAleatoria();

    cout << "\n\n\nSolucao Gulosa SOMA DOS INDICES: " << endl;
    pdm.imprimeSolucao(somaIndicesGulosa);

    cout << "\nFuncao de avaliacao: Soma dos Indices \n" << pdm.funcaoAvaliacao(somaIndicesGulosa) << endl;

    cout << "\n\n\nSolucao Gulosa SEMI GULOSA: " << endl;
    pdm.imprimeSolucao(semigulosa);

    cout << "\nFuncao de avaliacao: SEMI Gulosa \n" << pdm.funcaoAvaliacao(semigulosa) << endl;

    cout << "\nSolucao Aleatoria: " << endl;
    pdm.imprimeSolucao(aleatoria);

    cout << "\nFuncao de avaliacao: Aleatória \n" << pdm.funcaoAvaliacao(aleatoria) << endl;

    cout << "\nSolucao apos descida reduzida " << endl;
    aleatoria = pdm.descidaReduzida(aleatoria);

    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos descida reduzida \n" << pdm.funcaoAvaliacao(aleatoria) << endl;

    cout << "\nSolucao apos descida completa troca " << endl;
    //aleatoria=pdm.geraSolucaoAleatoria();*/

    /*aleatoria = pdm.descidaCompletaTroca(aleatoria, pdm.funcaoAvaliacao(aleatoria));
    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos descida completa troca  \n" <<pdm.funcaoAvaliacao(aleatoria) << endl;*/
    
    cout << "\nSolucao apos VND" << endl;
    
    aleatoria = pdm.descidaVizinhacaVariavel(aleatoria, pdm.funcaoAvaliacao(aleatoria));
    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos descida completa troca  \n" << pdm.funcaoAvaliacao(aleatoria) << endl;

    // MULTISTART
    cout << "\nSolucao apos multistart c/ VND" << endl;
    
    aleatoria = pdm.multiStart(aleatoria, pdm.funcaoAvaliacao(aleatoria));
    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos descida completa troca: " << pdm.funcaoAvaliacao(aleatoria) << endl;

    return 1;
}