#include "sound.h"
static HINSTANCE HInstance;
static char *buffer[N];
static int hasOpened=0;
void s_initSound()
{
    HInstance = GetModuleHandle(0);
    hasOpened = 1;
}
void s_close()
{
    int i;
    for(i=0; i<N; i++)
    {
        if(buffer[i])
            free(buffer[i]);
        buffer[i]=0;
    }
    hasOpened=0;
}
int s_loadSound(char *waveFile, int n)
{
    n--;
    if(hasOpened && n>=0 && n < N)
    {
        FILE *fd=fopen(waveFile, "rb");
        if(!fd)
            return -1;

        fseek(fd, 0, SEEK_END);
        int len = ftell(fd);
        buffer[n] =  malloc(len);
        if(!buffer[n])
            return -1;

        rewind(fd);
        int cnt=fread(buffer[n], 1, len, fd);
        if(cnt!=len)
        {
            free(buffer[n]);
            buffer[n]=0;
            return -1;
        }
        return 0;
    }
    else
        return -1;
}
int s_playSound(int n, int loop, int nowait)
{
    int mode = SND_MEMORY;
    if(nowait)
        mode |= SND_ASYNC;
    if(loop)
        mode |= SND_LOOP;

    n--;
    if(hasOpened && n>=0 && n < N && buffer[n])
    {
        PlaySound(buffer[n], HInstance,  mode);
        return 0;
    }
    else
        return -1;
}
void s_stopSound()
{
    PlaySound(NULL, NULL, 0);
}
