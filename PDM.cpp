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
vector<int> PDM::descidaReduzida(vector<int> &solucao){
    double foBest, fo;
    int posI,posJ,swap;
    foBest=funcaoAvaliacao(solucao);
    bool melhora=false;
    do{
        melhora=false;
        
        for(int i=0;i<M;i++){
            for(int j=M;j<N;j++){
                swap=solucao[i];
                solucao[i]=solucao[j];
                solucao[j]=swap;
                fo=funcaoAvaliacao(solucao);
                if(fo>foBest){
                    posI=i;
                    posJ=j;
                    foBest=fo;
                    melhora=true;
                }
                swap=solucao[j];
                solucao[j]=solucao[i];
                solucao[i]=swap;
            }
        }
        if(melhora){
            swap=solucao[posI];
            solucao[posI]=solucao[posJ];
            solucao[posJ]=swap;
        }
    }while(melhora);
    
    return solucao;
    

}
vector<int> PDM::descidaCompletaTroca(vector<int> &solucao, double foSol)
{
    vector<int> solCorrente = solucao;
    double melhorFo = foSol;
    int posI = 0, posJ = 0, aux;
    bool melhorou = false;

     do
    {
        melhorou = false;

        for (int i = 0; i < solCorrente.size() - 1; i++)
        {
            for (int j = 1; j < solCorrente.size(); j++)
            {
                //aplico a troca
                aux = solCorrente[i];
                solCorrente[i] = solCorrente[j];
                solCorrente[j] = aux;

                //avalio a solucao
                double foSolCorrente = funcaoAvaliacao(solCorrente);

                //guardo a melhor fo e o melhor movimento
                if (foSolCorrente > melhorFo)
                {
                    melhorFo = foSolCorrente;
                    posI = i;
                    posJ = j;
                    melhorou = true;
                }

                //desfaÃ§o a troca
                aux = solCorrente[i];
                solCorrente[i] = solCorrente[j];
                solCorrente[j] = aux;
            }
        }

        if (melhorou)
        {
            int aux = solCorrente[posI];
            solCorrente[posI] = solCorrente[posJ];
            solCorrente[posJ] = aux;
        }

    } while (melhorou);

    return solCorrente;
}
vector<pair<int,double>>PDM::distanciaElementos()
{
    vector<pair<int, double>> LE; // lista de elementos
    vector<int> distancias(N); // distancia somada de cada elemento para todos.

    // soma as distancias
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            distancias[i] += matrizDist[i][j]; // somatorio distancias linhas
        }
        LE.push_back(make_pair(i, distancias[i]));
    }
   
    return LE;
}
vector<int> PDM::geraSolucaoAleatoria()
{
    int x;
    for (int i = 0; i < N; i++)
    {
        solucao[i] = i;
    }
    random_shuffle(solucao.begin(), solucao.end());

    return solucao;
}

vector<int> PDM::geraSolucaoGulosaSomaIndices()
{
   vector<pair<int, double>> LC = distanciaMaximaElementos;// lista de candidatos

    sort(LC.begin(), LC.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    }); 


    cout << "\nVetor Solução Soma Indices: ";
    for (int i = 0; i < N; i++)
    {
        solucao[i] = LC[i].first;
        cout << " " << solucao[i];
    }

    return solucao;
}

