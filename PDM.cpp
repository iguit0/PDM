#include "PDM.h"
using namespace std;

PDM::PDM(string nomeArq) : nomeArq(nomeArq){
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
    solucao = vector<int>(N);

    for (int i = 0; i < total; i++)
    {
        double x, y;
        f >> x;
        f >> y;
        f >> val;
        matrizDist[x][y] = val;
        matrizDist[y][x] = val;
    }

    distanciaMaximaElementos = distanciaElementos(); // vetor de soma das distancia dos elementos
}

vector<int> PDM::descidaCompletaTroca(vector<int> &solucao, double foSol) {
    double foBest, fo;
    int posI, posJ, swap;
    foBest = foSol;
    bool melhora = false;
    do {
        melhora = false;

        for (int i = 0; i < M; i++) {
            for (int j = M; j < N; j++) {
                swap = solucao[i];
                solucao[i] = solucao[j];
                solucao[j] = swap;
                fo = funcaoAvaliacao(solucao);
                if (fo > foBest) {
                    posI = i;
                    posJ = j;
                    foBest = fo;
                    melhora = true;
                }
                swap = solucao[j];
                solucao[j] = solucao[i];
                solucao[i] = swap;
            }
        }
        if (melhora) {
            swap = solucao[posI];
            solucao[posI] = solucao[posJ];
            solucao[posJ] = swap;
        }
    } while (melhora);

    return solucao;
}
vector<int> PDM::descidaCompletaTroca2P(vector<int> &solucao, double foSol)
{
    vector<int> solCorrente = solucao;
    double melhorFo = foSol;
    int posI = 0, posI2 = 0, posJ = 0, aux, posJ2 = 0, aux2;
    bool melhorou = false;

    do {
        melhorou = false;

        for (int i = 0; i < M; i++) {
            for (int j = M; j < solCorrente.size(); j++) {
                if (j + 1 < solCorrente.size() && i + 1 < M) {
                    //aplico a troca
                    aux = solCorrente[i];
                    aux2 = solCorrente[i + 1];
                    solCorrente[i] = solCorrente[j];
                    solCorrente[i + 1] = solCorrente[j + 1];
                    solCorrente[j] = aux;
                    solCorrente[j + 1] = aux2;

                    //avalio a solucao
                    double foSolCorrente = funcaoAvaliacao(solCorrente);

                    //guardo a melhor fo e o melhor movimento
                    if (foSolCorrente > melhorFo) {
                        melhorFo = foSolCorrente;
                        posI = i;
                        posI2 = i + 1;
                        posJ = j;
                        posJ2 = j + 1;
                        melhorou = true;
                    }

                    //desfaÃ§o a troca
                    aux = solCorrente[i];
                    aux2 = solCorrente[i + 1];
                    solCorrente[i] = solCorrente[j];
                    solCorrente[i + 1] = solCorrente[j + 1];
                    solCorrente[j] = aux;
                    solCorrente[j + 1] = aux2;
                }
            }
        }

        if (melhorou) {
            int aux = solCorrente[posI];
            int aux2 = solCorrente[posI2];
            solCorrente[posI] = solCorrente[posJ];
            solCorrente[posI2] = solCorrente[posJ2];
            solCorrente[posJ] = aux;
            solCorrente[posJ2] = aux2;
        }

    } while (melhorou);

    return solCorrente;
}

vector<pair<int, double>> PDM::distanciaElementos() {
    vector<pair<int, double>> LE; // lista de elementos
    vector<int> distancias(N);    // distancia somada de cada elemento para todos.

    // soma as distancias
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            distancias[i] += matrizDist[i][j]; // somatorio distancias linhas
        }
        LE.push_back(make_pair(i, distancias[i]));
    }

    return LE;
}
vector<int> PDM::geraSolucaoAleatoria() {
    int x;
    for (int i = 0; i < N; i++) {
        solucao[i] = i;
    }
    random_shuffle(solucao.begin(), solucao.end());

    return solucao;
}

