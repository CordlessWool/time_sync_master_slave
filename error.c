//
// Created by wolle on 12.07.17.
//

#include <stdio.h>
#include <stdlib.h>
#include "error.h"


void die(char * s){
    perror(s);
    exit(1);
}