#include "PDM.h"

PDM::PDM(string nomeArq) : nomeArq(nomeArq)
{
    //abrir arquivo
    f = ifstream(nomeArq);

    if (!f.is_open())
        cout << "ERRO AO ABRIR ARQUIVO" << nomeArq << "!\n"
             << endl;

    //ler n. de linhas
    f >> N;

    //selecionar o n. de elementos a serem escolhidos
    f >> M;

    cout << "N: " << N << "\tM: " << M << "\n"
         << endl;

    int total = ((N * N) - N) / 2; // total matriz

    matrizDist = vector<vector<double>>(N, vector<double>(N));
    solucao = vector<int>(M);

    for (int i = 0; i < total; i++)
    {
        double x, y;
        f >> x;
        f >> y;
        f >> val;
        matrizDist[x][y] = val;
        matrizDist[y][x] = val;
    }

    // imprimindo matriz Dist
    cout << "Matriz de distancias: " << endl;

    cout << endl;
    for (int j = 0; j < N; j++)
    {
        cout << "[" << j << "] ";
        for (int i = 0; i < N; i++)
        {
            cout << matrizDist[i][j] << ' ';
        }
        cout << endl;
    }
}

vector<int> PDM::geraSolucaoAleatoria()
{
    for (int i = 0; i < N; i++)
        solucao[i] = i;

    random_shuffle(solucao.begin(), solucao.end());

    return solucao;
}

vector<int> PDM::geraSolucaoGulosaSomaIndices()
{
    vector<pair<int, double>> LC; // lista de candidatos

    vector<int> distancias(N);

    // soma as distancias
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            distancias[i] += matrizDist[i][j]; // somatorio distancias linhas
        }
        LC.push_back(make_pair(i,distancias[i]));
    }
    
    // ordenar de acordo com a distancia
    sort(LC.begin(), LC.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    for (int i = 0; i < int(LC.size()); i++)
         cout << LC[i].first << " " << LC[i].second << endl; 
    
    for (int i = 0; i < M; i++) {
        solucao[i] = LC[i].first;
        cout << " " << solucao[i];
    }

    return solucao;
}

void PDM::imprimeSolucao(vector<int> &solucao)
{
    cout << "[ ";
    for (int i = 0; i < N; i++)
        cout << solucao[i] << ", ";
    cout << "]" << endl;
}

double PDM::funcaoAvaliacao(vector<int> &solucao)
{
    double fitness = 0;

    for (int i = 0; i < N; i++) {

    
    for (int j = i + 1; j < N; j++){
            fitness += matrizDist[solucao[i]][solucao[j]];
            cout << i << " " << j << "  " << fitness << endl;
    }

    }

    /*for (int i = 0; i < M - 1; i++)
        for (int j = i + 1; j < M; j++)
            fitness += matrizDist[solucao[i]][solucao[j]];*/

    return fitness;
}

PDM::~PDM()
{
    f.close();
}