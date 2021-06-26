#include <iostream>

#include "reader.hpp"
#include "termcolor.hpp"

namespace tc = termcolor;

int main(int argc, char** argv) {
    ReaderAction ra;
    if(ra.isValid()) {
        std::cout << "[main] " << tc::green << "DLL link succeed."
            << tc::reset << std::endl;
    } else {
        std::cout << "[main] " << tc::red << "DLL link FAILED."
            << tc::reset << std::endl;
        DWORD dw = GetLastError(); 
        std::cout << "[main] " << tc::red
            << "Errorcode: " << dw
            << tc::reset << std::endl;
        ExitProcess(dw);
    }
    
    std::getchar();
    ra.beep(100);

    return 0;
}
