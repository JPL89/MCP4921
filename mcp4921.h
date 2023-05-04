// @File		MCP4921.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		04/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef MCP4921_H
#define MCP4921_H

#define MCP4921_CLK             PORTCbits.RC0
#define MCP4921_CS              PORTCbits.RC1
#define MCP4921_SDI             PORTCbits.RC2

#define MCP4921_CLK_TRIS        TRISCbits.RC0
#define MCP4921_CS_TRIS         TRISCbits.RC1
#define MCP4921_SDI_TRIS        TRISCbits.RC2

#define MCP4921_DAC_A           0x8000
#define MCP4921_DAC_B           0x0000
#define MCP4921_BUF             0x4000
#define MCP4921_GA              0x2000
#define MCP4921_SHDN            0x1000

// @Function: Spi_transfer
// @Return: unsigned char
// @Param: unsigned char
// @Description: Send 16-bits data 
void Spi_transfer(unsigned int data)
{
    for(unsigned int mask = 0x8000; mask; mask >>=1)
    {
        MCP4921_CLK = 1;
        
        if(data & mask) 
            MCP4921_SDI = 1;
        else MCP4921_SDI = 0;
        
        MCP4921_CLK = 0;
    }
}

// @Function: MCP4921_Init
// @Return: void
// @Param: void
// @Description: Initialize SPI
void MCP4921_Init(void)
{
    MCP4921_CLK_TRIS = 0;
    MCP4921_CS_TRIS = 0;
    MCP4921_SDI_TRIS = 0;
    
    MCP4921_CS = 1;
}

// @Function: MCP4921_Write
// @Return: unsigned int
// @Param: unsigned int
// @Description: Send data to SPI_transfer
void MCP4921_Write(unsigned int data)
{
    MCP4921_CS = 0;
    Spi_transfer(data);
    MCP4921_CS = 1;
}

#endif // MCP4921_H
