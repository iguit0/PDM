#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "PDM.h"

using namespace std;

int main()
{
    srand(1); // semente fixa
    PDM pdm("SOM-a_1_n25_m2.txt");

    vector<int> aleatoria = pdm.geraSol();

    pdm.imprimeSolucao(aleatoria);

    double avaliacao = pdm.funcaoAvaliacao(aleatoria);
    //cout << avaliacao << endl;

    return 1;
}