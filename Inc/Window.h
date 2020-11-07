#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

/* MACROS */
#define WINDOW_WIDTH    1200
#define WINDOW_HEIGHT   800
#define WINDOW_NAME     "MASTERMINDX"
#define FRAMERATE       60

class Window {
    /*private parts of Window Class*/
    private: 
        /*private obj for window class*/
        sf::RenderWindow *GameWindow;
        sf:: VideoMode VideoMode;
        sf::Event Event;

        /*private functions for window class*/
        void initWindow();
    public:
        Window();
        virtual ~Window();

        /*public functions for window class*/
        void show();
        void events();
        void clear();
        sf::Vector2i getMousePosition();
        const bool isShowing() const;
        void drawRectObj(sf::RectangleShape obj);
        void drawText(sf::Text txt);

};

#endif
