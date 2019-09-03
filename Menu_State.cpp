//
// Created by alessio on 13/03/19.
//

#include "Menu_State.h"

Menu_State::Menu_State() {          // Controlla che non sia stato cambiato lo stato dall'utente

    pageChanged=false;
}

bool Menu_State::getState() {       // ritorna a quale stato l'utente vuole passare

    return pageChanged;
}

void Menu_State::setState(bool change) {    //Informa che c'è stato un cambiamento di stato

    pageChanged=change;
}

Menu_State::~Menu_State() = default;


