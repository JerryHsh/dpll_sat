#include"random.h"

int generate_random_int(int mod) //generalize a random integer not bigger than mode
{
    return rand()%mod;
}