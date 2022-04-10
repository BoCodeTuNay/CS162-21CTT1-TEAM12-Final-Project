#pragma once;
#include "Class.h"

Class::Class(char name[MAXNAME], long long class_id = 0) {
    long long MOD = 1333333337;
    long long base = 2017;
    for (int i = 0; i < strlen(name); ++i) {
        class_id = ((class_id * base % MOD) + name[i]) % MOD;
    }
}