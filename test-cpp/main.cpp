/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Masamichi
 *
 * Created on 2016/01/22, 0:56
 */

#include <cstdlib>
#include "MC68000.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    printf("sizeof(long long)=%d\n", sizeof(long long));
    printf("sizeof(long)=%d\n", sizeof(long));
    printf("sizeof(int)=%d\n", sizeof(int));
    printf("sizeof(short)=%d\n", sizeof(short));
    
    MC68000* processor = new MC68000();
    return 0;
}

