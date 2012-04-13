#include "CApp.h"

CApp::CApp() {
    StartPlayer = 0;
    Winner = false;
    Draw = false;
    AISelect = false;

    Surf_Grid = NULL;
    Surf_X = NULL;
    Surf_O = NULL;
    Surf_XWin = NULL;
    Surf_OWin = NULL;
    Surf_Draw = NULL;
    Surf_Again = NULL;
    Surf_AI = NULL;

    Surf_Display = NULL;

    Running = true;
}

int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

void CApp::Reset() {
    // Resets the grid.
    for(int i = 0; i < 9; i++) {
        Grid[i] = GRID_TYPE_NONE;
    }

    // Selects the starting player.
    CurrentPlayer = StartPlayer;
    if (StartPlayer == 0)
        StartPlayer = 1;
    else
        StartPlayer = 0;

    Winner = false;
    AI = false;
    AISelect = false;
}

void CApp::SetCell(int ID, int Type) {
    if(ID < 0 || ID >= 9) return;
    if(Type < 0 || Type > GRID_TYPE_O) return;

    Grid[ID] = Type;
}

int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}
