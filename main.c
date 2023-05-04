// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "config.h"
#include "mcp4921.h"

void main(void)
{
    __delay_ms(500);
    
    PIC18F2520();
    
    MCP4921_Init();
    
    // TEST VOLTAGE
    // 1.5      1228
    // 2.5      2048
    // 3.5      2949
    // 5        4095    
    MCP4921_Write( MCP4921_DAC_A |
                //MCP4921_BUF|
                MCP4921_GA|
                //MCP4921_SHDN | 
                2949);
    
    while(1)
    {
        
    }
    
    return;
}