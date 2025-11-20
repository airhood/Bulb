#ifdef _WIN32
#define SLENT_API __declspec(dllexport)
#else
#define SLENT_API
#endif

#include <iostream>
#include <string>

extern "C" {
    SLENT_API void print(std::string str) {
        printf("%s", str.c_str());
    }

    SLENT_API void scan(std::string& buffer) {
        static std::string leftover;
        std::string input;

        if (!leftover.empty()) {
            size_t spacePos = leftover.find(' ');
            if (spacePos != std::string::npos) {
                buffer = leftover.substr(0, spacePos);
                leftover = leftover.substr(spacePos + 1);
            }
            else {
                buffer = leftover;
                leftover.clear();
            }
            return;
        }

        std::getline(std::cin, input);
        if (std::cin.eof() || std::cin.fail()) {
            std::cerr << "Error: Input exceeded maximum length or invalid input." << std::endl;
            buffer.clear();
            return;
        }

        size_t spacePos = input.find(' ');
        if (spacePos != std::string::npos) {
            buffer = input.substr(0, spacePos);
            leftover = input.substr(spacePos + 1);
        }
        else {
            buffer = input;
        }
    }

    SLENT_API void scanln(std::string& buffer) {
        std::getline(std::cin, buffer);
    }

    SLENT_API char readChar() {
        return std::cin.get();
    }
}
