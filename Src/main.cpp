#include <iostream>
#include "../Inc/MasterMindX.h"

int main() {
    MasterMindX game;

    while(game.isOn()) {
        game.update();
        game.render();
    }
}