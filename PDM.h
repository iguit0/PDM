#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class PDM {
    public:
    ifstream f;
    string nomeArq;

    PDM(string nomeArq);
    virtual ~PDM();
};