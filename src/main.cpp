#include <iostream>

#include "terminal.hpp"

int main(void) {
    enable_raw_mode();
    process_key();
    return 0;
}