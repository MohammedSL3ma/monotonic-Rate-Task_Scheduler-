/******************************************************************************
 *                                                                            *
 *************************  SWC     : TMR1_config     *************************
 *************************  Date    : 14/01/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/

#ifndef TMR1_CONFIG_H_
#define TMR1_CONFIG_H_


/* Options FOR TMR1 Mode:
1- TMR1_NORMAL_MODE_0
2- TMR1_CTC_MODE_4
*/
#define TMR1_MODE					TMR1_NORMAL_MODE_0

/* Options FOR PRESCALER:
1- TMR1_PRESCALER_1
2- TMR1_PRESCALER_8
3- TMR1_PRESCALER_64
4- TMR1_PRESCALER_256
5- TMR1_PRESCALER_1024
*/ 
#define TMR1_PRESCALER              TMR1_PRESCALER_64

#define TMR1_PRELOAD_VALUE          12144
#define TMR1_OVER_FLOW_COUNTER      4

#define TMR1_COMPARE_VALUE_A        62499
#define TMR1_CTC_COUNTER_A          4


#endif /* TMR1_CONFIG_H_ */
