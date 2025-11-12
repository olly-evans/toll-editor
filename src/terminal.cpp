#include <iostream>
#include <termios.h>
#include <limits>

#include "terminal.hpp"

void die(std::string error) {
    std::cout << CLEAR_SCRN;
    std::cout << CURSOR_HOME;
    std::cout << CLEAR_SCROLLBACK_BUF;
    std::cerr << error << NEWLINE;
    exit(EXIT_FAILURE);
}

static struct termios old_t;

void disable_raw_mode(void) {
    /* Restore old terminal i/o settings */
    tcsetattr(0, TCSANOW, &old_t);
}

void enable_raw_mode(void) {
    /* Set terminal to raw mode */
    if (tcgetattr(0, &old_t) == -1) die("enableRawMode() -> tcgetattr");
    atexit(disable_raw_mode);    /* Restore old terminal i/o settings */

    struct termios raw = old_t;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSAFLUSH, &raw) == -1) die("enableRawMode() -> tcgetattr");
}

char read_key() {
    /* Read a singular keypress from cin. */
    char ch{}; 
    std::cin.get(ch); 
    std::cout << "Key: " << ch << NEWLINE; 

    return ch;
}

void process_key() {
    /* Decide what to do with read key from read_key() */
    char ch = read_key();
    switch (ch) {
        case 'q':
            die("Exiting...");
    }
}