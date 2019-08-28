//
// Created by alessio on 16/03/19.
//

#ifndef ALL_ULTIMO_GAS_CHAMPIONSHIP_PAGE_H
#define ALL_ULTIMO_GAS_CHAMPIONSHIP_PAGE_H

#include "Menu_State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"

using namespace sf;
using namespace std;

class Championship_Page : public Menu_State{

public:


    Championship_Page(RenderWindow &window, Error &error);

    ~Championship_Page();

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

private:

    int chooseCar, Type_race;
    Texture T_championship[11];
    Sprite S_championship[11];
};


#endif //ALL_ULTIMO_GAS_CHAMPIONSHIP_PAGE_H
