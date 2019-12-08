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

    vector<pair<int, double>> distanciaMaximaElementos; // vetor com a soma de distancia dos elementos

    vector<pair<int, double>> distanciaElementos(); // função que calcula a soma de distancia dos elementos

    // imprimir solucao
    void imprimeSolucao(vector<int> &sol);

    // gerar Solucao Aleatoria
    vector<int> geraSolucaoAleatoria();

    // gerar solucao gulosa (soma indices)
    vector<int> geraSolucaoGulosaSomaIndices();

    vector<int> geraSolucaoSemiGulosa();

    // gerar solucao gulosa (media indices)
    vector<int> geraSolucaoGulosaMediaIndices();
    vector<int> shake(vector<int> &solucao, double tamanho);
    vector<int> descidaCompletaTroca2P(vector<int> &solucao, double foSol);
    vector<int> descidaCompletaTroca(vector<int> &solucao, double foSol);
    vector<int> descidaPrimeiroTroca(vector<int> &solucao, double foSol);
    vector<int> descidaVizinhacaVariavel(vector<int> &sol, double foSol);
    vector<int> buscaVizinhacaVariavel(vector<int> &solucao, double foSol, double taxaShake, int iteracoes);
    vector<int> multiStart(vector<int> &sol, double foSol);
};