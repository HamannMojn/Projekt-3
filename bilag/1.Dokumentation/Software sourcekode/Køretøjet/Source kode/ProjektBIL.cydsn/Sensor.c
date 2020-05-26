/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================*/
#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include "Sensor.h"


void writesToUART(float dis)
{    
    
    char disbuff[512];             // Opret char-array
    
    snprintf(disbuff, sizeof(disbuff), "distance: %.1f cm\r\n", dis);  // Læg udskriften i char-array
    
    UART_1_PutString(disbuff);     // Udskriv char-array
}

/* [] END OF FILE */


