#include "CApp.h"

void CApp::OnRender() {
    // Draws the AI select screen if no choice has been made.
    if (!AISelect)
        CSurface::OnDraw(Surf_Display, Surf_AI, 0, 0);
    else
        CSurface::OnDraw(Surf_Display, Surf_Grid, 0, 0);

    // Shows the board if no winner and no draw.
    if (!Winner && !Draw) {
        for(int i = 0; i < 9; i++) {
            int X = (i % 3) * 200;
            int Y = (i / 3) * 200;

            if(Grid[i] == GRID_TYPE_X) {
                CSurface::OnDraw(Surf_Display, Surf_X, X, Y);
            }
            else if(Grid[i] == GRID_TYPE_O) {
                CSurface::OnDraw(Surf_Display, Surf_O, X, Y);
            }
        }
        if (AISelect && CurrentPlayer == 0)
            CSurface::OnDraw(Surf_Display, Surf_Again, 270, 5, 0, 442, 60, 18);
        else if (AISelect)
            CSurface::OnDraw(Surf_Display, Surf_Again, 270, 5, 485, 442, 60, 18);
    }
    // Shows game over screen if it's draw or someone wins.
    else if (Draw)
        CSurface::OnDraw(Surf_Display, Surf_Draw, 0, 0);
    else {
        if (CurrentPlayer == 1)
            CSurface::OnDraw(Surf_Display, Surf_XWin, 0, 0);
        else
            CSurface::OnDraw(Surf_Display, Surf_OWin, 0, 0);
    }
    if (Winner || Draw) {
        CSurface::OnDraw(Surf_Display, Surf_Again, 25, 190, 0, 0, 600, 210);
        CSurface::OnDraw(Surf_Display, Surf_Again, 100, 440, 30, 300, 173, 88);
        CSurface::OnDraw(Surf_Display, Surf_Again, 375, 440, 308, 308, 139, 95);
    }

    // For double buffering.
    SDL_Flip(Surf_Display);
}
