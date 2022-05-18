/**
 * @file dataOperations.h
 * @author İsmail Enes Bilgin (bilginenesismail@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __DATA_OPERATIONS_H_
#define __DATA_OPERATIONS_H_

/**********************************************************************
 * Includes
 *********************************************************************/
#include <stdint.h>

/**********************************************************************
 * Macros
 *********************************************************************/
#define FRACTION_PRECISION  100000U  /**< */

/**********************************************************************
 * Type Definitions
 *********************************************************************/

/**********************************************************************
 * Inline Functions
 *********************************************************************/

/**
 * @brief The function separates the uint32_t data to the uint8_t type 
 * variable and inserts it into Buffer.
 * 
 * @note The function uses the LSBF.
 * 
 * @param Buffer OUT
 *               The Points of the buffer.
 * @param offset IN
 *               The offset of the buffer.
 * @param data   IN
 *               The value of the buffer insertion operation. 
 */
static inline void putU32_LSBF(uint8_t * Buffer, uint16_t offset, uint32_t data){
    
  Buffer[offset + 0] = (data & 0x000000FF) >>  0;
  Buffer[offset + 1] = (data & 0x0000FF00) >>  8;
  Buffer[offset + 2] = (data & 0x00FF0000) >> 16;
  Buffer[offset + 3] = (data & 0xFF000000) >> 24;
}

/**
 * @brief The function separates the uint32_t data to the uint8_t type
 * variable and inserts it into Buffer.
 * 
 * @note The function uses the MSBF.
 * 
 * @param Buffer OUT
 *               The points of the buffer.
 * 
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @param data   IN
 *               The value of the buffer insertion operation.
 */
static inline void putU32_MSBF(uint8_t * Buffer, uint16_t offset, uint32_t data){
    
  Buffer[offset + 0] = (data & 0xFF000000) >> 24;
  Buffer[offset + 1] = (data & 0x00FF0000) >> 16;
  Buffer[offset + 2] = (data & 0x0000FF00) >> 8;
  Buffer[offset + 3] = (data & 0x000000FF) >> 0;
}

/**
 * @brief The function separates the uint16_t data to the uint8_t type
 * variable and inserts it into Buffer.
 * 
 * @note The function uses the LSBF.
 * 
 * @param Buffer OUT
 *               The points of the buffer.
 * 
 * @param offset In
 *               The offset of the buffer.
 * 
 * @param data   IN
 *               The value of the buffer insertion operation.
 */
static inline void putU16_LSBF(uint8_t * Buffer, uint16_t offset, uint16_t data){

  Buffer[offset + 0] = (data & 0x00FF) >>  0;
  Buffer[offset + 1] = (data & 0xFF00) >>  8;
}

/**
 * @brief The function separates the uint16_t data to the uint8_t type
 * variable and inserts it into Buffer.
 * 
 * @note The function uses the MSBF.
 * 
 * @param Buffer OUT
 *               The points of the buffer.
 * 
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @param data   IN
 *               The value of the buffer insertion operation.
 */
static inline void putU16_MSBF(uint8_t * Buffer, uint16_t offset, uint16_t data){

  Buffer[offset + 0] = (data & 0xFF00) >> 8;
  Buffer[offset + 1] = (data & 0x00FF) >> 0;
}

/**
 * @brief The function separates the float value to the uint8_t type
 * variable and inserts it into buffer.
 * 
 * @note The function uses the LSBF.
 * 
 * @param Buffer OUT
 *               The points of the buffer.
 * 
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @param data   IN
 *               The value of the buffer insertion operation.
 * 
 * @remarks The function separates value as follow:
 *          
 *            data 
 *             intPart -> uint16_t and the first two bytes at the buffer.
 *             fractionPart -> uint16_t and the last two bytes at the buffer.                  
 */
static inline void putF16_LSBF(uint8_t * Buffer, uint16_t offset, float data){
  float f16FractPart = 0;
  int16_t u16Part = 0;

  u16Part = (int16_t) data;
  f16FractPart = data - u16Part;
  f16FractPart = ((uint16_t) (f16FractPart * FRACTION_PRECISION) % FRACTION_PRECISION);

  Buffer[offset + 0] = (u16Part & 0x00FF) >> 0;
  Buffer[offset + 1] = (u16Part & 0xFF00) >> 8;

  Buffer[offset + 2] = ((uint16_t) f16FractPart & 0x00FF) >> 0;
  Buffer[offset + 3] = ((uint16_t) f16FractPart & 0xFF00) >> 8;
}

/**
 * @brief The function separates the float value to the uint8_t type
 * variable and inserts it into buffer.
 * 
 * @note The function uses the MSBF.
 * 
 * @param Buffer OUT
 *               The points of the buffer.
 * 
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @param data   IN
 *               The value of the buffer insertion operation.
 * 
 * @remarks The function separates value as follow:
 *          
 *            data 
 *             intPart -> uint16_t and the first two bytes at the buffer.
 *             fractionPart -> uint16_t and the last two bytes at the buffer.
 */
