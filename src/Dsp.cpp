#include <iostream>
#include "Dsp.h"

using namespace std;
CDsp::CDsp()
{
    //ctor
}

CDsp::~CDsp()
{
    //dtor
}
void CDsp::Load()
{
    cout << "CDsp::Load()" << endl;
}
void CDsp::SetVolume(unsigned int volume)
{
    cout << "CDsp::SetVolume()" << endl;
}
void CDsp::Sleep(unsigned int mode)
{
    cout << "CDsp::Sleep()" << endl;
}
