/*
* ALUNO: IGOR LUCIO ROCHA ALVES - 3902
* DISCIPLINA: SIN 492
* PROBLEMA DA DIVERSIDADE MAXIMA - PDM
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "PDM.h"

using namespace std;

int main() {
    //string nomeInstancia = "MDG-a_1_n500_m50.txt";
    //string nomeInstancia ="SOM-b_5_n200_m20.txt";
    string nomeInstancia="MDG-b_1_n500_m50.txt";
    //string nomeInstancia ="GKD-c_2_n500_m50.txt";
    
    
    srand(1); // semente fixa
    PDM pdm(nomeInstancia);

    //vector<int> semigulosa = pdm.geraSolucaoAleatoria();
    //vector<int> somaIndicesGulosa = pdm.geraSolucaoGulosaSomaIndices();
    vector<int> aleatoria = pdm.geraSolucaoAleatoria();
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
    cout << "\nFuncao de avaliacao apos descida completa troca  \n" <<pdm.funcaoAvaliacao(aleatoria) << endl;
    cout << "\nSolucao apos VND" << endl;*/

    aleatoria = pdm.buscaVizinhacaVariavel(aleatoria, pdm.funcaoAvaliacao(aleatoria), 0.5, 20);
    //aleatoria=pdm.shake(aleatoria);
    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos VNS:  \n"
         << pdm.funcaoAvaliacao(aleatoria) << endl;
    /* cout << "\nSolucao apos multistart com  VND" << endl;
    
    aleatoria=pdm.multiStart(aleatoria, pdm.funcaoAvaliacao(aleatoria));
    pdm.imprimeSolucao(aleatoria);
    cout << "\nFuncao de avaliacao apos descida completa troca  \n" <<pdm.funcaoAvaliacao(aleatoria) << endl;
    
*/

    return 1;
}