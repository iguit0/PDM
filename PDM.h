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

    // funcao de avaliacao
    double funcaoAvaliacao(vector<int> &solucao);

    // solucao
    vector<int> solucao;

    // imprimir solucao
    void imprimeSolucao(vector<int> &sol);

    // gerar Solucao Aleatoria
    vector<int> geraSolucaoAleatoria();

    // gerar solucao gulosa (soma indices)
    vector<int> geraSolucaoGulosaSomaIndices();

    // gerar solucao gulosa (media indices)
    vector<int> geraSolucaoGulosaMediaIndices();

    // retorna a posicao do elemento correspondente a soma dos indices de diversidade
    double retornaMaiorDist(int elementoAtual, vector<int> &LC);

    // retorna a posicao do elemento media dos indices de diversidade
    double retornaMediaDist(int elementoAtual, vector<int> &LC);
};