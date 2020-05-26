/*******************************************************************************
* File Name: stby.h  
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

#if !defined(CY_PINS_stby_H) /* Pins stby_H */
#define CY_PINS_stby_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "stby_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 stby__PORT == 15 && ((stby__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    stby_Write(uint8 value);
void    stby_SetDriveMode(uint8 mode);
uint8   stby_ReadDataReg(void);
uint8   stby_Read(void);
void    stby_SetInterruptMode(uint16 position, uint16 mode);
uint8   stby_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the stby_SetDriveMode() function.
     *  @{
     */
        #define stby_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define stby_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define stby_DM_RES_UP          PIN_DM_RES_UP
        #define stby_DM_RES_DWN         PIN_DM_RES_DWN
        #define stby_DM_OD_LO           PIN_DM_OD_LO
        #define stby_DM_OD_HI           PIN_DM_OD_HI
        #define stby_DM_STRONG          PIN_DM_STRONG
        #define stby_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define stby_MASK               stby__MASK
#define stby_SHIFT              stby__SHIFT
#define stby_WIDTH              1u

/* Interrupt constants */
#if defined(stby__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in stby_SetInterruptMode() function.
     *  @{
     */
        #define stby_INTR_NONE      (uint16)(0x0000u)
        #define stby_INTR_RISING    (uint16)(0x0001u)
        #define stby_INTR_FALLING   (uint16)(0x0002u)
        #define stby_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define stby_INTR_MASK      (0x01u) 
#endif /* (stby__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define stby_PS                     (* (reg8 *) stby__PS)
/* Data Register */
#define stby_DR                     (* (reg8 *) stby__DR)
/* Port Number */
#define stby_PRT_NUM                (* (reg8 *) stby__PRT) 
/* Connect to Analog Globals */                                                  
#define stby_AG                     (* (reg8 *) stby__AG)                       
/* Analog MUX bux enable */
#define stby_AMUX                   (* (reg8 *) stby__AMUX) 
/* Bidirectional Enable */                                                        
#define stby_BIE                    (* (reg8 *) stby__BIE)
/* Bit-mask for Aliased Register Access */
#define stby_BIT_MASK               (* (reg8 *) stby__BIT_MASK)
/* Bypass Enable */
#define stby_BYP                    (* (reg8 *) stby__BYP)
/* Port wide control signals */                                                   
#define stby_CTL                    (* (reg8 *) stby__CTL)
/* Drive Modes */
#define stby_DM0                    (* (reg8 *) stby__DM0) 
#define stby_DM1                    (* (reg8 *) stby__DM1)
#define stby_DM2                    (* (reg8 *) stby__DM2) 
/* Input Buffer Disable Override */
#define stby_INP_DIS                (* (reg8 *) stby__INP_DIS)
/* LCD Common or Segment Drive */
#define stby_LCD_COM_SEG            (* (reg8 *) stby__LCD_COM_SEG)
/* Enable Segment LCD */
#define stby_LCD_EN                 (* (reg8 *) stby__LCD_EN)
/* Slew Rate Control */
#define stby_SLW                    (* (reg8 *) stby__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define stby_PRTDSI__CAPS_SEL       (* (reg8 *) stby__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define stby_PRTDSI__DBL_SYNC_IN    (* (reg8 *) stby__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define stby_PRTDSI__OE_SEL0        (* (reg8 *) stby__PRTDSI__OE_SEL0) 
#define stby_PRTDSI__OE_SEL1        (* (reg8 *) stby__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define stby_PRTDSI__OUT_SEL0       (* (reg8 *) stby__PRTDSI__OUT_SEL0) 
#define stby_PRTDSI__OUT_SEL1       (* (reg8 *) stby__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define stby_PRTDSI__SYNC_OUT       (* (reg8 *) stby__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(stby__SIO_CFG)
    #define stby_SIO_HYST_EN        (* (reg8 *) stby__SIO_HYST_EN)
    #define stby_SIO_REG_HIFREQ     (* (reg8 *) stby__SIO_REG_HIFREQ)
    #define stby_SIO_CFG            (* (reg8 *) stby__SIO_CFG)
    #define stby_SIO_DIFF           (* (reg8 *) stby__SIO_DIFF)
#endif /* (stby__SIO_CFG) */

/* Interrupt Registers */
#if defined(stby__INTSTAT)
    #define stby_INTSTAT            (* (reg8 *) stby__INTSTAT)
    #define stby_SNAP               (* (reg8 *) stby__SNAP)
    
	#define stby_0_INTTYPE_REG 		(* (reg8 *) stby__0__INTTYPE)
#endif /* (stby__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_stby_H */


/* [] END OF FILE */
