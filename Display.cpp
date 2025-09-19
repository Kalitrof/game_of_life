#include "Display.hpp"

Display::Display(int pixelSize, int gameWidth, int gameHeight) : mGameWidth(gameWidth), mGameHeight(gameHeight), mPixelSize(pixelSize), mWindow(sf::VideoMode(gameWidth * pixelSize, gameHeight * pixelSize), "GAME OF LIFE")
{
}

void Display::chargeFrame(Game &game)
{
    mWindow.clear();
    sf::VertexArray cells(sf::Quads);
    cells.resize(4 * mGameWidth * mGameHeight);

    int idx = 0;
    for (int i = 0; i < mGameWidth; i++)
    {
        for (int j = 0; j < mGameHeight; j++)
        {
            if (game.getIndex(i, j))
            {
                float x = i * mPixelSize;
                float y = j * mPixelSize;

                cells[idx + 0].position = {x, y};
                cells[idx + 1].position = {x + mPixelSize, y};
                cells[idx + 2].position = {x + mPixelSize, y + mPixelSize};
                cells[idx + 3].position = {x, y + mPixelSize};

                for (int k = 0; k < 4; k++)
                    cells[idx + k].color = sf::Color::Yellow;

                idx += 4;
            }
        }
    }
    cells.resize(idx);

    mWindow.draw(cells);

    mWindow.display();
}

bool Display::isOpen(bool pause, int speed)
{
    sf::Clock clock;
    while (clock.getElapsedTime().asMilliseconds() < speed || pause)
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mWindow.close();
                return false;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Q:
                case sf::Keyboard::Escape:
                    mWindow.close();
                    return false;
                case sf::Keyboard::Space:
                    pause = !pause;
                default:
                    break;
                }
            }
        }
    }

    return true;
}