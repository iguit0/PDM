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

vector<int> PDM::geraSolucaoGulosaMediaIndices()
{
    vector<int> solucao;

    int elementoAtual = 0;

    vector<int> LC; // lista de candidatos

    // preenchendo lista de candidatos
    for (int i = 0; i < N; i++)
        LC.push_back(i);

    while (!LC.empty())
    {
        int pos = retornaMediaDist(elementoAtual, LC);

        solucao.push_back(LC[pos]);

        elementoAtual = LC[pos];

        LC.erase(LC.begin() + pos);
    }

    return solucao;
}

double PDM::retornaMaiorDist(int elementoAtual, vector<int> &LC)
{
    // armazena a posicao com maior distancia
    double maiorPos = 0;

    // armazena a maior distancia
    double maiorDist = matrizDist[elementoAtual][LC[0]];

    // busca pelo elemento que possui maior diversidade (distancia)
    for (int i = 0; i < int(LC.size()); i++)
    {
        if (matrizDist[elementoAtual][LC[i]] > maiorDist)
        {
            maiorDist = matrizDist[elementoAtual][LC[i]];
            maiorPos = i;
        }
    }

    return maiorPos;
}

double PDM::retornaMediaDist(int elementoAtual, vector<int> &LC)
{
    // armazena a posicao com distancia media
    double mediaPos = 0;
    double aux;
    aux = double(N * 1.0);

    double mediaDist = matrizDist[elementoAtual][LC[0]];

    for (int j = 0; j < int(LC.size()); j++)
    {
        if (matrizDist[elementoAtual][LC[j]] > mediaDist)
        {
            mediaDist = (matrizDist[elementoAtual][LC[j]]) / N;
            mediaPos = j;
        }
    }

    return mediaPos;
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

    for (int i = 0; i < M - 1; i++)
        for (int j = i + 1; j < M; j++)
            fitness += matrizDist[solucao[i]][solucao[j]];

    return fitness;
}

PDM::~PDM()
{
    f.close();
}