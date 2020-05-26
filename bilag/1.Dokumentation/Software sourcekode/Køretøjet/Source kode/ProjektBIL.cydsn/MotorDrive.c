/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include"MotorDrive.h"
#include"Sensor.h"
#include <project.h>





int dutycycle = 50;
void decreaseSpeed()
{
    stby_Write(1);
    UART_1_PutString("Decreasing speed\r\n");
  
    PWMA_WriteCompare(dutycycle=dutycycle-10);
   
}

void increaseSpeed()
{
    stby_Write(1);
    UART_1_PutString("Increasing speed\r\n");
    
    PWMA_WriteCompare(dutycycle=dutycycle+10);
   
}

void driveForwards()
{
     
    stby_Write(1);
    UART_1_PutString("Set direction: forwards\r\n");
    
    PWMA_WriteCompare(dutycycle);
    Ain1_Write(1);
    Ain2_Write(0);
    
    PWMB_WriteCompare(dutycycle);
    Bin1_Write(1);
    Bin2_Write(0);
    
}

void driveBackwards()
{
    stby_Write(1);
    UART_1_PutString("Set direction: backwards\r\n");
    
    PWMA_WriteCompare(dutycycle);
    Ain1_Write(0);
    Ain2_Write(1);
    
    PWMB_WriteCompare(dutycycle);
    Bin1_Write(0);
    Bin2_Write(1);
    
   
}
void driveLeft()
{
    stby_Write(1);
    UART_1_PutString("Set direction: Left\r\n");
    
    PWMA_WriteCompare(dutycycle);
    Ain1_Write(1);
    Ain2_Write(0);
    
    PWMB_WriteCompare(dutycycle);
    Bin1_Write(0);
    Bin2_Write(1);
    
}
void driveRight()
{
    stby_Write(1);
    UART_1_PutString("Set direction: Right\r\n");
    
    PWMA_WriteCompare(dutycycle);
    Ain1_Write(0);
    Ain2_Write(1);
    
    PWMB_WriteCompare(dutycycle);
    Bin1_Write(1);
    Bin2_Write(0);
    
}

void stop()
{
    stby_Write(0);
    UART_1_PutString("Stop\r\n");
    
    PWMA_WriteCompare(0);
    PWMB_WriteCompare(0);   
}

/* [] END OF FILE */
