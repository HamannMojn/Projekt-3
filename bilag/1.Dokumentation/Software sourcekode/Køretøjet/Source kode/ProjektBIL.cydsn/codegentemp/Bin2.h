/*******************************************************************************
* File Name: Bin2.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Bin2_H) /* Pins Bin2_H */
#define CY_PINS_Bin2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Bin2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Bin2__PORT == 15 && ((Bin2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Bin2_Write(uint8 value);
void    Bin2_SetDriveMode(uint8 mode);
uint8   Bin2_ReadDataReg(void);
uint8   Bin2_Read(void);
void    Bin2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Bin2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Bin2_SetDriveMode() function.
     *  @{
     */
        #define Bin2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Bin2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Bin2_DM_RES_UP          PIN_DM_RES_UP
        #define Bin2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Bin2_DM_OD_LO           PIN_DM_OD_LO
        #define Bin2_DM_OD_HI           PIN_DM_OD_HI
        #define Bin2_DM_STRONG          PIN_DM_STRONG
        #define Bin2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Bin2_MASK               Bin2__MASK
#define Bin2_SHIFT              Bin2__SHIFT
#define Bin2_WIDTH              1u

/* Interrupt constants */
#if defined(Bin2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Bin2_SetInterruptMode() function.
     *  @{
     */
        #define Bin2_INTR_NONE      (uint16)(0x0000u)
        #define Bin2_INTR_RISING    (uint16)(0x0001u)
        #define Bin2_INTR_FALLING   (uint16)(0x0002u)
        #define Bin2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Bin2_INTR_MASK      (0x01u) 
#endif /* (Bin2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Bin2_PS                     (* (reg8 *) Bin2__PS)
/* Data Register */
#define Bin2_DR                     (* (reg8 *) Bin2__DR)
/* Port Number */
#define Bin2_PRT_NUM                (* (reg8 *) Bin2__PRT) 
/* Connect to Analog Globals */                                                  
#define Bin2_AG                     (* (reg8 *) Bin2__AG)                       
/* Analog MUX bux enable */
#define Bin2_AMUX                   (* (reg8 *) Bin2__AMUX) 
/* Bidirectional Enable */                                                        
#define Bin2_BIE                    (* (reg8 *) Bin2__BIE)
/* Bit-mask for Aliased Register Access */
#define Bin2_BIT_MASK               (* (reg8 *) Bin2__BIT_MASK)
/* Bypass Enable */
#define Bin2_BYP                    (* (reg8 *) Bin2__BYP)
/* Port wide control signals */                                                   
#define Bin2_CTL                    (* (reg8 *) Bin2__CTL)
/* Drive Modes */
#define Bin2_DM0                    (* (reg8 *) Bin2__DM0) 
#define Bin2_DM1                    (* (reg8 *) Bin2__DM1)
#define Bin2_DM2                    (* (reg8 *) Bin2__DM2) 
/* Input Buffer Disable Override */
#define Bin2_INP_DIS                (* (reg8 *) Bin2__INP_DIS)
/* LCD Common or Segment Drive */
#define Bin2_LCD_COM_SEG            (* (reg8 *) Bin2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Bin2_LCD_EN                 (* (reg8 *) Bin2__LCD_EN)
/* Slew Rate Control */
#define Bin2_SLW                    (* (reg8 *) Bin2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Bin2_PRTDSI__CAPS_SEL       (* (reg8 *) Bin2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Bin2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Bin2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Bin2_PRTDSI__OE_SEL0        (* (reg8 *) Bin2__PRTDSI__OE_SEL0) 
#define Bin2_PRTDSI__OE_SEL1        (* (reg8 *) Bin2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Bin2_PRTDSI__OUT_SEL0       (* (reg8 *) Bin2__PRTDSI__OUT_SEL0) 
#define Bin2_PRTDSI__OUT_SEL1       (* (reg8 *) Bin2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Bin2_PRTDSI__SYNC_OUT       (* (reg8 *) Bin2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Bin2__SIO_CFG)
    #define Bin2_SIO_HYST_EN        (* (reg8 *) Bin2__SIO_HYST_EN)
    #define Bin2_SIO_REG_HIFREQ     (* (reg8 *) Bin2__SIO_REG_HIFREQ)
    #define Bin2_SIO_CFG            (* (reg8 *) Bin2__SIO_CFG)
    #define Bin2_SIO_DIFF           (* (reg8 *) Bin2__SIO_DIFF)
#endif /* (Bin2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Bin2__INTSTAT)
    #define Bin2_INTSTAT            (* (reg8 *) Bin2__INTSTAT)
    #define Bin2_SNAP               (* (reg8 *) Bin2__SNAP)
    
	#define Bin2_0_INTTYPE_REG 		(* (reg8 *) Bin2__0__INTTYPE)
#endif /* (Bin2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Bin2_H */


/* [] END OF FILE */
