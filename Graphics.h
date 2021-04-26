#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#define FILL -1
#define NUM 100

#ifdef __cplusplus
extern "C"
{
#endif

int DLL_EXPORT g_init(const char *title, int width, int height);
int DLL_EXPORT g_show(void);
int DLL_EXPORT g_clear(int r, int g, int b);
int DLL_EXPORT g_saveToFile(const char *filename);
int DLL_EXPORT g_saveToMemory(int n);
int DLL_EXPORT g_loadFromFile(const char *filename);
int DLL_EXPORT g_loadFromFile_n(const char *filename, int n);
int DLL_EXPORT g_loadFromMemory(int n);
int DLL_EXPORT g_close(void);
int DLL_EXPORT g_waitKey(int delay);
int DLL_EXPORT g_getWidth(int *width);
int DLL_EXPORT g_getWidth_n(int *width, int n);
int DLL_EXPORT g_getHeight(int *height);
int DLL_EXPORT g_getHeight_n(int *height, int n);
int DLL_EXPORT g_setPixel(int x, int y, int r, int g, int b);
int DLL_EXPORT g_getPixel(int x, int y, int *r, int *g, int *b);
int DLL_EXPORT g_line(int x1, int y1, int x2, int y2, int r, int g, int b, int thickness);
int DLL_EXPORT g_lineStart(int x, int y, int r, int g, int b, int thickness);
int DLL_EXPORT g_lineTo(int x, int y);
int DLL_EXPORT g_circle(int xc, int yc, int radius, int r, int g, int b, int thickness);
int DLL_EXPORT g_rectangle(int x1, int y1, int x2, int y2, int r, int g, int b, int thickness);
int DLL_EXPORT g_polylines(int *x, int *y, int n, int isClosed, int r, int g, int b, int thickness);
int DLL_EXPORT g_floodFill(int x, int y, int r, int g, int b);
int DLL_EXPORT g_putImage_n(int x, int y, int n, int transparent);
int DLL_EXPORT g_putText(int x, int y, const char* text, double fontScale, int r, int g, int b, int thickness);
int DLL_EXPORT g_getTextSize(const char* text, double fontScale, int *width, int *height, int *baseline, int thickness);
typedef void (*g_MouseCallback)(int event, int x, int y, int flags, void* userdata);
int DLL_EXPORT g_setMouseCallback(g_MouseCallback onMouse, void *userdata);
enum MouseEventTypes {
       g_EVENT_MOUSEMOVE      = 0,
       g_EVENT_LBUTTONDOWN    = 1,
       g_EVENT_RBUTTONDOWN    = 2,
       g_EVENT_MBUTTONDOWN    = 3,
       g_EVENT_LBUTTONUP      = 4,
       g_EVENT_RBUTTONUP      = 5,
       g_EVENT_MBUTTONUP      = 6,
       g_EVENT_LBUTTONDBLCLK  = 7,
       g_EVENT_RBUTTONDBLCLK  = 8,
       g_EVENT_MBUTTONDBLCLK  = 9,
       g_EVENT_MOUSEWHEEL     = 10,
       g_EVENT_MOUSEHWHEEL    = 11
     };
enum MouseEventFlags {
       g_EVENT_FLAG_LBUTTON   = 1,
       g_EVENT_FLAG_RBUTTON   = 2,
       g_EVENT_FLAG_MBUTTON   = 4,
       g_EVENT_FLAG_CTRLKEY   = 8,
       g_EVENT_FLAG_SHIFTKEY  = 16,
       g_EVENT_FLAG_ALTKEY    = 32
     };

#ifdef __cplusplus
}
#endif

#endif // __GRAPHICS_H__
