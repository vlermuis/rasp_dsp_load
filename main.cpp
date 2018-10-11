#include <iostream>
#include "Dsp1451.h"
using namespace std;

Dsp1451 dspObj;

int main()
{
    dspObj.Load();
    cout << "Bazzinga!" << endl;
    return 0;
}
