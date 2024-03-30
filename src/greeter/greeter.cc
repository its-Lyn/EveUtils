#include "colour.h"

#include <cstdlib>
#include <ctime>
#include <sstream> 
#include <iostream>
#include <iomanip>

// Global variable
inline Colours colour_client;

// This is SO
// FUCKING CURSED
std::string get_user() {
    std::string res;

    const char* possible_user = std::getenv("USER");
    if (possible_user == NULL) {
        // NOTE: Throw does NOT throw a fucking string
        // IT THROWS RANDOM GARBAGE
        // Actual throw message "terminate called after throwing an instance of 'int'"
        std::cerr << colour_client.ColourText("No USER variable found.", Colour::Red) << std::endl;
        throw;
    }

    // God help me.
    res = possible_user;
    return res;
}

// This honestly hurts
std::string pad_time(int time) {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << time;

    return oss.str();
}

std::string greet(std::string user) {
    // “Good morning” is generally used from 5:00 to 12:00
    // “Good afternoon” time is from 12:00 to 18:00
    // “Good evening” is often used after 18:00 or when the sun goes down
    // "Good night" is usually used from 00:00 to 5:00

    time_t raw = time(NULL);
    tm *local = localtime(&raw);

    std::string days[7] = {
        "Sunday",    "Monday",    "Tuesday",
        "Wednesday", "Thursday",
        "Friday",    "Saturday"
    };

    std::string greeting;
    if (local->tm_hour < 5)
        greeting = "Sweet Dreams";
    else if (local->tm_hour < 12)
        greeting = "Good morning";
    else if (local->tm_hour < 18)
        greeting = "Good afternoon";
    else
        greeting = "Good evening";

    std::string final;
    final.append(
        colour_client.ColourText(
            greeting + ", " + user + "! ",
            Colour::Magenta
        )
    );

    final.append("Its ");
    final.append(colour_client.ColourText(days[local->tm_wday], Colour::Red));
    
    final.append(
        colour_client.ColourText(
            " " + pad_time(local->tm_hour) + ":" + pad_time(local->tm_min) + "." + pad_time(local->tm_sec),
            Colour::Green 
        )
    );

    final.append(" o'clock.");

    return final;
}

int main(int argc, char **argv) {
    std::string user;

    if (argc != 1) {
        user = argv[1];        
    } else {
        user = get_user();
    }

    std::cout << greet(user) << std::endl;

    return 0;
}