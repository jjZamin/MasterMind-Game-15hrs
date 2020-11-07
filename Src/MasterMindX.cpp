#include "../Inc/MasterMindX.h"

MasterMindX::MasterMindX() {
    this -> window = new Window();
    this -> initVars();
}

MasterMindX::~MasterMindX() {
    delete this -> window;
}

void MasterMindX::initVars() {
    this -> times_guessed = 0;
    this -> mouse_pushed = false;
    this -> game_done = false;
    this -> WON = false;
    this -> LOST = false;
    this -> K = -1;
    this -> hintSlotCnt = 1;
}


/**
 * set new color for slot 
*/
sf::Color MasterMindX::setNewColor(sf::RectangleShape rec) {
    if(rec.getFillColor() == sf::Color::Blue) {
        return sf::Color::Yellow;
    }
    else if(rec.getFillColor() == sf::Color::Yellow) {
        return sf::Color::Red;
    }
    else if(rec.getFillColor() == sf::Color::Red) {
        return sf::Color::Cyan;
    }
    else {
        return sf::Color::Blue;
    }
} 

/**
 * change slot color by clicking on it
*/
void MasterMindX::clickSlot() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if(this -> mouse_pushed == false) {
            this -> mouse_pushed = true;

            if(times_guessed < 6) {
                for(int i = 0; i < 3; i++) {
                    if(this -> board.getSlot(i, times_guessed)
                        .getGlobalBounds().contains(this -> mousePositionf)) {
                        
                        this -> board.setSlotColor(i, times_guessed, 
                            setNewColor(this -> board.getSlot(i, times_guessed)));
                    }
                }
            }
        }
    }
    else {
        this -> mouse_pushed = false;
    }
}

/**
 * pushing GUESS button, updating number of guesses, checking if answer is right 
*/
void MasterMindX::updateGuessBTN() {

    if(!game_done) {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if(this -> guess_pushed == false) {
                this -> guess_pushed = true;
        
                if(this -> board
                    .getGuessBTN()
                    .getGlobalBounds()
                    .contains(this -> mousePositionf)) {
                        checkIfGuessIsCorrect(); //now check if guess is correct
                } 
            }
        }
        else {
            this -> guess_pushed = false;
        }
    }
    else {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if(this -> guess_pushed == false) {
                this -> guess_pushed = true;
        
                if(this -> board
                    .getGuessBTN()
                    .getGlobalBounds()
                    .contains(this -> mousePositionf)) {
                        this -> initVars();
                        this -> board.resetBoard();
                } 
            }
        }
        else {
            this -> guess_pushed = false;
        }
    }
}

/**
 * Hints about which colors you guessed right
*/
void MasterMindX::setHints() {

    int checks = 0;
    int x = 0;
    int y = 0;   
    int color_pos = 0;
    int color_only = 0;
    bool already_marked = false;
    int cnt_buf = 0;
    sf::Color color_buf[4] = {sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White};

    
    if(times_guessed == 1) {
        hintSlotCnt = 1;
    }
    else if(times_guessed > 1 && times_guessed < 5) {
        if(this -> times_guessed%2 == 0) {
            hintSlotCnt = 1;
        }
        else {
            hintSlotCnt = 0;
        }
    }
    else if(times_guessed == 5) {
        hintSlotCnt = 2;
    }
    else if(times_guessed == 6) {
        hintSlotCnt = 3;
    }

    /* compare pos and color */
    for(int i = 0; i < 3; i++) {
        guessed[i] = board.getSlot(i, this -> times_guessed - 1).getFillColor();
        coded[i] = board.getCode(i).getFillColor();

        if(guessed[i] == coded[i]) {     
            this -> board.setHintColor((((this -> times_guessed) * (this -> K)) + hintSlotCnt), sf::Color::Magenta);
            color_buf[cnt_buf++] = coded[i];
            color_pos++;
            hintSlotCnt++;
        }
    }

    while(checks < 6 && color_pos < 2) {

        if(checks == 0) {
            x = 0;
            y = 1;
        }
        else if(checks == 1) {
            x = 0;
            y = 2;
        }
        else if(checks == 2) {
            x = 1;
            y = 0;
        }
        else if(checks == 3) {
            x = 1;
            y = 2;
        }
        else if(checks == 4) {
            x = 2;
            y = 0;
        }
        else if(checks == 5) {
            x = 2;
            y = 1;
        }

        if(guessed[x] == coded[y]) {
            for(int l = 0; l < 4; l++) {
                if(color_buf[l] == coded[y]) {
                    already_marked = true;
                    break;
                }
            }
            if(!already_marked) {
                color_buf[cnt_buf++] = coded[y];            
                this -> board.setHintColor((((this -> times_guessed) * (this -> K)) + hintSlotCnt), sf::Color::Black);         
                hintSlotCnt++;
            }            
        }
        already_marked = false;
        checks++;
    }
    
    if(K < 0) {
        this -> K = this -> K + 2;
    }
    else {
        this -> K = 2;
    }
}

