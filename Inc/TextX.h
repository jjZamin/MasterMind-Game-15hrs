#ifndef _TEXTX_H_
#define _TEXTX_H_

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>



class TextX {
    private:
        sf::Font font_1;
        sf::Font font_2;
        sf::Font font_3;
        sf::Font font_4;
        sf::Text text_guess;
        sf::Text text_play;
        sf::Text text_title;
        sf::Text text_you_won;
        sf::Text text_try_again;
        sf::Text text_game_text;

        void initFonts();
        void setGuessBTNtxt();
        void setGameNameText();
        void setYouWonText();
        void setYouLostText();
        void setPlayBTNtxt();
        void gameText();

    public:
        TextX();
        sf::Text txtGuess();
        sf::Text txtTitle();
        sf::Text txtYouWon();
        sf::Text txtTryAgain();
        sf::Text txtPlay();
        sf::Text txtGameText();

};

#endif