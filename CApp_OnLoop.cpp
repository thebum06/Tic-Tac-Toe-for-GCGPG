#include "CApp.h"

void CApp::Victory() {
    // Checks victory conditions through first square.
    if (Grid[0] != GRID_TYPE_NONE) {
        if (Grid[0] == Grid[1] && Grid[0] == Grid[2])
            Winner = true;
        if (Grid[0] == Grid[3] && Grid[0] == Grid[6])
            Winner = true;
    }
    // Checks victory conditions through last square.
    if (Grid[8] != GRID_TYPE_NONE) {
        if (Grid[8] == Grid[7] && Grid[8] == Grid[6])
            Winner = true;
        if (Grid[8] == Grid[5] && Grid[8] == Grid[2])
            Winner = true;
    }
    // Checks victory conditions through middle square.
    if (Grid[4] != GRID_TYPE_NONE) {
        if (Grid[4] == Grid[3] && Grid[4] == Grid[5])
            Winner = true;
        if (Grid[4] == Grid[1] && Grid[4] == Grid[7])
            Winner = true;
        if (Grid[4] == Grid[0] && Grid[4] == Grid[8])
            Winner = true;
        if (Grid[4] == Grid[2] && Grid[4] == Grid[6])
            Winner = true;
    }
    // Checks for draw.
    if (!Winner) {
        Draw = true;
        for (int i = 0; i < 9; i++) {
            if (Grid[i] == GRID_TYPE_NONE)
                Draw = false;
        }
    }
}

void CApp::Computer() {
    int AIChoice;
    bool Placed;

    // Checks first if it can win, and then checks if it can block a win.
    for (int i = 2; i > 0; i--) {
        if (Grid[0] == GRID_TYPE_NONE && !Placed) {
            if ((Grid[1] == i && Grid[2] == i) ||
            (Grid[3] == i && Grid[6] == i)     ||
            (Grid[4] == i && Grid[8] == i))    {
                Grid[0] = GRID_TYPE_O;
                Placed = true;
            }
        }
        if (Grid[1] == GRID_TYPE_NONE && !Placed) {
            if ((Grid[0] == i && Grid[2] == i) ||
            (Grid[4] == i && Grid[7] == i))    {
                Grid[1] = GRID_TYPE_O;
                Placed = true;
            }
        }
        if (Grid[2] == GRID_TYPE_NONE && !Placed) {
            if ((Grid[0] == i && Grid[1] == i) ||
            (Grid[5] == i && Grid[8] == i)     ||
            (Grid[4] == i && Grid[6] == i))    {
                Grid[2] = GRID_TYPE_O;
                Placed = true;
            }
        }
        if (Grid[3] == GRID_TYPE_NONE && !Placed) {
            if ((Grid[0] == i && Grid[6] == i) ||
            (Grid[4] == i && Grid[5] == i))    {
                Grid[3] = GRID_TYPE_O;
                Placed = true;
            }
        }
        if (Grid[4] == GRID_TYPE_NONE && !Placed) {
            if ((Grid[1] == i && Grid[7] == i) ||
            (Grid[3] == i && Grid[5] == i)     ||
            (Grid[0] == i && Grid[8] == i)     ||
            (Grid[2] == i && Grid[6] == i))    {
                Grid[4] = GRID_TYPE_O;
                Placed = true;
            }
        }
        if (Grid[5] == GRID_TYPE_NONE && !Placed) {
            if ((Grid[2] == i && Grid[8] == i) ||
            (Grid[3] == i && Grid[4] == i))    {
                Grid[5] = GRID_TYPE_O;
                Placed = true;
            }
        }
        if (Grid[6] == GRID_TYPE_NONE && !Placed) {
            if ((Grid[1] == i && Grid[3] == i) ||
            (Grid[7] == i && Grid[8] == i)     ||
            (Grid[4] == i && Grid[2] == i))    {
                Grid[6] = GRID_TYPE_O;
                Placed = true;
            }
        }
        if (Grid[7] == GRID_TYPE_NONE && !Placed) {
            if ((Grid[6] == i && Grid[8] == i) ||
            (Grid[1] == i && Grid[4] == i))    {
                Grid[7] = GRID_TYPE_O;
                Placed = true;
            }
        }
        if (Grid[8] == GRID_TYPE_NONE && !Placed) {
            if ((Grid[2] == i && Grid[5] == i) ||
            (Grid[6] == i && Grid[7] == i)     ||
            (Grid[0] == i && Grid[4] == i))    {
                Grid[8] = GRID_TYPE_O;
                Placed = true;
            }
        }
    }

    if (!Placed) {
        do {
            AIChoice = rand() % 9;
        } while (Grid[AIChoice] != GRID_TYPE_NONE);

        Grid[AIChoice] = GRID_TYPE_O;
    }
    CurrentPlayer = 0;
}

void CApp::OnLoop() {
    Victory();
    if (CurrentPlayer == 1 && AI && !Winner && !Draw) {
        Computer();
        Victory();
    }
}
