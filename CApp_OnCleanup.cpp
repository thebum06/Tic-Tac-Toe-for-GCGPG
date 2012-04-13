#include "CApp.h"

void CApp::OnCleanup() {
    SDL_FreeSurface(Surf_Grid);
    SDL_FreeSurface(Surf_X);
    SDL_FreeSurface(Surf_O);
    SDL_FreeSurface(Surf_XWin);
    SDL_FreeSurface(Surf_OWin);
    SDL_FreeSurface(Surf_Draw);
    SDL_FreeSurface(Surf_Display);
    SDL_FreeSurface(Surf_Again);
    SDL_FreeSurface(Surf_AI);
    SDL_Quit();
}
