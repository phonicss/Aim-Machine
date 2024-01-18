#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
Class that act like a game engine
wrapper class 
*/
class Game {

    private:
        //variables
        //window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;

        //private functions
        void initVariables();
        void initWindow();

    public:
        //constructors / destructors 
        Game();
        virtual ~Game();

        //Accsessors
        const bool running() const;


        //Functions
        void pollEvenets();
        void update();
        void render();
};


#endif