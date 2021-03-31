#pragma once

#include <stdio.h>
#include <unistd.h>

using namespace std;

// An animated scene, and the base class for this assignment.
// This can be used to display text on the console in repeated intervals, like
// you would use for a game. In fact, it's mainly same code I used in example 
// 8-2.cpp to visualize the differences between bubble sort and selection sort. 
class Scene
{
protected:
    static const int WIDTH = 80;
    static const int HEIGHT = 23;

    // The 2D array that stores the board information. Change the values it
    // holds to change what the scene shows on the screen.
    char board[HEIGHT][WIDTH];

    // You can set this to false in update() to make the scene end.
    bool shouldContinue = true;

    // Keeps track of how many times update() has been called.
    unsigned long frame = 0;

    // If the scene runs for more than this many frames, it will stop.
    // You can set this variable in init() to change the runtime length.
    unsigned long maxFrames = 1000;

    // Frames per second: how many times the scene should update per second.
    // Lower values means fewer updates per second, higher means more.
    // You can set this variable in init( to change the runtime speed.
    double FPS = 60.0;

    // FPS implicitly defines seconds per frame as the inverse
    double SPF() { return 1.0 / FPS; }

    // Writes the contents of the board to the screen
    virtual void showBoard()
    {
        printf("\x1b[H");
        for(int y = 0; y < HEIGHT; y++)
        {
            for(int x = 0; x < WIDTH; x++)
            {
                putchar(board[y][x]);
            }
            putchar('\n');
        }
    }

    // Puts a blank space in every position on the board
    void clearBoard(int xstart = 0, int xend = WIDTH, int ystart = 0, 
        int yend = HEIGHT)
    {
        for(int y = ystart; y < yend; y++)
        {
            for(int x = xstart; x < xend; x++)
            {
                board[y][x] = ' ';
            }
        }
    }

    // Makes the program sleep by the amount of seconds passed in.
    // This gets called in update() to make the scene display more smoothly.
    void sleepFor(double seconds)
    {
        // Convert seconds to microseconds for usleep
        unsigned int ns = (unsigned int)(1000000.0 * seconds);
        usleep(ns);
    }

    // Sets up the scene before it runs
    virtual void init()
    {
        clearBoard();
    }

    // Called to update the scene by a fixed amount of time. 
    virtual void update()
    {
        sleepFor(SPF());
        frame++;
        
        if (frame > maxFrames) shouldContinue = false;
    }
    

public:
    virtual ~Scene() { }

    // The function that sets up and runs the scene. Very concise, but powerful.
    void run()
    {
        init();                     // initialize the scene
        while (shouldContinue)      // start the scene in a loop
        {
            update();               // call update once per loop
            showBoard();            // then see the changes with showBoard()
        }
    }
};
