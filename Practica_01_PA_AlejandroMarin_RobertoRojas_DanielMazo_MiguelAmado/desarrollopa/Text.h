#pragma once
#include <string>
#include <GL/glut.h>
#include "Solid.h"

using namespace std;

class Text : public Solid
{


public:
    enum textType { TimesNewRoman10, TimesNewRoman24, Helvetica10, Helvetica12, Helvetica18 };


private:

    string texto;
    textType tipo;

public : 
    // Constructor base
    Text(string text = "NewText", textType type = TimesNewRoman10, Color color = Color())
        : Solid(), texto(text), tipo(type) {
        this->SetColor(color);
    }
    // Constructor con int
    Text(int value, textType type = TimesNewRoman10, Color color = Color())
        : Solid(), texto(std::to_string(value)), tipo(type) {
        this->SetColor(color);
    }

    // Sobrecargar setText para aceptar diferentes tipos
    void setText(const string& text) {
        this->texto = text;
    }

    void setText(int value) {
        this->texto = to_string(value);
    }

    void setText(float value) {
        this->texto = to_string(value);
    }

    void setText(double value) {
        this->texto = to_string(value);
    }

    // Getter para el texto
    inline string getText() const { return this->texto; }

    // Getter para el tipo
    inline textType getType() const { return this->tipo; }

    // Setter para tipo
    inline void setType(const textType& typetoSet) { this->tipo = typetoSet; }

    // Métodos virtuales
    void Render();
    Solid* Clone();
};
