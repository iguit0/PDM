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

    int total = ((N*N)-N)/2; // total matriz

    matrizDist = vector<vector<double>>(N,vector<double>(N));
    solucao = vector<int>(N);

    for (int i = 0; i < total; i++)
    {
        double x,y;
        f >> x;
        f >> y;
        f >> val;
        matrizDist[x][y] = val;
        matrizDist[y][x] = val;
    }


    // imprimindo matriz Dist
    /*for(int j=0;j<25;j++) {
        for(int i=0;i<25;i++) {
            cout << matrizDist[i][j] << ' ';
        }
        cout << endl;      
    }*/
}

vector<int> PDM::geraSol() {
    int valor;
    
    for(int i=0;i<N;i++) {
        valor = (rand()%2); // gerando 0's e 1's
        solucao[i] = valor;
    }

    return solucao;
}

void PDM::imprimeMatrizDist(vector<vector<double>> &matrizDist) {
     for(int j=0;j<N;j++) {
        for(int i=0;i<N;i++) {
            cout << matrizDist[i][j] << ' ';
        }
        cout << endl;
    }
}

void PDM::imprimeSolucao(vector<int> &solucao) {
    cout << "\t\t*** IMPRIMINDO SOLUCAO ***" << endl;
	cout << "[ ";
	for (int i = 0; i < N; i++)
		cout << solucao[i] << ", ";
	cout << "]" << endl;
}

double PDM::funcaoAvaliacao(vector<int> &sol) {
    double soma = 0;

    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            soma += matrizDist[i][j] * sol[i] * sol[j];

	return soma;
}

PDM::~PDM()
{
    f.close();
}