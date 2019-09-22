#include "PDM.h"

PDM::PDM(string nomeArq): nomeArq(nomeArq) {
    f = ifstream(nomeArq); // abrir arquivo

    if(!f.is_open()) cout << "ERRO AO ABRIR ARQUIVO" << nomeArq << "!\n" << endl;
}

PDM::~PDM() {
    f.close();
}