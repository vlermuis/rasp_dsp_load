#ifndef DSP_H
#define DSP_H


class CDsp
{
    public:
        CDsp();
        virtual ~CDsp();
        virtual void Load();
        virtual void SetVolume(unsigned int volume);
        virtual void Sleep(unsigned int mode);

    protected:

    private:
};

#endif // DSP_H
