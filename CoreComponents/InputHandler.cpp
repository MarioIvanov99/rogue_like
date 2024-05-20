#include "InputHandler.h"
#ifdef _WIN32
#include <windows.h>
#endif

bool InputHandler::isKeyPressed(int key){
    return GetAsyncKeyState(key) & 0x8000;
}