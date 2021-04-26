#ifndef _SOUND_H_
#define _SOUND_H_
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#define N 100
void s_initSound();
int s_loadSound(char *waveFile, int n);
int s_playSound(int n, int loop, int nowait);
void s_stopSound();
void s_close();
#endif
