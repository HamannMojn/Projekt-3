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

#include"ServoArm.h"
#include <project.h>
#include "Sensor.h"



void LOFT()
{

    UART_1_PutString("LOEFT AF OBJEKT\r\n\n");
    
    // Justere gribe arm mod objekt
        for (int control4=30; control4 <= 105; control4= control4 + 1 ) 
            {
            PWM_4_WriteCompare(control4);
            CyDelay(50);    
            }
 
         for (int control2=75; control2 >= 50; control2= control2 - 1 ) 
            {
            PWM_2_WriteCompare(control2);
            CyDelay(50);
            
            }
        PWM_3_WriteCompare(20); 
        CyDelay(1000);
              
        PWM_6_WriteCompare(80); //Grib om objekt
        CyDelay(500);
   
    // Justere gribe arm mod objekt
       
    // Løft af objekt til ønkset højde
          for (int control2=50; control2 <= 65; control2= control2 + 1 ) 
            {
            PWM_2_WriteCompare(control2);
            CyDelay(50);
            }
            
           for (int control3 = 32; control3 <= 45; control3 = control3 + 1 ) 
            {
            PWM_3_WriteCompare(control3);
            CyDelay(50);
            }
            
            for (int control4=105; control4 >= 90; control4= control4 - 1 ) 
            {
            PWM_4_WriteCompare(control4);
            CyDelay(50);    
            }
        PWM_6_WriteCompare(80);
        UART_1_PutString("OBJEKT LOEFTET\r\n");

}

void SANK()
{
        UART_1_PutString("SAENK AF OBJEKT\r\n\n");
        
        for (int control2=65; control2 >= 56; control2= control2 - 1 ) 
            {
            PWM_2_WriteCompare(control2);
            CyDelay(100);
            }
            PWM_4_WriteCompare(100);
        for (int control3=45; control3 >= 30; control3= control3 - 1 ) 
            {
            PWM_3_WriteCompare(control3);
            CyDelay(100);
            }
       
        
        PWM_6_WriteCompare(80);
        CyDelay(1000);
        PWM_6_WriteCompare(50);
       
       // Justere gribe arm mod objekt
        
         for (int control2=56; control2 <= 78; control2= control2 + 1 ) 
            {
            PWM_2_WriteCompare(control2);
            CyDelay(100);
            }
            
        PWM_4_WriteCompare(30);
        CyDelay(500);    
        PWM_3_WriteCompare(32); 
        CyDelay(1000);
        PWM_6_WriteCompare(50); 
        UART_1_PutString("OBJEKT SAENKET\r\n");
}

/* [] END OF FILE */
