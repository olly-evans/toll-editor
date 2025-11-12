#pragma once

#include <iostream>

void die(std::string error);
void disable_raw_mode(void);
void enable_raw_mode(void);

char read_key();
void process_key();