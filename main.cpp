#include <iostream>
#include "Dsp1451.h"
using namespace std;

CDsp1451 dspObj;

int main()
{
    dspObj.Load();
    dspObj.SetVolume(65);
    cout << "Bazzinga!" << endl;
    return 0;
}
