//
// Created by alessio on 01/12/18.
//

#include "Control.h"
#include "Load_Exception.h"

Control::Control() = default;

int Control::SetControl(RenderWindow &window, Error &error, int num_circuit, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    //Metodo che richiama ricorsivamente lo specifico metodo per i controlli a seconda del circuito nel quale ci troviamo

    switch (num_circuit) {

        case 1:
            return CircuitOne(window, error, y_CarPlayer, x_CarPlayer, degree_CarPlayer);

        case 3:
            return CircuitThree(window, error, y_CarPlayer, x_CarPlayer, degree_CarPlayer);

        case 2:
            return CircuitTwo(window, error, y_CarPlayer, x_CarPlayer, degree_CarPlayer);

        default: break;
    }

    return -1;
}

int Control::CircuitOne(RenderWindow &window, Error &error, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    // Metodo che attraverso una bitmap colorata gestisce i controlli sulla velocità della macchina dell'utente

    //// BIANCO -> velocità NORMALE

    //// ROSSO -> la velocità viene DIMINUITA (casi: fuori pista su erba o sabbia, pitlane)

    //// NERO -> la velocità si AZZERA istantaneamente (caso: ci troviamo di fronte ad un ostacolo come muro, gomme, tribune)

    x_CarPlayer= static_cast<float>(x_CarPlayer + 38 * sin((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer - 38 * cos((degree_CarPlayer * M_PI) / 180));

    try {
        if (image1 == 0) {
            if(!circuit_one.loadFromFile("Control/control1.bmp"))
                throw Load_exception("Load_exception:Impossibile caricare file");
            image1 = 1;
        }
    }
    catch(Load_exception e){
        window.close();
        error.Check_Image(window);
    }

    red=circuit_one.getPixel(100,230);
    black=circuit_one.getPixel(290,220);
    color=circuit_one.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color== red){
        return 1;
    }
    if(color == black){
        return 2;
    }
    return 0;

}

int Control::CircuitTwo(RenderWindow &window, Error &error, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    // Metodo che attraverso una bitmap colorata gestisce i controlli sulla velocità della macchina dell'utente

    //// BIANCO -> velocità NORMALE

    //// ROSSO -> la velocità viene DIMINUITA (casi: fuori pista su erba o sabbia, pitlane)

    //// NERO -> la velocità si AZZERA istantaneamente (caso: ci troviamo di fronte ad un ostacolo come muro, gomme, tribune)

    x_CarPlayer= static_cast<float>(x_CarPlayer + 38 * cos((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer + 38 * sin((degree_CarPlayer * M_PI) / 180));

    try {
        if (image2 == 0) {
            if (!circuit_two.loadFromFile("Control/control2.bmp"))
                throw Load_exception("Load_exception:Impossibile caricare file");
            image2 = 1;
        }
    }
    catch(Load_exception e) {
        window.close();
        error.Check_Image(window);
    }

    red=circuit_two.getPixel(947,51);
    black=circuit_two.getPixel(1,1);
    color=circuit_two.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == red){
        return 1;
    }
    if(color == black){
        return 2;
    }
    return 0;
}

int Control::CircuitThree(RenderWindow &window, Error &error, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    // Metodo che attraverso una bitmap colorata gestisce i controlli sulla velocità della macchina dell'utente

    //// BIANCO -> velocità NORMALE

    //// ROSSO -> la velocità viene DIMINUITA (casi: fuori pista su erba o sabbia, pitlane)

    //// NERO -> la velocità si AZZERA istantaneamente (caso: ci troviamo di fronte ad un ostacolo come muro, gomme, tribune)

    x_CarPlayer= static_cast<float>(x_CarPlayer - 38 * cos((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer - 38 * sin((degree_CarPlayer * M_PI) / 180));

    try {
        if (image3 == 0) {
            if (!circuit_three.loadFromFile("Control/control3.bmp"))
                throw Load_exception("Load_exception:Impossibile caricare file");
            image3 = 1;
        }
    }
    catch(Load_exception e){
        window.close();
        error.Check_Image(window);
    }

    green=circuit_three.getPixel(807,422);
    black=circuit_three.getPixel(5,5);
    color=circuit_three.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == black){
        return 2;
    }

    if(color == green){
        return 1;
    }

    return 0;
}

int Control::SetControlReverse(int numcircuit, float y_CarPlayer, float x_CarPlayer) {

    //Metodo che richiama ricorsivamente lo specifico metodo per i controlli sulla retromarcia a seconda del circuito nel quale ci troviamo

    switch(numcircuit) {

        case 1:
            return CircuitOneReverse(y_CarPlayer, x_CarPlayer);

        case 2:
            return CircuitTwoReverse(y_CarPlayer, x_CarPlayer);

        case 3:
            return CircuitThreeReverse(y_CarPlayer, x_CarPlayer);
        default: break;
    }

}

int Control::CircuitOneReverse(float y_CarPlayer, float x_CarPlayer) {

    // Metodo che attraverso una bitmap colorata gestisce i controlli sulla velocità della macchina dell'utente

    //// BIANCO -> velocità NORMALE

    //// ROSSO -> la velocità viene DIMINUITA (casi: fuori pista su erba o sabbia, pitlane)

    //// NERO -> la velocità si AZZERA istantaneamente (caso: ci troviamo di fronte ad un ostacolo come muro, gomme, tribune)

    red=circuit_one.getPixel(100,230);
    black=circuit_one.getPixel(290,220);
    color=circuit_one.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color== red){
        return 1;
    }
    if(color == black){
        return 2;
    }
    return 0;
}

int Control::CircuitTwoReverse(float y_CarPlayer, float x_CarPlayer) {

    // Metodo che attraverso una bitmap colorata gestisce i controlli sulla velocità della macchina dell'utente

    //// BIANCO -> velocità NORMALE

    //// ROSSO -> la velocità viene DIMINUITA (casi: fuori pista su erba o sabbia, pitlane)

    //// NERO -> la velocità si AZZERA istantaneamente (caso: ci troviamo di fronte ad un ostacolo come muro, gomme, tribune)

    red=circuit_two.getPixel(947,51);
    black=circuit_two.getPixel(1,1);
    color=circuit_two.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == red){
        return 1;
    }
    if(color == black){
        return 2;
    }
    return 0;
}

int Control::CircuitThreeReverse(float y_CarPlayer, float x_CarPlayer) {

    // Metodo che attraverso una bitmap colorata gestisce i controlli sulla velocità della macchina dell'utente

    //// BIANCO -> velocità NORMALE

    //// VERDE -> la velocità viene DIMINUITA (casi: fuori pista su erba o sabbia, pitlane)

    //// NERO -> la velocità si AZZERA istantaneamente (caso: ci troviamo di fronte ad un ostacolo come muro, gomme, tribune)

    color=circuit_three.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == black){
        return 2;
    }

    if(color == green){
        return 1;
    }

    return 0;
}

