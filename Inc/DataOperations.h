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
 * @param Buffer IN/OUT
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
 * @param Buffer IN/OUT
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
 * @param Buffer IN/OUT
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
 * @param Buffer IN/OUT
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
 * @param Buffer IN/OUT
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
 * @param Buffer IN/OUT
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

#endif /* __DATA_OPERATIONS_H_ */

// EOF