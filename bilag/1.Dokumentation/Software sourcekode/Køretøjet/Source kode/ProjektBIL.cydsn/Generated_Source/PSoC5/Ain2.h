/*******************************************************************************
* File Name: Ain2.h  
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

#if !defined(CY_PINS_Ain2_H) /* Pins Ain2_H */
#define CY_PINS_Ain2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Ain2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Ain2__PORT == 15 && ((Ain2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Ain2_Write(uint8 value);
void    Ain2_SetDriveMode(uint8 mode);
uint8   Ain2_ReadDataReg(void);
uint8   Ain2_Read(void);
void    Ain2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Ain2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Ain2_SetDriveMode() function.
     *  @{
     */
        #define Ain2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Ain2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Ain2_DM_RES_UP          PIN_DM_RES_UP
        #define Ain2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Ain2_DM_OD_LO           PIN_DM_OD_LO
        #define Ain2_DM_OD_HI           PIN_DM_OD_HI
        #define Ain2_DM_STRONG          PIN_DM_STRONG
        #define Ain2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Ain2_MASK               Ain2__MASK
#define Ain2_SHIFT              Ain2__SHIFT
#define Ain2_WIDTH              1u

/* Interrupt constants */
#if defined(Ain2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Ain2_SetInterruptMode() function.
     *  @{
     */
        #define Ain2_INTR_NONE      (uint16)(0x0000u)
        #define Ain2_INTR_RISING    (uint16)(0x0001u)
        #define Ain2_INTR_FALLING   (uint16)(0x0002u)
        #define Ain2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Ain2_INTR_MASK      (0x01u) 
#endif /* (Ain2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Ain2_PS                     (* (reg8 *) Ain2__PS)
/* Data Register */
#define Ain2_DR                     (* (reg8 *) Ain2__DR)
/* Port Number */
#define Ain2_PRT_NUM                (* (reg8 *) Ain2__PRT) 
/* Connect to Analog Globals */                                                  
#define Ain2_AG                     (* (reg8 *) Ain2__AG)                       
/* Analog MUX bux enable */
#define Ain2_AMUX                   (* (reg8 *) Ain2__AMUX) 
/* Bidirectional Enable */                                                        
#define Ain2_BIE                    (* (reg8 *) Ain2__BIE)
/* Bit-mask for Aliased Register Access */
#define Ain2_BIT_MASK               (* (reg8 *) Ain2__BIT_MASK)
/* Bypass Enable */
#define Ain2_BYP                    (* (reg8 *) Ain2__BYP)
/* Port wide control signals */                                                   
#define Ain2_CTL                    (* (reg8 *) Ain2__CTL)
/* Drive Modes */
#define Ain2_DM0                    (* (reg8 *) Ain2__DM0) 
#define Ain2_DM1                    (* (reg8 *) Ain2__DM1)
#define Ain2_DM2                    (* (reg8 *) Ain2__DM2) 
/* Input Buffer Disable Override */
#define Ain2_INP_DIS                (* (reg8 *) Ain2__INP_DIS)
/* LCD Common or Segment Drive */
#define Ain2_LCD_COM_SEG            (* (reg8 *) Ain2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Ain2_LCD_EN                 (* (reg8 *) Ain2__LCD_EN)
/* Slew Rate Control */
#define Ain2_SLW                    (* (reg8 *) Ain2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Ain2_PRTDSI__CAPS_SEL       (* (reg8 *) Ain2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Ain2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Ain2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Ain2_PRTDSI__OE_SEL0        (* (reg8 *) Ain2__PRTDSI__OE_SEL0) 
#define Ain2_PRTDSI__OE_SEL1        (* (reg8 *) Ain2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Ain2_PRTDSI__OUT_SEL0       (* (reg8 *) Ain2__PRTDSI__OUT_SEL0) 
#define Ain2_PRTDSI__OUT_SEL1       (* (reg8 *) Ain2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Ain2_PRTDSI__SYNC_OUT       (* (reg8 *) Ain2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Ain2__SIO_CFG)
    #define Ain2_SIO_HYST_EN        (* (reg8 *) Ain2__SIO_HYST_EN)
    #define Ain2_SIO_REG_HIFREQ     (* (reg8 *) Ain2__SIO_REG_HIFREQ)
    #define Ain2_SIO_CFG            (* (reg8 *) Ain2__SIO_CFG)
    #define Ain2_SIO_DIFF           (* (reg8 *) Ain2__SIO_DIFF)
#endif /* (Ain2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Ain2__INTSTAT)
    #define Ain2_INTSTAT            (* (reg8 *) Ain2__INTSTAT)
    #define Ain2_SNAP               (* (reg8 *) Ain2__SNAP)
    
	#define Ain2_0_INTTYPE_REG 		(* (reg8 *) Ain2__0__INTTYPE)
#endif /* (Ain2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Ain2_H */


/* [] END OF FILE */
