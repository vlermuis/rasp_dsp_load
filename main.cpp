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
    float fr = pDsp1451->DataToFloat( 0x01E66666, 8, 24);
    if ((fr > 1.8) && (fr < 2.0))
    {
        cout << "DataToFloat() - ok." << endl;
    }
    else
    {
        cout << "DataToFloat() - error!" << endl;
    }
    free(pDsp1451);
    cout << "Bazzinga!" << endl;
    return 0;
}
