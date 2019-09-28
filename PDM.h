#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class PDM
{
public:
    ifstream f;     // Objeto p/ leitura de arquivos
    string nomeArq; // nome da instancia

    PDM(string nomeArq); // construtor e destrutor
    virtual ~PDM();

    // ler n. de linhas
    int N;

    //selecionar o n. de elementos a serem escolhidos
    int M;

    double val;

    //matriz de distancias
    vector<vector<double>> matrizDist;
};