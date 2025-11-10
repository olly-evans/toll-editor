#pragma once

#include <iostream>

class Abuf {
    private:
        std::string m_b;
        int m_len;
        int m_capacity;

    public:
    //default value should be 0.
        Abuf(std::string b, int len, int capacity) {
            m_b = b;
            m_len = len;
            m_capacity = capacity;
        }

        void ab_append(std::string append, int size) {
            return;
        }
};