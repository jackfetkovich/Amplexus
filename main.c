#include <stdio.h>
#include <inttypes.h>
#include "AmplexusTypes.h"

int main() {
//    Position p = {
//            (uint64_t) 1 >> 4,
//    }
    uint64_t mike = (uint64_t) 1 << 5;
    printf("%d", mike);

    return 0;
}
