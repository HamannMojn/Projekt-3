/* ========================================
 *
 * Copyright Mathias Segoufin, Year 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdbool.h>
#include <unistd.h>

// Prototype for interrupt-handler.
CY_ISR_PROTO(ISR_UART_rx_handler);

bool LEDstatus = false;
char c;
int ASCIIvalue = 0;

//Funktioner til styring
void LEDon();
void LEDoff();

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Starter UART
    UART_1_Start();
    
    UART_1_PutString("PSoC UART Receiver program has started. \r\n");
    UART_1_PutString("Sending a 1 from the RPi will activate the LED and sending a 0 will deactivate the LED. \r\n");
    
    //Starter Interrupt
    isr_1_StartEx(ISR_UART_rx_handler);

    for(;;)
    {
        if(LEDstatus == true)        //Toggler en LED på PSoC. Kan laves om til en funktion som eksempelvis løfter et objekt.
        {
            Pin_LED_Write(1);
            //while(!objektsamletop) //Pseudokode til at sende besked tilbage til RPI og videre til PC (GUI) når objekt er samlet op.
            //{                      //Pseudokode til at sende besked tilbage til RPI og videre til PC (GUI) når objekt er samlet op.
            //  //do nothing         //Pseudokode til at sende besked tilbage til RPI og videre til PC (GUI) når objekt er samlet op.
            //}                      //Pseudokode til at sende besked tilbage til RPI og videre til PC (GUI) når objekt er samlet op.
            //UART_1_PutChar("l");   //Sender "l" til RPI for "løftet".
        }
        else if(LEDstatus == false) //Toggler en LED på PSoC. Kan laves om til en funktion som eksempelvis sænker et objekt.
        {
            if(Pin_LED_Read() == 1)
            {
                Pin_LED_Write(~Pin_LED_Read());
                //while(!sænket)        //Pseudokode til at sende besked tilbage til RPI og videre til PC (GUI) når objekt er sænket.
                //{                     //Pseudokode til at sende besked tilbage til RPI og videre til PC (GUI) når objekt er sænket.                      
                //  //do nothing        //Pseudokode til at sende besked tilbage til RPI og videre til PC (GUI) når objekt er sænket. 
                //}                     //Pseudokode til at sende besked tilbage til RPI og videre til PC (GUI) når objekt er sænket. 
                //UART_1_PutChar("s");  //Sender "s" til RPI for "sænket".
            }
        }
    }
}

//UART Interrupt Handler, der styres via inputs. Efter modtagelse ekkoer den tilbage til konsol og sætter den igang.
CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    for (uint8_t i = 0; i < bytesToRead; i++)
    {
        c = UART_1_GetChar();

        
        UART_1_PutString("PSoC received: ");
        UART_1_PutChar(c);
        UART_1_PutString(" from PuTTY terminal on PC");
        UART_1_PutString("\r\n");

        
        //Switch-Case som gennemgår kommunikationsprotokollen:
        switch (c)
        {
            case '0' :     
            {
                LEDoff();    //LED slukkes som signal på at bilen stoppes.
                UART_1_PutString("Stop\r\n");
            }
            break;
            case '1' :      
            {
                UART_1_PutString("Driving forward\r\n");
                if(LEDstatus == false)
                {
                    LEDon();
                }else if(LEDstatus == true)
                {
                    LEDoff();
                }

            }
            break;
            case '2' :      
            {
                UART_1_PutString("Driving backwards\r\n");
                if(LEDstatus == false)
                {
                    LEDon();
                }else if(LEDstatus == true)
                {
                    LEDoff();
                }
            }
            break;
            case '3' :     
            {
                UART_1_PutString("Turning left\r\n");
                if(LEDstatus == false)
                {
                    LEDon();
                }else if(LEDstatus == true)
                {
                    LEDoff();
                }
            }
            break;
            case '4' :      
            {
                UART_1_PutString("Turning right\r\n");
                if(LEDstatus == false)
                {
                    LEDon();
                }else if(LEDstatus == true)
                {
                    LEDoff();
                }
            }
            break;
            case '8' :      
            {
                UART_1_PutString("Lifting arm\r\n");
                if(LEDstatus == false)
                {
                    LEDon();
                }else if(LEDstatus == true)
                {
                    LEDoff();
                }                
            }
            break;
            case '9' :      
            {
                UART_1_PutString("Lowering arm\r\n");
                if(LEDstatus == false)
                {
                    LEDon();
                }else if(LEDstatus == true)
                {
                    LEDoff();
                }                
            }
            break; 
            
            default :
            break;
        }
    }
}

void LEDon()    //Toggler en LED på PSoC. Kan laves om til en funktion som eksempelvis løfter et objekt.
{
    LEDstatus = true;
}

void LEDoff()   //Toggler en LED på PSoC. Kan laves om til en funktion som eksempelvis sænker et objekt.
{
    LEDstatus = false;
}

/* [] END OF FILE */


