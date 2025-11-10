#include <iostream>

#define CLEAR_SCRN "\x1b[2J"
#define CLEAR_SCROLLBACK_BUF "\x1b[3J"

#define CURSOR_HOME "\x1b[H"


void die(std::string error) {
    std::cout << CLEAR_SCRN;
    std::cout << CURSOR_HOME;
    std::cout << CLEAR_SCROLLBACK_BUF;
    std::cerr << error << std::endl;
}