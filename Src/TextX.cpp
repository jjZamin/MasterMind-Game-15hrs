#include "../Inc/TextX.h"


TextX::TextX() {
    this -> initFonts();
    this -> setGuessBTNtxt();
    this -> setGameNameText();
    this -> setYouLostText();
    this -> setYouWonText();
    this -> setPlayBTNtxt();
    this -> gameText();
}

void TextX::initFonts() {
    this -> font_1.loadFromFile("fonts/Boogie.ttf");
    this -> font_2.loadFromFile("fonts/days.ttf");
    this -> font_3.loadFromFile("fonts/texture.ttf");
    this -> font_4.loadFromFile("fonts/vend.ttf");
}

void TextX::setGuessBTNtxt() {
    this -> text_guess.setPosition(sf::Vector2f(550.f, 670.f));
    this -> text_guess.setFont(this -> font_1);
	this -> text_guess.setCharacterSize(50);
	this -> text_guess.setFillColor(sf::Color::White);
	this -> text_guess.setString("GUESS");
}

void TextX::setPlayBTNtxt() {
    this -> text_play.setPosition(sf::Vector2f(515.f, 670.f));
    this -> text_play.setFont(this -> font_1);
	this -> text_play.setCharacterSize(50);
	this -> text_play.setFillColor(sf::Color::Green);
	this -> text_play.setString("Play again");
}

void TextX::setGameNameText() {
    this -> text_title.setPosition(sf::Vector2f(410.f, 15.f));
    this -> text_title.setFont(this -> font_2);
	this -> text_title.setCharacterSize(70);
	this -> text_title.setFillColor(sf::Color::White);
	this -> text_title.setString("Mastermind X");
}

void TextX::setYouWonText() {
    this -> text_you_won.setPosition(sf::Vector2f(750.f, 630.f));
    this -> text_you_won.setFont(this -> font_4);
	this -> text_you_won.setCharacterSize(70);
	this -> text_you_won.setFillColor(sf::Color::Green);
	this -> text_you_won.setString("Amazing job!");
}

void TextX::setYouLostText() {
    this -> text_try_again.setPosition(sf::Vector2f(750.f, 630.f));
    this -> text_try_again.setFont(this -> font_4);
	this -> text_try_again.setCharacterSize(70);
	this -> text_try_again.setFillColor(sf::Color::Red);
	this -> text_try_again.setString("Try again!");
}

void TextX::gameText() {

    std::stringstream stst;
    stst    << "[ You're playing the computer ]" 
            << "\n"
            << "[ It hid its code under the black tiles! ]" 
            << "\n"
            << "[ You start your guesses from the left most column ]" 
            << "\n"
            << "[ There are 4 colors to choose from ]"
            << "\n"
            << "[ Click on a column slot (several times) to choose between colors ]"
            << "\n"
            << "[ Push GUESS when you're done with your guess! ]"
            << "\n"
            << "<NOTE>: Hints below every column tell you:"
            << "\n"
            << " >> Magenta: Position and color of a tile is correct!"
            << "\n"
            << " >> Black: A color is correct, but not in the right position.";

    this -> text_game_text.setPosition(sf::Vector2f(10.f, 640.f));
    this -> text_game_text.setFont(this -> font_3);
	this -> text_game_text.setCharacterSize(14);
	this -> text_game_text.setFillColor(sf::Color(100, 200, 100, 255));
	this -> text_game_text.setString(stst.str());
}



sf::Text TextX::txtGuess() {
    return this -> text_guess;
}

sf::Text TextX::txtPlay() {
    return this -> text_play;
}

sf::Text TextX::txtTitle() {
    return this -> text_title;
}

sf::Text TextX::txtYouWon() {
    return this -> text_you_won;
}

sf::Text TextX::txtTryAgain() {
    return this -> text_try_again;
}

sf::Text TextX::txtGameText() {
    return this -> text_game_text;
}