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
    cout << endl
		 << "Matriz de distancias: " << endl;
    for(int x=0;x<N;x++){
        if(x==0) cout << ' ';
        cout << x << ' ';
    }
    cout << endl;
    cout << endl;
    for(int j=0;j<N;j++) {
        cout << "[" << j << "] ";
        for(int i=0;i<N;i++) {
            cout << matrizDist[i][j] << ' ';
        }
        cout << endl;      
    }
}

vector<int> PDM::geraSolucaoAleatoria() {
    
    for(int i=0;i<N;i++) {
        solucao[i] = i;
    }

    random_shuffle(solucao.begin(), solucao.end());

    return solucao;
}

vector<int> PDM::geraSolucaoGulosa() {
    vector<int> solucao;

    vector<int> LC; // lista de candidatos

    // preenchendo lista de candidatos
    for(int i=0;i<N;i++)
        LC.push_back(i);

    

    return LC;
}

double PDM::retornaMaiorDist(int elementoAtual, vector<int> &LC) {
	// armazena a posicao com maior distancia
	double maiorPos = 0;

    // armazena a maior distancia
    double maiorDist = matrizDist[0][LC[0]];

    // busca pelo elemento que possui maior diversidade (distancia)
    for(int i=0;i<int(LC.size());i++) {
        if(matrizDist[elementoAtual][LC[i]] > maiorDist) {
            cout << i;
            maiorPos = i;
        }
    }

	return maiorPos;
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

    for(int i=0;i<M-1;i++)
        for(int j=i+1;j<M;j++)
            soma += matrizDist[sol[i]][sol[j]];

	return soma;
}

PDM::~PDM()
{
    f.close();
}