#include "game.h"



//private functions
void Game::initVariables () {
    this->window = nullptr;
};

void Game::initWindow () {
    this->videoMode.height = 800;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Aim Machine", sf::Style::Titlebar | sf::Style::Close);
};

//Constructors

Game::Game () {
    this->initVariables();
    this->initWindow();
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
};


void Game::render () {
    this->window->clear(sf::Color::Blue);
    //draw a game
    this->window->display();
};


