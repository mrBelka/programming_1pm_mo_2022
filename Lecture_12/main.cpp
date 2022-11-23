#include <Game.hpp>

int main()
{

    mt::Game game;

    game.SetResolution(500, 600);
    game.SetCaption("Test game");
    game.Setup();

    game.Run();

    return 0;
}