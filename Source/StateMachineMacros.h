#pragma once

#define GetKey(X) 0[#X]
#define IsKeyPressed(Key) (!!(GetAsyncKeyState(KEY)&0x8000)