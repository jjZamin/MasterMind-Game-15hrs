#include "../Inc/Board.h"

Board::Board() {
    std::srand(static_cast<unsigned>(time(NULL)));
    this -> initMainBoard();
    this -> initSlots();
    this -> initHints();
    this -> generateCode();
}

/**
 * Main board 
*/
void Board::initMainBoard() {
    this -> MainBoard.setPosition(100.f, 100.f);
    this -> MainBoard.setSize(sf::Vector2f(1000.f, 500.f));
    this -> MainBoard.setFillColor(sf::Color::Green);
    this -> MainBoard.setOutlineColor(sf::Color::White);
	this -> MainBoard.setOutlineThickness(5.f);

    float _pos_y = 120.f;
    this -> slot.setPosition(980.f, _pos_y);
    this -> slot.setSize(sf::Vector2f(100.f, 100.f));
    this -> slot.setFillColor(sf::Color::Black);
    this -> slot.setOutlineColor(sf::Color::Magenta);
    this -> slot.setOutlineThickness(2.f);

    for(int i = 0; i < 3; i++) {
        hidden[i] = slot;        
        _pos_y = _pos_y + 120.f;
        this -> slot.setPosition(980.f, _pos_y);
    }

    this -> guessBTN.setPosition(500.f, 650.f);
    this -> guessBTN.setSize(sf::Vector2f(200.f, 100.f));
    this -> guessBTN.setFillColor(sf::Color(0, 100, 0, 100));
    this -> guessBTN.setOutlineColor(sf::Color::Red);
    this -> guessBTN.setOutlineThickness(3.f);
}


/**
 * Initialize the positions of the guessing slots
*/
void Board::initSlots() {

    float _pos_x = 120.f;
    float _pos_y = 120.f;

    this -> slot.setPosition(_pos_x, _pos_y);
    this -> slot.setSize(sf::Vector2f(100.f, 100.f));
    this -> slot.setFillColor(sf::Color::White);
    this -> slot.setOutlineColor(sf::Color::Black);
	this -> slot.setOutlineThickness(2.f);

    for(int i = 0; i < SLOTS_ROWS; i++) {
        for(int j = 0; j < SLOTS_COLS; j++) {
            mainSlots[i][j] = slot;
            
            if(j < (SLOTS_COLS-1)) {
                _pos_x = _pos_x + 140.f;
                this -> slot.setPosition(_pos_x, _pos_y);
            }
        }
        _pos_x = 120.f;
        _pos_y = _pos_y + 120.f;
        this -> slot.setPosition(_pos_x, _pos_y);
    }
}

/**
 * Initiates the hint slots
*/
void Board::initHints() {
    int count = 0;
    float next_column = 0.f;

    float _pos_x = 120.f;
    float _pos_y = 500.f;

    this -> slot.setPosition(_pos_x, _pos_y);
    this -> slot.setSize(sf::Vector2f(20.f, 20.f));
    this -> slot.setFillColor(sf::Color(255, 255, 255, 210));
    this -> slot.setOutlineColor(sf::Color::Black);
	this -> slot.setOutlineThickness(1.f);

    for(int i = 0; i < (3*6); i++) {
        this -> hints[i] = slot;

        count++;
        if(count == 3) {
            count = 0;
            next_column++;
            _pos_x = 120.f + (140.f*next_column);
        }
        else {
            _pos_x = _pos_x + 24.f;
        }
        this -> slot.setPosition(_pos_x, _pos_y);
    }
}

/**
 * Generates random color out of 4 possible
*/
sf::Color Board::generateColor() {
    int clr = rand() % 4; //4 colors possible

    switch (clr)
    {
        case 0:
            return sf::Color::Blue;
            break;
        case 1:
            return sf::Color::Yellow;
            break;
        case 2:
            return sf::Color::Red;
            break;
        case 3:
            return sf::Color::Cyan;
            break;
        default:
            return sf::Color::Blue;
            break;
    }
}


/****************** PUBLIC FUNCTIONS ******************/


/**
 * Generate new code
*/
void Board::generateCode() {

    float _pos_y = 120.f;

    this -> slot.setPosition(980.f, _pos_y);
    this -> slot.setSize(sf::Vector2f(100.f, 100.f));
    this -> slot.setFillColor(generateColor());
    this -> slot.setOutlineColor(sf::Color::Magenta);
    this -> slot.setOutlineThickness(2.f);

    for(int i = 0; i < 3; i++) {
        code[i] = slot;        
        _pos_y = _pos_y + 120.f;
        this -> slot.setPosition(980.f, _pos_y);
        this -> slot.setFillColor(generateColor());
    }
}

sf::RectangleShape Board::getCode(int x) {
    if(x < 3) {
        return this -> code[x];
    }
    return this -> code[0];
}

sf::RectangleShape Board::hiddenCode(int x) {

    if(x < 3) {
        return this -> hidden[x];
    }
    return this -> hidden[0];
}

/**
 * Return Main Board to be drawn
*/
sf::RectangleShape Board::getMainBoard() {
    return this -> MainBoard;
}

/**
 * Get slots
*/
sf::RectangleShape Board::getSlot(int x, int y) {
    
    if((x >= 0 && x < SLOTS_ROWS) && (y >= 0 && y < SLOTS_COLS)) {
        return this -> mainSlots[x][y];
    }
    return this -> mainSlots[0][0];
}

sf::RectangleShape Board::getHintSlot(int x) {
    if(x < 3*6) {
        return this -> hints[x];
    }
    return this -> hints[0];
}

void Board::setHintColor(int x, sf::Color color) {
    if(x < 3*6) {
        hints[x].setFillColor(color);
    }
}

/**
 * set color for slots when pushed 
*/
void Board::setSlotColor(int x, int y, sf::Color color) {
    if((x >= 0 && x < SLOTS_ROWS) && (y >= 0 && y < SLOTS_COLS)) {
        mainSlots[x][y].setFillColor(color);
    }
}

void Board::resetBoard() {
    this -> initMainBoard();
    this -> initSlots();
    this -> initHints();
    this -> generateCode();
}

/**
 * Catch the GUESS btn
*/
sf::RectangleShape Board::getGuessBTN() {
    return this -> guessBTN;
}