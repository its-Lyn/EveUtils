#include "colour.h"

std::string Colours::ColourText(std::string text, Colour colour) {
    return this->AppendColour(colour) + text + this->AppendColour(Colour::Nothing);
}

// Tf?
std::string Colours::AppendColour(Colour colour) {
    return "\033[1;" + std::to_string((int)colour) + "m";
}