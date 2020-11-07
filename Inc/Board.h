#ifndef _BOARD_H_
#define _BOARD_H_

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define SLOTS_ROWS      3
#define SLOTS_COLS      6
#define NR_OF_COLORS    4

class Board {
    private:
        sf::RectangleShape MainBoard;
        sf::RectangleShape slot;
        sf::RectangleShape mainSlots[SLOTS_ROWS][SLOTS_COLS];

        sf::RectangleShape code[SLOTS_ROWS];
        sf::RectangleShape hidden[SLOTS_ROWS];
        sf::RectangleShape guessBTN;

        sf::RectangleShape hints[6*3];

        /*private functions*/
        void initMainBoard();
        void initSlots();
        void initHints();
        void generateCode();
        sf::Color generateColor();
    public:
        Board();
        sf::RectangleShape getMainBoard();
        sf::RectangleShape getSlot(int x, int y);
        sf::RectangleShape getHintSlot(int x);
        sf::RectangleShape getCode(int x);
        sf::RectangleShape hiddenCode(int x);
        sf::RectangleShape getGuessBTN();
        void setSlotColor(int x, int y, sf::Color color);
        void setHintColor(int x, sf::Color color);
        void resetBoard();
};

#endif