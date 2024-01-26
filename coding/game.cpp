#include "game.h"



//private functions
void Game::initVariables () {
    this->window = nullptr;

    //game logic
    this->endGame = false;
    this->points = 0;
    this->health = 10;
    this->enemySpawnTimerMax = 10;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 20;
    bool deleted = false;
    this->mouseHeld = false;

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

const bool Game::getEndGame () const {
    return this->endGame;
}

//Functions 

void Game::spawnEnemy () {

    //spawn enemies, colors and positions

    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getRadius() - 10)),
        0.f
    );

    //spawn the enemy
    this->enemies.push_back(this->enemy);

    //remove enemies at the end


};



void Game::pollEvenets () 
{
      //Event pulling
    while (this->window->pollEvent(this->ev)) 
    {
        switch (this->ev.type) 
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) 
                {
                    this->window->close();
                }
                break;
        }
    }
}

void Game:: updateMousePositions () 
{

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosview = this->window->mapPixelToCoords(this->mousePosWindow);
};

void Game::updateEnemies () 
{

    //updating the timer for enemy spawning
    if (this->enemies.size() < this->maxEnemies) 
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) 
        {
            //spawn the enemy and respawn the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        } else 
        {
            this->enemySpawnTimer += 1.f;
        }
    }

    //move enemies and update them

    for ( int i = 0; i < enemies.size(); i++) 
    {
        deleted = false;
        this->enemies[i].move(0.f,5.f);
         //if enemy is out of bound
        if (this->enemies[i].getPosition().y > this->window->getSize().y) 
        {
            this -> enemies.erase(this->enemies.begin() + i);
            this->health = this->health - 1;
        }
    }

    //Check if cliked

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
    {
        if (this->mouseHeld == false) 
        {   
            this->mouseHeld = true;
            deleted = false;
            for (size_t i = 0; i < this->enemies.size() && deleted == false ; i++) 
            {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosview))
                {
                //delete an enemy
                deleted = true;
                this->enemies.erase(enemies.begin() + i);
                //gain points
                this->points += 1;
                }
            }
        }
    } else 
    {
        this->mouseHeld = false;
    }
}

void Game::update () 
{
    this->pollEvenets();

    if (!this->endGame) 
    {
        this->updateMousePositions();
        this->updateEnemies();  
    }
    
    //end game condition
    if (this->health <= 0) 
    {
        this->endGame = true;
    }

    
};

void Game::renderEnemies () 
{
       //render all enemies
    for ( auto &e : this->enemies) 
    {
        this->window->draw(e);
    }

}


void Game::render () 
{

    this->window->clear();
    //draw a game
    this->renderEnemies();

    this->window->display();
};