/**
 * Compares the quess with the code
*/
void MasterMindX::checkIfGuessIsCorrect() {
    for(int i = 0; i < 3; i++) {
        guessed[i] = board.getSlot(i, times_guessed).getFillColor();
        coded[i] = board.getCode(i).getFillColor();
    }

    if((guessed[0] == coded[0]) 
        && (guessed[1] == coded[1])
        && (guessed[2] == coded[2])) {
        std::cout << "CORRECT!" << "\n";

        game_done = true;
        WON = true;
    }
    else {
        std::cout << "NOT CORRECT!" << "\n";
        times_guessed++;
        if(times_guessed == 6) {
            game_done = true;
            LOST = true;
        }
        else {
            this -> setHints(); //set hint slots
        }
    }
}

// update the ouse positions relative to window (vector 2i)
void MasterMindX::updateMousePos() {
    mousePosition = this -> window -> getMousePosition();
    mousePositionf = (sf::Vector2f)mousePosition;
}

/*********************** PUBLIC FUNCTIONS ***********************/

/**
 * check if the window is still opened
*/
const bool MasterMindX::isOn() const {
    return this -> window -> isShowing();
}

/**
 * update game
*/
void MasterMindX::update() {
    this -> window -> events();
    this -> updateMousePos();
    this -> clickSlot();
    this -> updateGuessBTN();

    // std::cout << "mouse x: " << mousePosition.x << "\n";
    // std::cout << "mouse y: " << mousePosition.y << "\n";
}

/**
 * render game
*/
void MasterMindX::render() {
    this -> window -> clear();

    /*render next frame*/
    /*----------*/
    this -> window -> drawRectObj(board.getMainBoard());

    /*code to be quessed will be shown either when you loose or win*/
    if(game_done == true and (LOST == true || WON == true)) {
        for(int z = 0; z < SLOTS_ROWS; z++) {
            this -> window -> drawRectObj(board.getCode(z));
        }
        if(LOST == true) {
            this -> window -> drawText(text.txtTryAgain());
        }
        else if(WON == true) {
            this -> window -> drawText(text.txtYouWon());
        }
    }
    else {
        for(int z = 0; z < SLOTS_ROWS; z++) {
           this -> window -> drawRectObj(board.hiddenCode(z));
        }
    }
    
    /*draw hint slots*/
    for(int z = 0; z < 3*6; z++) {
        this -> window -> drawRectObj(board.getHintSlot(z));
    }

    /*draw slots*/
    for(int i = 0; i < SLOTS_ROWS; i++) {
        for(int j = 0; j < SLOTS_COLS; j++) {
            this -> window -> drawRectObj(board.getSlot(i, j));
        }
    }

    this -> window -> drawRectObj(board.getGuessBTN());
    
    if(!game_done) {
        this -> window -> drawText(text.txtGuess());        
    }
    else {
        this -> window -> drawText(text.txtPlay());
    }

    this -> window -> drawText(text.txtTitle());
    this -> window -> drawText(text.txtGameText());
    /*----------*/


    this -> window -> show();
}
