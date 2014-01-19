#include <stdint.h>



/// main pixel format for palettes and output
#pragma pack(push, 1)
typedef union _BGRA {
    uint8_t chan[4];
    struct {
        uint8_t B, G, R, A;
    };
    uint32_t BGRA;
} BGRA;
#pragma pack(pop)

/// "standard" GIF animation type
typedef struct _ASTD {
    uint8_t *bptr; /// index data storage
    uint32_t xdim, /// frame width
             ydim, /// frame height
             fcnt, /// frame count
            *time; /// frame delays
    BGRA    *bpal; /// palette
} ASTD;



ASTD *MakeDataAnimStd(char *data, long size);
ASTD *MakeFileAnimStd(char *name);
void FreeAnimStd(ASTD **anim);

/// external functions, have to be implemented or imported
char *LoadFile(char *name, long *size);
