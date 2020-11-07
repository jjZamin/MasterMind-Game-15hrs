#ifndef _MASTERMINDX_H_
#define _MASTERMINDX_H_

#include <iostream>
#include <sstream>
#include <vector>
#include "Window.h"
#include "Board.h"
#include "TextX.h"

class MasterMindX {
    /*private parts of Master Mind Game Class*/
    private: 
        Window *window;
        Board board;
        TextX text;

        //vars
        int times_guessed;
        sf::RectangleShape slot_buffer;
        int K; //var for hints
        int hintSlotCnt;

        // color checks
        sf::Color guessed[3];
        sf::Color coded[3];

        //flags
        bool mouse_pushed;
        bool game_done;
        bool guess_pushed;
        bool WON;
        bool LOST;
   
       //mouse positions
		sf::Vector2i mousePosition;
        sf::Vector2f mousePositionf;

        /*private functions for window class*/
        void clickSlot();
        void initVars();
        void updateMousePos();
        sf::Color setNewColor(sf::RectangleShape rec);
        void updateGuessBTN();
        void checkIfGuessIsCorrect(); 
        void setHints();

    public:
        MasterMindX();
        virtual ~MasterMindX();

        /*public functions for window class*/
        const bool isOn() const;
        void update();
        void render();
};

#endif