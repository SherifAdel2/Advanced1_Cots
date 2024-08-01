

/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef UTILS_H_
#define UTILS_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOG_BIT(REG,BIT) (REG^=(1<<BIT))

/* Read a certain bit in any register */
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)

#endif
/********************************************************************************************/
/* END OF FILE: Utils.h                                                                */
/********************************************************************************************/
