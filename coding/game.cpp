#include "game.h"



//private functions
void Game::initVariables () {
    this->window = nullptr;
};

void Game::initWindow () {
    this->videoMode.height = 800;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Aim Machine", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
};

void Game::initEnemies () {
    this->enemy.setPosition(10,10);
    this->enemy.setRadius(25);
    this->enemy.setFillColor(sf::Color::Red);
    this->enemy.setOutlineColor(sf::Color::Yellow);
    this->enemy.setOutlineThickness(1.f);
}

//Constructors

Game::Game () {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
};

Game::~Game () {
    delete this->window;
};

//Accsesors
const bool Game::running () const {
    return this->window->isOpen();
};

//Functions 
void Game::pollEvenets () {
      //Event pulling
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
        }
    }
}



void Game::update () {
    this->pollEvenets();

    //update mouse position
    sf::Mouse::getPosition(*this->window).x;
    sf::Mouse::getPosition(*this->window).y;
};


void Game::render () {

    this->window->clear();
    //draw a game
    this->window->draw(this->enemy);

    this->window->display();
};


