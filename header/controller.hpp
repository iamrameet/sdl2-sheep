#pragma once
#include <iostream>
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
#include "path.hpp"
#include "vector-list.hpp"
#include "controls/sheep_control.hpp"
#include "controls/hitpoint_control.hpp"

// #define Array(type, identifier) std::vector<type> identifier
class Game;

class Controller{
    // Array(SheepPath *, paths);
    VectorList<SheepPath *> &paths;
    Game *game;
    int selected = 0;
    int playerId;
    private:
        void onSelect(SheepPath *path, int index, unsigned int highlightIndex);
        void onUnselect(SheepPath *path, int index, unsigned int highlightIndex);
    public:
        HitpointControl *hitpointControl;
        SheepControl *control[3];
        Controller(Game *game, VectorList<SheepPath *> &paths, int playerId);
        int getSelectedIndex();
        SheepPath * getSelectedPath();
        void selectPath(int index);
        void selectPathRight();
        void selectPathLeft();
        void clearSelection();
        void plotSheep(int direction);
};