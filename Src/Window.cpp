#include "../Inc/Window.h"

/* constructor for window class */
Window::Window() {
    this -> initWindow();
}

Window::~Window() {
    delete this -> GameWindow;
}

void Window::initWindow() {
    this -> GameWindow = nullptr;
    
    this -> VideoMode.height = WINDOW_HEIGHT;
    this -> VideoMode.width = WINDOW_WIDTH;

    this -> GameWindow = new sf::RenderWindow(
        this -> VideoMode,
        WINDOW_NAME,
        sf::Style::Titlebar | sf::Style::Close
    );
    this -> GameWindow -> setFramerateLimit(FRAMERATE);
}

/***** PUBLIC FUNCTIONS *****/
/**
 * Showing the window
*/
void Window::show() {
    this -> GameWindow -> display();
}
/**
 * Clear window, black
*/
void Window::clear() {
    this -> GameWindow -> clear(sf::Color::Black);
}

/**
 * Polling events from the window
*/
void Window::events() {

    while(this -> GameWindow -> pollEvent(this -> Event)) {
        switch(this -> Event.type) {
            case sf::Event::Closed:
                this -> GameWindow -> close();
                break;
            case sf::Event::KeyPressed:
                if(this -> Event.key.code == sf::Keyboard::Escape) {
                    this -> GameWindow -> close();
                }
                break;
        }
    }
}

/**
 * [returns: bool]
 * Check if window is opened
*/
const bool Window::isShowing() const {
    return this -> GameWindow -> isOpen();
}

void Window::drawRectObj(sf::RectangleShape obj) {
    this -> GameWindow -> draw(obj);
}

void Window::drawText(sf::Text txt) {
    this -> GameWindow -> draw(txt);
}

sf::Vector2i Window::getMousePosition() {
    return sf::Mouse::getPosition(*this -> GameWindow);
}