#include "includes.h"
#include <fstream>
#include <matdash.hpp>
#include <matdash/boilerplate.hpp>
#include <matdash/minhook.hpp>

#include "hooks.hpp"

void mod_main(HMODULE module) {
#ifdef SHOW_CONSOLE
    AllocConsole();
    std::ofstream conout("CONOUT$", std::ios::out);
    std::ifstream conin("CONIN$", std::ios::in);
    std::cout.rdbuf(conout.rdbuf());
    std::cin.rdbuf(conin.rdbuf());
    std::cout << std::boolalpha;
#endif

    Hooks::init();

#ifdef SHOW_CONSOLE
    std::string line;
    std::getline(std::cin, line);
    MH_Uninitialize();
    conout.close();
    conin.close();
    FreeConsole();
    FreeLibraryAndExitThread(module, 0);
#endif
}
