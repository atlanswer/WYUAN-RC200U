#ifndef _READER_H_
#define _READER_H_

#include <windows.h>

#include <iostream>
#include "termcolor.hpp"
namespace tc = termcolor;

// Control words
extern const char BLOCK0_EN;
extern const char BLOCK1_EN;
extern const char BLOCK2_EN;
extern const char NEEDSERIAL;
extern const char EXTERNKEY;
extern const char NEEDHALT;

// Constant
extern const char* DLLNAME;

// Function prototype
typedef unsigned int (__stdcall *T_READER)(
            unsigned char ctrlword,
            unsigned char afi,
            unsigned char startblock,
            unsigned char blocknum,
            unsigned char *uid,
            unsigned char *revbuf
);
typedef unsigned int (__stdcall *T_WRITER)(
            unsigned char ctrlword,
            unsigned char afi,
            unsigned char startblock,
            unsigned char blocknum,
            unsigned char *uid,
            unsigned char *writebuf
);
typedef unsigned int (__stdcall *T_BEEP)(
    unsigned long xms
);
typedef unsigned int (__stdcall *T_GETDEVNUM)(
    unsigned char *devicenumber
);

class ReaderAction {
    public:
        ReaderAction();
        ~ReaderAction();

        bool isValid(void);
        void beep(unsigned long xms);
    private:
        // Status
        bool runTimeLinkSuccess;
        // DLL instance
        HINSTANCE hinstdll;
        // Read
        T_READER iso15693readex;
        // Write
        T_WRITER piccwriteex15693;
        // Beep
        T_BEEP pcdbeep;
        // Get device number
        T_GETDEVNUM pcdgetdevicenumber;
};

#endif /* _READER_H_*/