static inline void putF16_MSBF(uint8_t * Buffer, uint16_t offset, float data){
  float f16FractPart = 0;
  int16_t u16Part = 0;

  u16Part = (int16_t) data;
  f16FractPart = data - u16Part;
  f16FractPart = ((uint16_t) (f16FractPart * FRACTION_PRECISION) % FRACTION_PRECISION);


  Buffer[offset + 0] = (u16Part & 0xFF00) >> 8;
  Buffer[offset + 1] = (u16Part & 0x00FF) >> 0;

  Buffer[offset + 2] = ((uint16_t) f16FractPart & 0xFF00) >> 8;
  Buffer[offset + 3] = ((uint16_t) f16FractPart & 0x00FF) >> 0;
}


/**
 * @brief The function merges the buffer elements and then gives the uint32_t type value.
 *
 * @note The function uses the LSBF.
 *
 * @param Buffer IN
 *               The points of the buffer.
 *
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @return uint32_t The value of the buffer merge operation. 
 */
static inline uint32_t makeU32_LSBF(uint8_t * Buffer, uint16_t offset){
    
    uint32_t temp;

    temp = Buffer[offset + 0] << 0;
    temp += Buffer[offset + 1] << 8;
    temp += Buffer[offset + 2] << 16;
    temp += Buffer[offset + 3] << 24;

    return temp;
}

/**
 * @brief The function merges the buffer elements and then gives the uint32_t type value.
 * 
 * @note The function uses the MSBF.
 * 
 * @param Buffer IN
 *               The points of the buffer.
 * 
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @return uint32_t The value of the buffer merger operations.
 */
static inline uint32_t makeU32_MSBF(uint8_t * Buffer, uint16_t offset){
    uint32_t temp;

    temp = Buffer[offset + 0] << 24;
    temp += Buffer[offset + 1] << 16;
    temp += Buffer[offset + 2] << 8;
    temp += Buffer[offset + 3] << 0;

    return temp;
}

/**
 * @brief The function merges the buffer elements and then gives the uint16_t type value.
 *
 * @note The function uses the LSBF.
 *
 * @param Buffer IN
 *               The points of the buffer.
 *
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @return uint16_t The value of the buffer merge operation. 
 */
static inline uint16_t makeU16_LSBF(uint8_t * Buffer, uint16_t offset){
    
    uint16_t temp;

    temp = Buffer[offset + 0] << 0;
    temp += Buffer[offset + 1] << 8;

    return temp;
}

/**
 * @brief The function merges the buffer elements and then gives the uint16_t type value.
 * 
 * @note The function uses the MSBF.
 * 
 * @param Buffer IN
 *               The points of the buffer.
 * 
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @return uint16_t The value of the buffer merger operations.
 */
static inline uint16_t makeU16_MSBF(uint8_t * Buffer, uint16_t offset){

    uint16_t temp;

    temp = Buffer[offset + 0] << 8;
    temp += Buffer[offset + 1] << 0;


    return temp;
}

/**
 * @brief The function merges the buffer elements and then gives the float type value.
 * 
 * @note The function uses LSBF.
 * 
 * @param Buffer IN
 *               The points of the buffer.
 * 
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @return float The value of the buffer merger operation.
 */
static inline float makeF16_LSBF(uint8_t * Buffer, uint16_t offset){
  float f16FractPart = 0;
  uint16_t u16Part = 0;

  u16Part = Buffer[offset + 0] << 0;
  u16Part += Buffer[offset + 1] << 8;

  f16FractPart = Buffer[offset + 2] << 0;
  f16FractPart += Buffer[offset + 3] << 8;

  return u16Part + ((float) f16FractPart / FRACTION_PRECISION);
}

/**
 * @brief The function merges the buffer elements and then gives the float type value.
 * 
 * @note The function uses MSBF.
 * 
 * @param Buffer IN
 *               The points of the buffer.
 * 
 * @param offset IN
 *               The offset of the buffer.
 * 
 * @return float The value of the buffer merger operation.
 */
static inline float makeF16_MSBF(uint8_t * Buffer, uint16_t offset){
  float f16FractPart = 0;
  uint16_t u16Part = 0;

  u16Part = Buffer[offset + 0] << 8;
  u16Part += Buffer[offset + 1] << 0;

  f16FractPart = Buffer[offset + 2] << 8;
  f16FractPart += Buffer[offset + 3] << 0;

  return u16Part + ((float) f16FractPart / FRACTION_PRECISION);
}

#endif /* __DATA_OPERATIONS_H_ */

// EOF