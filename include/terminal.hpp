#pragma once

#include <iostream>

#define CLEAR_SCRN "\x1b[2J"
#define CLEAR_SCROLLBACK_BUF "\x1b[3J"

#define CURSOR_HOME "\x1b[H"

#define NEWLINE "\r\n"

void die(std::string error);
void disable_raw_mode(void);
void enable_raw_mode(void);

char read_key();
void process_key();