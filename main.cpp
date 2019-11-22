#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "PDM.h"

using namespace std;

int main()
{
    string nomeInstacia = "exe.txt";
    srand(0); // semente fixa
    PDM pdm(nomeInstacia);

    //vector<int> semigulosa = pdm.geraSolucaoSemiGulosa();
    //vector<int> somaIndicesGulosa = pdm.geraSolucaoGulosaSomaIndices();
    vector<int> aleatoria = pdm.geraSolucaoGulosaSomaIndices();
    //vector<int> mediaIndicesGulosa = pdm.geraSolucaoGulosaMediaIndices();

   /* cout << "\n\n\nSolucao Gulosa (soma dos indices): " << endl;
    pdm.imprimeSolucao(somaIndicesGulosa);

    cout << "\nFuncao de avaliacao: Gulosa \n" << pdm.funcaoAvaliacao(somaIndicesGulosa) << endl;

    cout << endl;*/

 /*   cout << "\n\n\nSolucao Gulosa SEMI GULOSA: " << endl;
    pdm.imprimeSolucao(semigulosa);

    cout << "\nFuncao de avaliacao: SEMI Gulosa \n" << pdm.funcaoAvaliacao(semigulosa) << endl;

    cout << endl;

    cout << "\nSolucao Aleatoria: " << endl;
    pdm.imprimeSolucao(aleatoria);

    cout << "\nFuncao de avaliacao: Aleatória \n" << pdm.funcaoAvaliacao(aleatoria) << endl;

    cout << endl;

    cout << "\nSolucao Aleatoria: " << endl;
    pdm.imprimeSolucao(aleatoria);

    cout << "\nSolucao apos descida reduzida " << endl;
    //aleatoria=pdm.geraSolucaoAleatoria();

    aleatoria=pdm.descidaReduzida(aleatoria);
    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos descida reduzida \n" << pdm.funcaoAvaliacao(aleatoria) << endl;

    cout << "\nSolucao apos descida completa troca " << endl;
    //aleatoria=pdm.geraSolucaoAleatoria();*/

    /*aleatoria=pdm.descidaCompletaTroca(aleatoria, pdm.funcaoAvaliacao(aleatoria));
    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos descida completa troca  \n" <<pdm.funcaoAvaliacao(aleatoria) << endl;*/
   /* cout << "\nSolucao apos VND" << endl;
    
    aleatoria=pdm.descidaVizinhacaVariavel(aleatoria, pdm.funcaoAvaliacao(aleatoria));
    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos descida completa troca  \n" <<pdm.funcaoAvaliacao(aleatoria) << endl;*/
     cout << "\nSolucao apos multistart c/ VND" << endl;
    
    aleatoria=pdm.multiStart(aleatoria, pdm.funcaoAvaliacao(aleatoria));
    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos descida completa troca: " << pdm.funcaoAvaliacao(aleatoria) << endl;

    return 1;
}