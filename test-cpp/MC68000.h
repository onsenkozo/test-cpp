/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MC68000.h
 * Author: Masamichi
 *
 * Created on 2016/01/16, 23:31
 */

#ifndef MC68000_H
#define MC68000_H

#include <string>
using namespace std;

#define C_INST_ARRAYSIZE 65536
#define C_INSTBLOCK_ARRAYSIZE 16

class MC68000 {
public:
    MC68000();
    MC68000(const MC68000& orig);
    virtual ~MC68000();
private:
    typedef void (MC68000::*FunctionFunc)();
    FunctionFunc *instructionset;

    void InitBlocks();
    
    /**
     * Assign Instruction
     * @param pattern
     * @param instructionset
     */
    void AssignInstruction(string pattern, FunctionFunc instructionset);
    
    /**
     * 
     */
    void ABCD();
    
    /**
     * 
     */
    void ADD();
    
};

#endif /* MC68000_H */

