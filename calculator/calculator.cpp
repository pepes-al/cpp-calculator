#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

bool ReadNumber(Number& n) {
    if (!(std::cin >> n)) {
        std::cerr << "Error: Numeric operand expected";
        return false;
    }

    return true;
}

bool RunCalculatorCycle() {

    std::string operand;
    Number number;
    Number memory;
    bool is_memory_empty = true;

    if (!ReadNumber(number)) {
    return false;
    }

    while (std::cin >> operand) {

        Number num = 0;

        if (operand == "+") {
            if (!ReadNumber(num)) {
            return false;
            }
            number += num;
        }

        else if (operand == "-") {
            if (!ReadNumber(num)) {
            return false;
            }
            number -= num;
        }

        else if (operand == "*") {
            if (!ReadNumber(num)) {
            return false;
            }
            number *= num;
        }

        else if (operand == "/") {
            if (!ReadNumber(num)) {
            return false;
            }
            number /= num;
        }

        else if (operand == "**") {
            if (!ReadNumber(num)) {
            return false;
            }
            number = pow(number, num);
        }

        else if (operand == "q") {
            return true;
        }

        else if (operand == "=") {
            std::cout << number << std::endl;
        }

        else if (operand == ":") {
            if (!ReadNumber(num)) {
            return false;
            }
            number = num;
        }

        else if (operand == "c") {
            number = 0;
        }

        else if (operand == "s") {
            is_memory_empty = false;    
            memory = number;
        }

        else if (operand == "l") {
            if (!is_memory_empty) {
                number = memory;
            }
            else {
                std::cerr << "Error: Memory is empty";
                return false;
            }
        }

        else {
            std::cerr << "Error: Unknown token " << operand;
            return false;
        }
    }

    return false;

}// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
