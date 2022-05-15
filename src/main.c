/**
 * @file main.c
 * @author İsmail Enes Bilgin (bilginenesismail@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "../Inc/DataOperations.h"

#define BUFFER_SIZE 10
#define U32_TEST_VALUE 125120100
#define U16_TEST_VALUE 10526


void printBuffer(uint8_t * Buffer, uint16_t len);
void test_u32LSBF(void);
void test_u32MSBF(void);
void test_u16LSBF(void);
void test_u16MSBF(void);

/**
 * @brief The application entry point.
 * 
 * @return int 
 */
int main(void){

    // Test function for U32 LSBF Functions
    printf("------------------------------------------------------------\n\r");
    printf("U32 LSBF Test Function Start: \n\r");
    test_u32LSBF();

    // Test function for U32 MSBF Functions
    printf("------------------------------------------------------------\n\r");
    printf("U32 MSBF Test Function Start: \n\r");
    test_u32MSBF();

    // Test function for U16 LSBF Functions
    printf("------------------------------------------------------------\n\r");
    printf("U16 LSBF Test Function Start: \n\r");
    test_u16LSBF();

    // Test function for U16 MSBF Functions
    printf("------------------------------------------------------------\n\r");
    printf("U16 MSBF Test Function Start: \n\r");
    test_u16MSBF();

    return 0;
}

/**
 * @brief The function prints the buffer element.
 * 
 * @param Buffer IN
 *               Pointer of the buffer.
 * 
 * @param len    IN
 *               Length of the buffer.
 */
void printBuffer(uint8_t * Buffer, uint16_t len){
    printf("Buffer Value : \n\r");

    for (uint16_t i = 0; i < len; i++)
    {   
        if(i % 10 == 0){
            printf("\n\r");
        }

        printf(" %d -  %u |", i, Buffer[i]);
    }

    printf("\n\r");
}

/**
 * @brief Test function for the Unsigned Long Put and Make LSBF.
 * 
 */
void test_u32LSBF(void){
    uint32_t temp = 0;
    uint8_t u8Buffer[BUFFER_SIZE];
    memset(u8Buffer, 0, BUFFER_SIZE);

    printf("Empty Buffer created : ");
    printBuffer(u8Buffer, BUFFER_SIZE);

    printf("Put U32 Test: %u\n\r", U32_TEST_VALUE);
    putU32_LSBF(u8Buffer, 0, (uint32_t) U32_TEST_VALUE);

    printf("After Operation buffer Parameter:\n\r");
    printBuffer(u8Buffer, BUFFER_SIZE);

    printf("Make U32 Test:\n\r");

    temp = (uint32_t) makeU32_LSBF(u8Buffer, 0);
    printf("makeU32_LSBF : %u\n\r", temp);

    printf("Result : ");
    if (temp == U32_TEST_VALUE){
        printf("Correct!\n\r");
    }else{
        printf("False!\n\r");
    }
}

/**
 * @brief  Test function for the Unsigned Long Put and Make MSBF.
 * 
 */
void test_u32MSBF(void){
    uint32_t temp = 0;
    uint8_t u8Buffer[BUFFER_SIZE];
    memset(u8Buffer, 0, BUFFER_SIZE);

    printf("Empty Buffer created : ");
    printBuffer(u8Buffer, BUFFER_SIZE);

    printf("Put U32 Test: %u\n\r", U32_TEST_VALUE);
    putU32_MSBF(u8Buffer, 0, (uint32_t) U32_TEST_VALUE);

    printf("After Operation buffer Parameter:\n\r");
    printBuffer(u8Buffer, BUFFER_SIZE);

    printf("Make U32 Test:\n\r");

    temp = (uint32_t) makeU32_MSBF(u8Buffer, 0);
    printf("makeU32_LSBF : %u\n\r", temp);

    printf("Result : ");
    if (temp == U32_TEST_VALUE){
        printf("Correct!\n\r");
    }else{
        printf("False!\n\r");
    }
}

/**
 * @brief Test function for the Unsigned Long Put and Make LSBF.
 * 
 */
void test_u16LSBF(void){
    uint16_t temp = 0;
    uint8_t u8Buffer[BUFFER_SIZE];

    memset(u8Buffer, 0, BUFFER_SIZE);

    printf("Empty Buffer created : ");
    printBuffer(u8Buffer, BUFFER_SIZE);

    printf("Put U16 Test: %u\n\r", U16_TEST_VALUE);
    putU16_LSBF(u8Buffer, 0, (uint16_t) U16_TEST_VALUE);

    printf("After Operation buffer Parameter:\n\r");
    printBuffer(u8Buffer, BUFFER_SIZE);

    printf("Make U32 Test:\n\r");

    temp = (uint16_t) makeU16_LSBF(u8Buffer, 0);
    printf("makeU16_LSBF : %u\n\r", temp);

    printf("Result : ");
    if (temp == U16_TEST_VALUE){
        printf("Correct!\n\r");
    }else{
        printf("False!\n\r");
    }
}

/**
 * @brief Test function for the Unsigned Long Put and make MSBF.
 * 
 */
void test_u16MSBF(void){
    uint16_t temp = 0;
    uint8_t u8Buffer[BUFFER_SIZE];
    memset(u8Buffer, 0, BUFFER_SIZE);

    printf("Empty Buffer created : ");
    printBuffer(u8Buffer, BUFFER_SIZE);

    printf("Put U16 Test: %u\n\r", U16_TEST_VALUE);
    putU16_MSBF(u8Buffer, 0, (uint16_t) U16_TEST_VALUE);

    printf("After Operation buffer Parameter:\n\r");
    printBuffer(u8Buffer, BUFFER_SIZE);

    printf("Make U16 Test:\n\r");

    temp = (uint16_t) makeU16_MSBF(u8Buffer, 0);
    printf("makeU16_MSBF : %u\n\r", temp);

    printf("Result : ");
    if (temp == U16_TEST_VALUE){
        printf("Correct!\n\r");
    }else{
        printf("False!\n\r");
    }
}