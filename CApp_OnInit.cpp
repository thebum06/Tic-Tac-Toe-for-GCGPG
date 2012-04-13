#include "CApp.h"

bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((Surf_Grid = CSurface::OnLoad("./gfx/grid.bmp")) == NULL) {
        return false;
    }

    if((Surf_X = CSurface::OnLoad("./gfx/x.bmp")) == NULL) {
        return false;
    }

    if((Surf_O = CSurface::OnLoad("./gfx/o.bmp")) == NULL) {
        return false;
    }

    if((Surf_XWin = CSurface::OnLoad("./gfx/xwin.bmp")) == NULL) {
        return false;
    }
    if((Surf_OWin = CSurface::OnLoad("./gfx/owin.bmp")) == NULL) {
        return false;
    }
    if((Surf_Draw = CSurface::OnLoad("./gfx/draw.bmp")) == NULL) {
        return false;
    }
    if((Surf_Again = CSurface::OnLoad("./gfx/again.bmp")) == NULL) {
        return false;
    }
    if((Surf_AI = CSurface::OnLoad("./gfx/AI.bmp")) == NULL) {
        return false;
    }

    CSurface::Transparent(Surf_X, 255, 0, 255);
    CSurface::Transparent(Surf_O, 255, 0, 255);
    CSurface::Transparent(Surf_Again, 255, 255, 255);

    srand(time(0));

    Reset();

    return true;
}
