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

    int total = ((N*N)-25)/2;

    matrizDist = vector<vector<double>>(25,vector<double>(25));

    for (int i = 0; i < total; i++)
    {
        double x,y;
        f >> x;
        f >> y;
        f >> val;
        matrizDist[x][y] = val;
        matrizDist[y][x] = val;
    }


    for(int j=0;j<25;j++) {
        for(int i=0;i<25;i++)
        {
            cout << matrizDist[i][j] << ' ';
            
        }
        cout << endl;
            
    }
}

PDM::~PDM()
{
    f.close();
}