vector<int> PDM::geraSolucaoSemiGulosa()
{
   
    vector<pair<int, double>> LC = distanciaMaximaElementos;// lista de candidatos
    int posA = rand()%LC.size();
    solucao[0] = LC[posA].first;
   // cout << "\n\n\n VALOR " <<   solucao[0] <<endl<<endl;
    LC.erase(LC.begin()+posA);
   

    sort(LC.begin(), LC.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    }); 

    for (int i = 1; i < LC.size(); i++)
    {
        solucao[i] = LC[i].first;
    }
     cout << "\nVetor Solução Semi Gulosa : "<<endl<<endl;
    for (int i = 0; i < N; i++)
    {
        cout << " " << solucao[i];
    }
    cout<<endl;

    return solucao;
}
vector<int> PDM::descidaPrimeiroInsert(vector<int> &solucao, double foSol)
{
    vector<int> solCorrente = solucao;

    double melhorFo = foSol;
    int posI = 0, posJ = 0;

    bool melhorou = false;

    do
    {
        melhorou = false;

        for (int i = 0; i < solCorrente.size(); i++)
        {
            for (int j = 0; j < solCorrente.size(); j++)
            {
                if (i != j)
                {
                    //aplico a realocacao
                    int cidade = solCorrente[i];
                    //remover a cidade na posicao i
                    solCorrente.erase(solCorrente.begin() + i);

                    //inserir a cidade na posicao j
                    solCorrente.insert(solCorrente.begin() + j, cidade);

                    //avalio a solucao
                    double foSolCorrente = funcaoAvaliacao(solCorrente);

                    //guardo a melhor fo e o melhor movimento
                    if (foSolCorrente > melhorFo)
                    {
                        melhorFo = foSolCorrente;
                        melhorou = true;
                        break;
                    }
                    else
                    {
                        //desfaÃ§o a realocacao
                        int cidade = solCorrente[j];
                        //remover a cidade na posicao j
                        solCorrente.erase(solCorrente.begin() + j);

                        //inserir a cidade na posicao i
                        solCorrente.insert(solCorrente.begin() + i, cidade);
                    }
                }
            }

            if (melhorou)
                break;
        }

    } while (melhorou);

    return solCorrente;
}
vector<int> PDM::descidaPrimeiroTroca(vector<int> &solucao, double foSol)
{
    vector<int> solCorrente = solucao;

    double melhorFo = foSol;
    int posI = 0, posJ = 0;

    bool melhorou = false;

    do
    {
        melhorou = false;

        for (int i = 0; i < solCorrente.size() - 1; i++)
        {
            for (int j = 1; j < solCorrente.size(); j++)
            {
                //aplico a troca
                int aux = solCorrente[i];
                solCorrente[i] = solCorrente[j];
                solCorrente[j] = aux;

                //avalio a solucao
                double foSolCorrente = funcaoAvaliacao(solCorrente);

                //guardo a melhor fo e o melhor movimento
                if (foSolCorrente > melhorFo)
                {
                    melhorFo = foSolCorrente;
                    melhorou = true;
                    break;
                }
                else
                {
                    //desfaÃ§o a troca
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
vector<int> PDM::descidaVizinhacaVariavel(vector<int> &sol, double foSol)
{
    int k = 1, r = 3;

    double melhorSolucao = foSol, fitnessCorrente;
    vector<int> solucao = sol, vetorCorrente;
    vector<int> melhorSOl = sol;
    //imprimeIndividuo(sol);
    int i = 0;
    while (k <= r)
    {
        if (k == 3)
        {
            
            vetorCorrente = descidaPrimeiroInsert(solucao, melhorSolucao);

            
            fitnessCorrente = funcaoAvaliacao(vetorCorrente);
            if (fitnessCorrente > melhorSolucao)
            {
                solucao = vetorCorrente;
                melhorSolucao = fitnessCorrente;
                k = 1;
            }
            else
            {
                k++;
            }
        }

        if (k == 1)
        {
            
            vetorCorrente = descidaPrimeiroTroca(solucao, melhorSolucao);
            
            fitnessCorrente = funcaoAvaliacao(vetorCorrente);
            if (fitnessCorrente > melhorSolucao)
            {
                solucao = vetorCorrente;
                melhorSolucao = fitnessCorrente;
                k = 1;
            }
            else
            {
                k++;
            }
        }
        

        if (k == 2)
        {
            
            vetorCorrente = descidaCompletaTroca(solucao, funcaoAvaliacao(solucao));
            
            fitnessCorrente = funcaoAvaliacao(vetorCorrente);
            if (fitnessCorrente > melhorSolucao)
            {
                solucao = vetorCorrente;
                melhorSolucao = fitnessCorrente;
                k = 1;
            }
            else
            {
                k++;
            }
        }

        
    }

    return solucao;
}
vector<int> PDM::multiStart(vector<int> &sol, double foSol)
{
    double melhorFo=foSol, correnteFo=foSol;
    int numeroGeracoesSemMelhora=12;
    int contador;
    vector<int>melhorSol=sol,solCorrente=geraSolucaoAleatoria();
    while(contador<numeroGeracoesSemMelhora){
        solCorrente=descidaPrimeiroTroca(solCorrente,correnteFo);
        correnteFo=funcaoAvaliacao(solCorrente);
        if (correnteFo > melhorFo){
            melhorSol=solCorrente;
            melhorFo=correnteFo;
            contador=0;
        }else{
            cout<<"iterações sem melhora: "<<contador<<endl;
            solCorrente=geraSolucaoAleatoria();
            contador++;
        }
       
    }
    return melhorSol;
}
void PDM::imprimeSolucao(vector<int> &solucao)
{
    cout << "[ ";
    for (int i = 0; i < M; i++)
        cout << solucao[i] << ", ";
    cout << " | ";
    for (int i = M; i < N; i++)
        cout << solucao[i] << ", ";
    cout << "]" << endl;
}
double PDM::funcaoAvaliacao(vector<int> &solucao)
{
    double fitness = 0;

    for (int i = 0; i < M-1; i++)
    {
        for(int j=i+1;j<M;j++){
                //cout<<"i"<<solucao[i]<<"j"<<solucao[j]<<endl;
                fitness += matrizDist[solucao[i]][solucao[j]];
           
        }
              
    }
    return fitness;
}

PDM::~PDM()
{
    f.close();
}