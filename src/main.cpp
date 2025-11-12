#include <iostream>

#include "terminal.hpp"

int main(void) {
    enable_raw_mode();
    while (1) {
        process_key();
    }
    return 0;
}