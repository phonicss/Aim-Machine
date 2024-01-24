#pragma once

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ctime>
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

        //Mouse positions
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosview;

        //Game logic
        int points;
        float enemySpawnTimer;
        float enemySpawnTimerMax;
        int maxEnemies;

        //Game objects
        std::vector<sf::CircleShape> enemies;
        sf::CircleShape enemy;

        //private functions
        void initVariables();
        void initWindow();
        void initEnemies();

    public:
        //constructors / destructors 
        Game();
        virtual ~Game();

        //Accsessors
        const bool running() const;


        //Functions
        void spawnEnemy();
        void pollEvenets();
        void updateMousePositions();
        void updateEnemies();
        void update();
        void renderEnemies();
        void render();
};


#endif