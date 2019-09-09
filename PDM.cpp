#include "PDM.h"

PDM::PDM(string nomeArq): nomeArq(nomeArq) {
    f = ifstream(nomeArq);

    if(!f.is_open()) cout << "ERRO AO ABRIR ARQUIVO" << nomeArq << "!\n" << endl;
}