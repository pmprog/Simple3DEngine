
#pragma once

#include <tonc.h>

typedef u32 SDL_Window;
typedef u32* SDL_Renderer;

#define SDL_SCANCODE_RIGHT      0x0010
#define SDL_SCANCODE_LEFT       0x0020
#define SDL_SCANCODE_UP         0x0040
#define SDL_SCANCODE_DOWN       0x0080
#define SDL_SCANCODE_W          0x0002  // B
#define SDL_SCANCODE_S          0x0001  // A
#define SDL_SCANCODE_Q          0x0200  // L
#define SDL_SCANCODE_E          0x0100  // R

#define SDL_INIT_VIDEO          0x0000
#define SDL_QUIT                0xDEAD

typedef struct SDL_Event
{
    u32 type;
} SDL_Event;

void SDL_Init(u32 Ignore);
void SDL_CreateWindowAndRenderer(u32 W, u32 H, u32 D, SDL_Window* Wn, SDL_Renderer* Rn);
const unsigned char* SDL_GetKeyboardState();
void SDL_DestroyRenderer(SDL_Renderer* Rn);
void SDL_DestroyWindow(SDL_Window* Wn);
void SDL_Quit();
u16 SDL_PollEvent(SDL_Event* Ev);

void SDL_SetRenderDrawColor(SDL_Renderer* Rn, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
void SDL_RenderClear(SDL_Renderer* Rn);
void SDL_RenderPresent(SDL_Renderer* Rn);
void SDL_RenderDrawPoint(SDL_Renderer* Rn, u32 X, u32 Y);
void SDL_RenderDrawLine(SDL_Renderer* Rn, u32 X1, u32 Y1, u32 X2, u32 Y2);

u16 SDL_KeyHeld(u16 K);
