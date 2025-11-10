#include <iostream>
#include <termios.h>

#define CLEAR_SCRN "\x1b[2J"
#define CLEAR_SCROLLBACK_BUF "\x1b[3J"

#define CURSOR_HOME "\x1b[H"


void die(std::string error) {
    std::cout << CLEAR_SCRN;
    std::cout << CURSOR_HOME;
    std::cout << CLEAR_SCROLLBACK_BUF;
    std::cerr << error << std::endl;
}

static struct termios old_t, new_t;

void disable_raw_mode(void) {
    /* Restore old terminal i/o settings */
    tcsetattr(0, TCSANOW, &old_t);
}

void enable_raw_mode(void) {
    if (tcgetattr(0, &old_t) == -1) die("enableRawMode() -> tcgetattr");
    atexit(disable_raw_mode);


    struct termios new_t = old_t;
    new_t.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    new_t.c_oflag &= ~(OPOST);
    new_t.c_cflag |= (CS8);
    new_t.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    new_t.c_cc[VMIN] = 0;
    new_t.c_cc[VTIME] = 1;

    if (tcsetattr(0, TCSAFLUSH, &new_t) == -1) die("enableRawMode() -> tcgetattr");
}