vector<int> PDM::geraSolucaoGulosaSomaIndices() {
    vector<pair<int, double>> LC = distanciaMaximaElementos; // lista de candidatos

    // ordena
    sort(LC.begin(), LC.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    cout << "\nVetor Solução Soma Indices: ";
    for (int i = 0; i < N; i++) {
        solucao[i] = LC[i].first;
        cout << " " << solucao[i];
    }

    return solucao;
}

vector<int> PDM::geraSolucaoSemiGulosa() {

    vector<pair<int, double>> LC = distanciaMaximaElementos; // lista de candidatos
    int posA = rand() % LC.size();
    solucao[0] = LC[posA].first;
    LC.erase(LC.begin() + posA);


    // ordena
    sort(LC.begin(), LC.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    for (int i = 1; i < LC.size(); i++) {
        solucao[i] = LC[i].first;
    }
    cout << "\nVetor Solução Semi Gulosa : " << endl
         << endl;
    for (int i = 0; i < N; i++) {
        cout << " " << solucao[i];
    }
    cout << endl;

    return solucao;
}

vector<int> PDM::descidaPrimeiroTroca(vector<int> &solucao, double foSol) {
    vector<int> solCorrente = solucao;

    double melhorFo = foSol;
    int posI = 0, posJ = 0;

    bool melhorou = false;

    do {
        melhorou = false;

        for (int i = 0; i < solCorrente.size() - 1; i++) {
            for (int j = 1; j < solCorrente.size(); j++) {
                // aplico troca
                int aux = solCorrente[i];
                solCorrente[i] = solCorrente[j];
                solCorrente[j] = aux;

                // avalio solucao
                double foSolCorrente = funcaoAvaliacao(solCorrente);

                // guardo a melhor FO e o melhor movimento
                if (foSolCorrente > melhorFo) {
                    melhorFo = foSolCorrente;
                    melhorou = true;
                    break;
                }
                else {
                    // desfaz troca
                    aux = solCorrente[i];
                    solCorrente[i] = solCorrente[j];
                    solCorrente[j] = aux;
                }
            }

            if (melhorou)
                break;
        }

    } while (melhorou);

    return solCorrente;
}

vector<int> PDM::shake(vector<int> &solucao, double tamanho) {
    int aux, r, tam = static_cast<int>(M * tamanho);
    vector<pair<int, int>> LC;

    for (int i = 0; i < (N - M); i++) {
        LC.push_back(make_pair(i + M, solucao[i + M]));
    }

    for (int i = 0; i < tam; i++) {
        r = rand() % LC.size();
        aux = solucao[i];
        solucao[i] = LC[r].second;
        solucao[LC[r].first] = aux;
        LC.erase(LC.begin() + r);
    }

    return solucao;
}
vector<int> PDM::buscaVizinhacaVariavel(vector<int> &sol, double foSol, double taxaShake, int iteracoes) {
    int cont = 0;
    vector<int> solCorrente = sol;
    double bestFo = foSol, foCorrente;
    do {
        cout << "iter: " << cont << endl;
        solCorrente = shake(solCorrente, taxaShake);
        foCorrente = funcaoAvaliacao(solCorrente);
        solCorrente = descidaVizinhacaVariavel(solCorrente, foCorrente);
        foCorrente = funcaoAvaliacao(solCorrente);
        if (bestFo < foCorrente) {
            cout << "  melhorou de " << bestFo << " para  " << foCorrente << endl;
            sol = solCorrente;
            bestFo = foCorrente;
        }
        cont++;
    } while (cont < iteracoes);

    return sol;
}

vector<int> PDM::descidaVizinhacaVariavel(vector<int> &sol, double foSol) {
    int k = 1, r = 2;

    double melhorSolucao = foSol, fitnessCorrente;
    vector<int> solucao = sol, vetorCorrente;
    vector<int> melhorSOl = sol;
    int i = 0;
    while (k <= r) {
        if (k == 1) {

            vetorCorrente = descidaCompletaTroca2P(solucao, melhorSolucao);
            //vetorCorrente=descidaCompletaTroca(solucao, melhorSolucao);
            fitnessCorrente = funcaoAvaliacao(vetorCorrente);
            if (fitnessCorrente > melhorSolucao) {
                solucao = vetorCorrente;
                melhorSolucao = fitnessCorrente;
                k = 1;
            }
            else {
                k++;
            }
        }

        if (k == 2) {

            vetorCorrente = descidaPrimeiroTroca(solucao, funcaoAvaliacao(solucao));

            fitnessCorrente = funcaoAvaliacao(vetorCorrente);
            if (fitnessCorrente > melhorSolucao) {
                solucao = vetorCorrente;
                melhorSolucao = fitnessCorrente;
                k = 1;
            }
            else {
                k++;
            }
        }
    }

    return solucao;
}

vector<int> PDM::multiStart(vector<int> &sol, double foSol) {
    double melhorFo = foSol, correnteFo = foSol;
    int numeroGeracoesSemMelhora = 12;
    int contador;
    vector<int> melhorSol = sol, solCorrente = geraSolucaoAleatoria();

    while (contador < numeroGeracoesSemMelhora) {
        solCorrente = descidaPrimeiroTroca(solCorrente, correnteFo);
        correnteFo = funcaoAvaliacao(solCorrente);
        if (correnteFo > melhorFo) {
            melhorSol = solCorrente;
            melhorFo = correnteFo;
        }
        else {
            cout << "iterações sem melhora: " << contador << endl;
            solCorrente = geraSolucaoAleatoria();
            contador++;
        }
    }

    return melhorSol;
}

void PDM::imprimeSolucao(vector<int> &solucao) {
    cout << "[ ";
    for (int i = 0; i < M; i++)
        cout << solucao[i] << ", ";
    cout << " | ";
    for (int i = M; i < N; i++)
        cout << solucao[i] << ", ";
    cout << "]" << endl;
}

double PDM::funcaoAvaliacao(vector<int> &solucao) {
    double fitness = 0;

    for (int i = 0; i < M - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            fitness += matrizDist[solucao[i]][solucao[j]];
        }
    }

    return fitness;
}

PDM::~PDM() {
    f.close();
}