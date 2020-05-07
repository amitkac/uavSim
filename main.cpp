#include <iostream>
#include <stdio.h>
#include "Sim.h"
#include "uavObject.h"
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

struct positions
{
    vector<float> xUpdate;
    vector<float> yUpdate;
};

positions readCsv(const char *file);

Sim *sim = nullptr;
int main()
{

    const int FPS = 60;                // 60 frames per second
    const int frameDelay = 1000 / FPS; // max time between frames

    Uint32 frameStart;
    int frameTime;
    // while (game running)
    // {
    //     handle input;
    //     update all objects->positions;
    //     render changes to display
    // }

    sim = new Sim;

    sim->init("UAV motion for Dryden wind model", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
              SCREEN_WIDTH, SCREEN_HEIGHT, false, 0);

    // game loop
    positions dataUpdates = readCsv("endpoint.csv");
    cout << dataUpdates.xUpdate.size() << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << dataUpdates.xUpdate[i] << endl;
    }
    int counter = 0;
    while (sim->running())
    {

        frameStart = SDL_GetTicks();
        sim->handleEvents();

        // put loop here get data from csv
        if (counter < dataUpdates.xUpdate.size())
        {

            sim->update(dataUpdates.xUpdate[counter] * 100, dataUpdates.yUpdate[counter] * 100);
            cout << "(" << counter << flush;
            cout << "," << setprecision(10) << dataUpdates.xUpdate[counter] << flush;
            cout << "," << setprecision(10) << dataUpdates.yUpdate[counter] << ")" << endl;
        }
        else
        {
            sim->update(0, 0);
        }

        sim->render();
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
        counter++;
    }
    sim->clean();
    delete sim;

    return 0;
}

positions readCsv(const char *file)
{
    positions t;
    ifstream fin;
    fin.open(file);
    if (!fin.is_open())
    {
        exit(EXIT_FAILURE);
    }

    vector<float> xPoint;
    vector<float> yPoint;

    string line;
    vector<string> vec;
    getline(fin, line); //skip the header
    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }

        istringstream iss(line);
        string lineStream;
        string::size_type sz;
        vector<float> row;
        while (getline(iss, lineStream, ','))
        {
            // cout << lineStream << endl;
            row.push_back(stof(lineStream, &sz));
        }
        xPoint.push_back(row[10]);
        yPoint.push_back(row[11]);
    }

    // cout << "pos: (" << setprecision(10) << xPos[counter] << "," << ypos[counter] << ")" << endl;
    t.xUpdate = xPoint;
    t.yUpdate = yPoint;

    fin.close();

    // t.x = 10.04;
    // t.y = 89.99;

    return t;
}

// void loadBmpImg()
// {

//     SDL_Surface *screenBack = NULL;
//     screenBack = SDL_GetWindowSurface(window);

//     SDL_Surface *background = SDL_LoadBMP("img/back.bmp");
//     SDL_BlitSurface(background, NULL, screenBack, NULL);
//     SDL_UpdateWindowSurface(window);
// }

// to run->
//  g++ -g main.cpp Game.cpp TextManager.cpp GameObject.cpp blitImage.cpp  -o gameTest -lSDL2 -lSDL2_image
