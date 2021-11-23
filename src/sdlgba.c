
#include "sdlgba.h"

#define RGB8macro(r,g,b)        ( ((r)>>3) | (((g)>>3)<<5) | (((b)>>3)<<10) )

static u16 pollctr;
static u16 rendercolour;


void SDL_Init(u32 Ignore)
{
    pollctr = 0;
}

void SDL_CreateWindowAndRenderer(u32 W, u32 H, u32 D, SDL_Window* Wn, SDL_Renderer* Rn)
{
    // Mode 3 Bitmap
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2 | DCNT_OBJ | DCNT_OBJ_1D;
}

const unsigned char* SDL_GetKeyboardState()
{
    return NULL;
}

void SDL_DestroyRenderer(SDL_Renderer* Rn)
{
    
}
void SDL_DestroyWindow(SDL_Window* Wn)
{

}
void SDL_Quit()
{

}

u16 SDL_PollEvent(SDL_Event* Ev)
{
    Ev->type = 0;
    pollctr = 1 - pollctr;
    return pollctr;
}

u16 SDL_KeyHeld(u16 K)
{
    u16 gbainput = (u16)(~REG_KEYINPUT) & 0x03ff;
    return (gbainput & K);
}



void SDL_SetRenderDrawColor(SDL_Renderer* Rn, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
    rendercolour = RGB8macro(R, G, B);
}
void SDL_RenderClear(SDL_Renderer* Rn)
{
    for(int y = 0; y < 160; ++y)
    {
        SDL_RenderDrawLine( Rn, 0, y, 240, y );
    }
}
void SDL_RenderPresent(SDL_Renderer* Rn)
{

}
void SDL_RenderDrawPoint(SDL_Renderer* Rn, u32 X, u32 Y)
{
    m3_plot( X, Y, rendercolour );
}

void SDL_RenderDrawLine(SDL_Renderer* Rn, u32 X1, u32 Y1, u32 X2, u32 Y2)
{
    m3_line( X1, Y1, X2, Y2, rendercolour );
}
