#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <vector>
#include <time.h>
#include <random>
#include <omp.h>

class Game
{
public:
    // Builder

    /**
     * @brief Constructs a Game of Life instance with the specified grid dimensions.
     *
     * @param width The width of the game grid. Defaults to 50 if not specified.
     * @param height The height of the game grid. Defaults to 50 if not specified.
     */
    Game(int width = 50, int height = 50);

    // Methods

    /**
     * @brief Calculates the linear index in the underlying data structure for the cell at position (i, j).
     *
     * @param i The row index of the cell.
     * @param j The column index of the cell.
     * @return The linear index corresponding to the (i, j) position.
     */
    inline uint8_t getIndex(int i, int j) const;

    /**
     * @brief Advances the game state to the next generation.
     *
     * Applies the rules of Conway's Game of Life to update the board,
     * computing the next generation based on the current state.
     */
    void nextGen();

    /**
     * @brief Counts the number of neighboring cells for the cell at position (i, j).
     *
     * This function calculates and returns the number of neighboring cells
     * (typically alive cells) surrounding the cell located at the specified
     * row (i) and column (j) in the game grid.
     *
     * @param i The row index of the cell.
     * @param j The column index of the cell.
     * @return int The number of neighboring cells.
     */
    int numbNeighbor(int i, int j);

private:
    // Atributes
    std::vector<uint8_t> mGame, mNext;
    int const mGameWidth;
    int const mGameHeight;
};

#endif