#include "reader.hpp"

const char BLOCK0_EN    {0x01};
const char BLOCK1_EN    {0x02};
const char BLOCK2_EN    {0x04};
const char NEEDSERIAL   {0x08};
const char EXTERNKEY    {0x10};
const char NEEDHALT     {0x20};

const char* DLLNAME     {"OUR_MIFARE64.dll"};

ReaderAction::ReaderAction() :
    runTimeLinkSuccess{false},
    hinstdll{NULL},
    iso15693readex{NULL},
    piccwriteex15693{NULL},
    pcdbeep{NULL},
    pcdgetdevicenumber{NULL} {
    // Get a handle to the DLL module.
    hinstdll = LoadLibrary(TEXT(DLLNAME));
    // Get the function address.
    if(hinstdll != NULL) {
        iso15693readex = (T_READER) GetProcAddress(
            hinstdll, "iso15693readex"
        );
        piccwriteex15693 = (T_WRITER) GetProcAddress(
            hinstdll, "piccwriteexiso15693"
        );
        pcdbeep = (T_BEEP) GetProcAddress(hinstdll, "pcdbeep");
        pcdgetdevicenumber = (T_GETDEVNUM) GetProcAddress(
            hinstdll, "pcdgetdevicenumber"
        );
        runTimeLinkSuccess = true;
        std::cout << "[ReaderAction] " << tc::green
            << "Constructor succeed." << tc::reset << std::endl;
    } else {
        runTimeLinkSuccess = false;
    }
}

ReaderAction::~ReaderAction() {
    FreeLibrary(hinstdll);
    std::cout << "[ReaderAction] " << tc::green
        << "Destructor succeed." << tc::reset << std::endl;
}

bool ReaderAction::isValid(void) {
    return runTimeLinkSuccess;
}

void ReaderAction::beep(unsigned long xms) {
    unsigned char status = pcdbeep(xms);
    if(status != 0) {
        std::cout << "[ReaderAction::beep()] " << tc::red
        << "Errorcode: " << int(status) << tc::reset << std::endl;
    }
}
