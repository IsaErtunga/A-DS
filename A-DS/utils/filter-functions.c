//
//  filter-functions.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-03-12.
//

#include "filter-functions.h"

int gt(int a, int b) {
    if (a > b) return 1;
    return 0;
}

int gte(int a, int b) {
    if (a >= b) return 1;
    return 0;
}

int lt(int a, int b) {
    if (a < b) return 1;
    return 0;
}

int lte(int a, int b) {
    if (a <= b) return 1;
    return 0;
}
