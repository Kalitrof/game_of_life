#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Game.hpp"
#include "Display.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    int gameWidth = 15;
    int gameHeight = 15;
    float pixelSize = 10;
    bool pause = false;
    int speed = 1;

    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]) == "-p" || std::string(argv[i]) == "--pause")
            pause = true;
        else if (std::string(argv[i]) == "--width" && i + 1 < argc)
            gameWidth = stoi(argv[++i]);
        else if (std::string(argv[i]) == "--height" && i + 1 < argc)
            gameHeight = stoi(argv[++i]);
        else if (std::string(argv[i]) == "--pixel" && i + 1 < argc)
            pixelSize = stoi(argv[++i]);
        else if ((std::string(argv[i]) == "-s" || std::string(argv[i]) == "--speed") && i + 1 < argc)
        {
            speed = stoi(argv[++i]);
            if (speed <= 0)
                speed = 1;
        }
        else if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help")
        {
            std::cout << "Usage: game_of_life [options]\n\n"
                      << "Options:\n"
                      << "  -p, --pause            Pause after each iteration, waiting for user input\n"
                      << "  --width <number>       Number of cells horizontally\n"
                      << "  --height <number>      Number of cells vertically\n"
                      << "  --pixel <number>       Pixel size when displaying cells\n"
                      << "  -s, --speed <ms>       Delay in milliseconds between iterations\n"
                      << "  -h, --help             Show this help message\n";
            exit(0);
        }
    }

    Game game = Game(gameWidth, gameHeight);

    Display display(pixelSize, gameWidth, gameHeight);
    display.chargeFrame(game);
    while (display.isOpen(pause, speed))
    {
        game.nextGen();
        display.chargeFrame(game);
    }
    return 0;
}