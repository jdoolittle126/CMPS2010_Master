#pragma once
#include <cmath>
#include <cstdlib>

double rfloat()
{
    return (rand() % 1025) / 1024.0;
}

double lerp(double t, double a, double b)
{
    return ((1.0 - t) * a) + (t * b);
}

double clamp(double t, double min, double max)
{
    if (t < min) t = min;
    if (t > max) t = max;
    return t;
}

// Scene3: bouncing balls of varying bounciness
class MyScene : public Scene
{
    protected:
        const double gravity = -9.81;
        // first dimension is for the row, second dimension contains 
        // position in [0], velocity in [1], and bounciness in [2]
        double physics[WIDTH][3];

        bool firstBounce = false;

        virtual void init()
        {
            Scene::init();

            for(int x = 0; x < WIDTH; x++)
            {
                physics[x][0] = HEIGHT - 1;
                physics[x][1] = 0;
                physics[x][2] = rfloat() * 0.99;
            }
        }

        // Called once every frame. 
        virtual void update()
        {
            clearBoard();

            int restCount = 0;

            double dt = SPF();

            for(int x = 0; x < WIDTH; x++)
            {
                int y = (int)physics[x][0];
                if (y < 0 ) y = 0;
                else if (y >= HEIGHT) y = HEIGHT - 1;

                board[y][x] = 'o';

                double oldv = physics[x][1];
                double newv = oldv + (gravity * dt);
                double oldp = physics[x][0];
                double newp = oldp + (newv * dt);

                if (newp <= 0)
                {
                    newp = abs(newp);
                    newv = -newv * physics[x][2];
                    physics[x][2] *= 0.75;

                    firstBounce = true;
                }

                physics[x][0] = newp;
                physics[x][1] = newv;

                if (abs(newp) <= 1.0 && abs(newv) <= 1.0) restCount++;
            }
            
            if (firstBounce && restCount == WIDTH) shouldContinue = false;

            // Keep this call to the parent's version of update()
            Scene::update();
        }

        // Writes the contents of the board to the screen
        virtual void showBoard()
        {
            printf("\x1b[H");
            for(int y = 0; y < HEIGHT; y++)
            {
                for(int x = 0; x < WIDTH; x++)
                {
                    putchar(board[HEIGHT - 1 - y][x]);
                }
                putchar('\n');
            }
        }
};