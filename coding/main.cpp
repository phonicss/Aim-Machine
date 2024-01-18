#include <iostream>
#include "game.h"


int main()
{
    //init game engine
    Game game;

    //Game loop
    while (game.running())
    {
       
        //update
        game.update();
        
        //render
        game.render();

    }



    //End of aplication


    return 0;
}