int Control::CarControl(int numcircuit) {

    Color C_Red, C_Black, C_Color;
    Image Circuit_Bit;
    bool flag=true;

    switch (numcircuit) {
        case 1:
            if (!Circuit_Bit.loadFromFile("Control/control1.bmp"))
                cout<<"error"<<endl;
            C_Red=Circuit_Bit.getPixel(100,230);
            C_Black=Circuit_Bit.getPixel(290,220);
            break;
        case 2:
            if (!Circuit_Bit.loadFromFile("Control/control2.bmp"))
                cout<<"error"<<endl;
            C_Red=Circuit_Bit.getPixel(947,51);
            C_Black=Circuit_Bit.getPixel(1,1);
            break;
        case 3:
            if (!Circuit_Bit.loadFromFile("Control/control3.bmp"))
                cout<<"error"<<endl;
            flag=false;
            C_Black=Circuit_Bit.getPixel(5,5);
            break;
        default: break;
    }

    C_Color=Circuit_Bit.getPixel(static_cast<unsigned int>(x_Car), static_cast<unsigned int>(y_Car));

    if(flag) {
        if (C_Color == C_Red) {
            return 1;
        }
    }

    if(C_Color == C_Black){
        return 2;
    }

    return 0;
}

void Control::setControl(float x, float y) {
    x_Car=x;
    y_Car=y;
}
