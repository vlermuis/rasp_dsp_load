#include <iostream>
#include "Dsp1451.h"
using namespace std;

//CDsp1451 dspObj;

int main()
{
    CDsp1451* pDsp1451 = new(CDsp1451);
    pDsp1451->Load();
    pDsp1451->SetVolume(65);
    pDsp1451->Sleep(0);
    pDsp1451->Sleep(1);
    free(pDsp1451);
    cout << "Bazzinga!" << endl;
    return 0;
}
