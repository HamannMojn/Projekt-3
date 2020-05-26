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
#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include "MotorDrive.h"
#include "ServoArm.h"
#include "Sensor.h"

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);
 

    int control_2   = 78;
    int control_3   = 32;
    int control_4   = 30;
    int control_6   = 60;
     
    //Sensor
    int counter = 0;
    float distance = 0.0;
   


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    PWMA_Start();
    PWMB_Start();
    stby_Write(0);
    
    //Sensor
    Timer_1_Start();
    
    UART_1_PutString("DC-Motor-PWM application started\r\n");
    UART_1_PutString("0: Stop\r\n");
    UART_1_PutString("w: Drive forwards\r\n");
    UART_1_PutString("s: Drive backwards\r\n");
    UART_1_PutString("a: Drive left\r\n");
    UART_1_PutString("s: Drive right\r\n");
    UART_1_PutString("1: Increase speed\r\n");
    UART_1_PutString("2: Decrease speed\r\n");
    
    //Servo arm
    PWM_2_Start();
    PWM_3_Start();
    PWM_4_Start();
    PWM_6_Start();
   
    PWM_2_WriteCompare(control_2);
    PWM_3_WriteCompare(control_3);
    PWM_4_WriteCompare(control_4);
    PWM_6_WriteCompare(control_6);
    

    
    for(;;)
    {
        while(Echo_Read()==0){
       Control_Reg_1_Write(1);
       CyDelayUs(10);
       Control_Reg_1_Write(0);
       CyDelay(1);     
       }
       while (Echo_Read()==1){}
        
      counter = 65535 - Timer_1_ReadCounter();
      distance= (float)counter/58.0;
      writesToUART(distance);
    }
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case '2' :
        {
            decreaseSpeed();
        }
        break;
        case '1' :
        {
            increaseSpeed();
        }
        break;
        case 'w' :
        {
            //writesToUART(distance);
            driveForwards();
        }
        break;
        case 's' :
        {
            driveBackwards();
        }
        break;
         case 'a' :
        {
            driveLeft();
        }
        break;
         case 'd' :
        {
            driveRight();
        }
        break;
         case '3' :
        {
            if(distance <= 30)
            {
                LOFT();
            }
            
            else{}
        }
        break;
         case '4' :
        {
            SANK();
        }
        break;
        case '0' :
        {
            stop();
            
        }
        break;
        default :
        {
            // nothing
        }
        break;
    }
}

/* [] END OF FILE */

