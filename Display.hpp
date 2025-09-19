#ifndef DISPLAY_INCLUDED
#define DISPLAY_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.hpp"

class Display
{
public:
    // Builder

    /**
     * @brief Constructs a Display object for visualizing the Game of Life grid.
     *
     * @param pixel_size The size (in pixels) of each cell in the display. Defaults to 10.
     * @param game_width The number of cells horizontally in the game grid. Defaults to 50.
     * @param game_height The number of cells vertically in the game grid. Defaults to 50.
     */
    Display(int pixel_size = 10, int game_width = 50, int game_height = 50);

    // Methods

    /**
     * @brief Updates the display with the current state of the game.
     *
     * This function processes the given Game object and updates the display
     * to reflect the current frame of the Game of Life simulation.
     *
     * @param game Reference to the Game object containing the current state.
     */
    void chargeFrame(Game &game);

    /**
     * @brief Checks if the display window should remain open.
     *
     * This function determines whether the display window is still open,
     * potentially taking into account the pause state and the current speed.
     *
     * @param pause Indicates whether the game is currently paused.
     * @param speed The current speed setting of the game.
     * @return true if the display window should remain open, false otherwise.
     */
    bool isOpen(bool pause, int speed);

private:
    // Attributes
    sf::RenderWindow mWindow;
    int const mGameWidth;
    int const mGameHeight;
    float const mPixelSize;
};

#endif