#include "Game.hpp"

Game::Game(int width, int height) : mGameWidth(width), mGameHeight(height)
{
    mGame.resize(mGameWidth * mGameHeight, 0);
    srand(time(0));
    int numbTotalPixel = mGameHeight * mGameWidth;
    int numbPixel = numbTotalPixel / 3;
    int a, b;
    for (int i = 0; i < numbPixel; i++)
    {
        a = rand() % mGameWidth;
        b = rand() % mGameHeight;
        mGame[b * mGameWidth + a] = 1;
    }
    mNext = mGame;
};

inline uint8_t Game::getIndex(int i, int j) const
{
    return mGame[j * mGameWidth + i];
}

int Game::numbNeighbor(int i, int j)
{
    int numb = 0;
    int left = (i - 1 + mGameWidth) % mGameWidth;
    int right = (i + 1) % mGameWidth;
    int up = (j - 1 + mGameHeight) % mGameHeight;
    int down = (j + 1) % mGameHeight;
    numb = getIndex(left, up) + getIndex(i, up) + getIndex(right, up) +
           getIndex(left, j) + getIndex(right, j) +
           getIndex(left, down) + getIndex(i, down) + getIndex(right, down);
    return numb;
}

void Game::nextGen()
{
#pragma omp parallel for collapse(2)
    for (int i = 0; i < mGameWidth; i++)
    {
        for (int j = 0; j < mGameHeight; j++)
        {
            int numbNeigh = this->numbNeighbor(i, j);
            bool cell = this->getIndex(i, j);
            mNext[j * mGameWidth + i] = (numbNeigh == 3) || (numbNeigh == 2 && cell);
        }
    }
    mGame.swap(mNext);
}