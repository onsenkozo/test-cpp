/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MC68000.cpp
 * Author: Masamichi
 * 
 * Created on 2016/01/16, 23:31
 */

#include "MC68000.h"
#include <stdlib.h>
#include <list>

/**
 * Constructor
 */
MC68000::MC68000() {
    this->instructionset = (FunctionFunc *)calloc(C_INST_ARRAYSIZE, sizeof(FunctionFunc));

    // Assign Blocks
    InitBlocks();
}

/**
 * Copy Constructor
 * @param orig
 */
MC68000::MC68000(const MC68000& orig) {
}

/**
 * Destructor
 */
MC68000::~MC68000() {
    if (this->instructionset != NULL) {
        free(this->instructionset);
    }
}

/**
 * Assign Block
 */
void MC68000::InitBlocks() {
    this->AssignInstruction(string("1100aaa10000bccc"), (FunctionFunc)(MC68000::ABCD));
    this->AssignInstruction(string("1101aaabbbcccddd"), (FunctionFunc)(MC68000::ADD));
    this->AssignInstruction(string("a101aaabbbcccddd"), (FunctionFunc)(MC68000::ADD));
}

/**
 * Assign Instruction
 * @param pattern
 * @param instructionset
 */
void MC68000::AssignInstruction(string pattern, FunctionFunc instructionset) {
    // Count Bit Length and Bit Mapping
    list<int> mappos;
    int bits = 0;
    int val = 0;
    int map = 0;
    for (int i = 0; i < pattern.length(); i++) {
        if (pattern[i] == '1' || pattern[i] == '0') {
            if (map > 0) {
                mappos.push_back(map);
                map = 0;
            }
            val++;
        } else {
            if (i == 0) {
                mappos.push_back(0);               
            }
            if (val > 0) {
                mappos.push_back(val);
                val = 0;
            }
            map++;
            bits++;
        }
    }
    if (map > 0) {
        if (map == pattern.length()) {
            mappos.push_back(0);
        }
        mappos.push_back(map);
    }
    if (val > 0) {
        mappos.push_back(val);
    }

    printf("sizeof(FunctionFunc)=%d\n", sizeof(FunctionFunc));

    list<int>::const_iterator itEnd = mappos.end();
    for (list<int>::const_iterator it = mappos.begin(); it != itEnd; ++it) {
        printf("%d\n", *it);    
    }

    // Assignation
    for (int i = 0; i < ( 2 ^ bits - 1); i++) {
        
    }
    
    (this->*instructionset)();
}

/**
 * Add Decimal with Extend
 * Source10 + Destination10 + X → Destination
 */
void MC68000::ABCD() {
    // TODO: 
    printf("ABCD.sizeof(FunctionFunc)=%d\n", sizeof(FunctionFunc));
}

/**
 * Add
 * Source + Destination → Destination
 */
void MC68000::ADD() {
    printf("ADD.sizeof(FunctionFunc)=%d\n", sizeof(FunctionFunc));
    
}
