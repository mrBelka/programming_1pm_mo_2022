#include <Game.hpp>

int main()
{

    mt::Game game;

    game.SetResolution(500, 600);
    game.SetCaption("Test game");

    mt::Errors error = game.Setup();

    switch (error)
    {
    case mt::Errors::SUCCESS:
        std::cout << "Setup complited" << std::endl;
        break;
    case mt::Errors::LOAD_PICTURE:
        std::cout << "Load picture failed!" << std::endl;
        return -1;
    default:
        break;

    }

    error = game.Run();

    switch (error)
    {
    case mt::Errors::LOAD_PICTURE:
        std::cout << "Load picture failed!" << std::endl;

    }

    return 0;
}