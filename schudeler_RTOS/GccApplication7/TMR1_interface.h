/******************************************************************************
 *                                                                            *
 *************************  SWC     : TMR1_interface  *************************
 *************************  Date    : 14/01/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/

#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_


/* MACROS FOR TIMER INTERRUPT SOURCE */
#define TMR1_NORMAL_OVER_FLOW         1
#define TMR1_CTC_COMPARE_MATCH_A      2

                /*************** APIS PROTOTYPES ***************/
void TMR1_voidInit       (void);
void TMR1_voidStart      (void);
void TMR1_voidStop       (void);
void TMR1_voidSetCallBack(void(*copy_pFunAction)(void), u8 copy_u8InterruptSource);


#endif /* TMR1_INTERFACE_H_ */
