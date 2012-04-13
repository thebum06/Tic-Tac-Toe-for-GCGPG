#include "CApp.h"

// Checks all the events, and runs the appropriate function.
void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

// Runs when the user exits the game.
void CApp::OnExit() {
    Running = false;
}

// Runs when the user clicks left mouse button.
void CApp::OnLButtonDown(int mX, int mY) {
    // If AI has not been selected.
    if (!AISelect) {
        if ((mX > 156 && mX < 440) && (mY > 279 && mY < 350)) {
            AI = true;
            AISelect = true;
        }
        else if ((mX > 192 && mX < 410) && (mY > 413 && mY < 478)) {
            AI = false;
            AISelect = true;
        }
    }
    // Checks which square the user clicks.
    else if (!Winner && !Draw) {
        int ID    = mX / 200;
        ID = ID + ((mY / 200) * 3);

        if(Grid[ID] != GRID_TYPE_NONE) {
            return;
        }

        if(CurrentPlayer == 0) {
            SetCell(ID, GRID_TYPE_X);
            CurrentPlayer = 1;
        }
        else {
            SetCell(ID, GRID_TYPE_O);
            CurrentPlayer = 0;
        }
    }
    // If game is over, checks if yes or no is clicked.
    else {
        if ((mX > 100 && mX < 273) && (mY > 440 && mY < 530))
            Reset();
        else if ((mX > 375 && mX < 514) && (mY > 440 && mY < 530))
            Running = false;
    }
}
