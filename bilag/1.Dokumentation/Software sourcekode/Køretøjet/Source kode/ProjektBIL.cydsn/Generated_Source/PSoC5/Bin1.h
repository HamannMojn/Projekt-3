/*******************************************************************************
* File Name: Bin1.h  
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

#if !defined(CY_PINS_Bin1_H) /* Pins Bin1_H */
#define CY_PINS_Bin1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Bin1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Bin1__PORT == 15 && ((Bin1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Bin1_Write(uint8 value);
void    Bin1_SetDriveMode(uint8 mode);
uint8   Bin1_ReadDataReg(void);
uint8   Bin1_Read(void);
void    Bin1_SetInterruptMode(uint16 position, uint16 mode);
uint8   Bin1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Bin1_SetDriveMode() function.
     *  @{
     */
        #define Bin1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Bin1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Bin1_DM_RES_UP          PIN_DM_RES_UP
        #define Bin1_DM_RES_DWN         PIN_DM_RES_DWN
        #define Bin1_DM_OD_LO           PIN_DM_OD_LO
        #define Bin1_DM_OD_HI           PIN_DM_OD_HI
        #define Bin1_DM_STRONG          PIN_DM_STRONG
        #define Bin1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Bin1_MASK               Bin1__MASK
#define Bin1_SHIFT              Bin1__SHIFT
#define Bin1_WIDTH              1u

/* Interrupt constants */
#if defined(Bin1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Bin1_SetInterruptMode() function.
     *  @{
     */
        #define Bin1_INTR_NONE      (uint16)(0x0000u)
        #define Bin1_INTR_RISING    (uint16)(0x0001u)
        #define Bin1_INTR_FALLING   (uint16)(0x0002u)
        #define Bin1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Bin1_INTR_MASK      (0x01u) 
#endif /* (Bin1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Bin1_PS                     (* (reg8 *) Bin1__PS)
/* Data Register */
#define Bin1_DR                     (* (reg8 *) Bin1__DR)
/* Port Number */
#define Bin1_PRT_NUM                (* (reg8 *) Bin1__PRT) 
/* Connect to Analog Globals */                                                  
#define Bin1_AG                     (* (reg8 *) Bin1__AG)                       
/* Analog MUX bux enable */
#define Bin1_AMUX                   (* (reg8 *) Bin1__AMUX) 
/* Bidirectional Enable */                                                        
#define Bin1_BIE                    (* (reg8 *) Bin1__BIE)
/* Bit-mask for Aliased Register Access */
#define Bin1_BIT_MASK               (* (reg8 *) Bin1__BIT_MASK)
/* Bypass Enable */
#define Bin1_BYP                    (* (reg8 *) Bin1__BYP)
/* Port wide control signals */                                                   
#define Bin1_CTL                    (* (reg8 *) Bin1__CTL)
/* Drive Modes */
#define Bin1_DM0                    (* (reg8 *) Bin1__DM0) 
#define Bin1_DM1                    (* (reg8 *) Bin1__DM1)
#define Bin1_DM2                    (* (reg8 *) Bin1__DM2) 
/* Input Buffer Disable Override */
#define Bin1_INP_DIS                (* (reg8 *) Bin1__INP_DIS)
/* LCD Common or Segment Drive */
#define Bin1_LCD_COM_SEG            (* (reg8 *) Bin1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Bin1_LCD_EN                 (* (reg8 *) Bin1__LCD_EN)
/* Slew Rate Control */
#define Bin1_SLW                    (* (reg8 *) Bin1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Bin1_PRTDSI__CAPS_SEL       (* (reg8 *) Bin1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Bin1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Bin1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Bin1_PRTDSI__OE_SEL0        (* (reg8 *) Bin1__PRTDSI__OE_SEL0) 
#define Bin1_PRTDSI__OE_SEL1        (* (reg8 *) Bin1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Bin1_PRTDSI__OUT_SEL0       (* (reg8 *) Bin1__PRTDSI__OUT_SEL0) 
#define Bin1_PRTDSI__OUT_SEL1       (* (reg8 *) Bin1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Bin1_PRTDSI__SYNC_OUT       (* (reg8 *) Bin1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Bin1__SIO_CFG)
    #define Bin1_SIO_HYST_EN        (* (reg8 *) Bin1__SIO_HYST_EN)
    #define Bin1_SIO_REG_HIFREQ     (* (reg8 *) Bin1__SIO_REG_HIFREQ)
    #define Bin1_SIO_CFG            (* (reg8 *) Bin1__SIO_CFG)
    #define Bin1_SIO_DIFF           (* (reg8 *) Bin1__SIO_DIFF)
#endif /* (Bin1__SIO_CFG) */

/* Interrupt Registers */
#if defined(Bin1__INTSTAT)
    #define Bin1_INTSTAT            (* (reg8 *) Bin1__INTSTAT)
    #define Bin1_SNAP               (* (reg8 *) Bin1__SNAP)
    
	#define Bin1_0_INTTYPE_REG 		(* (reg8 *) Bin1__0__INTTYPE)
#endif /* (Bin1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Bin1_H */


/* [] END OF FILE */
