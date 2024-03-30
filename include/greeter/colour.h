#pragma once

#include <iostream>

enum Colour {
    Magenta = 95,
    Green = 32,
    Red = 31,

    Nothing = 0
};


class Colours {
public:
    std::string ColourText(std::string text, Colour colour);

private:
    std::string AppendColour(Colour colour);
};