/*********************************************************************
 * Name            : Collin Beaudoin & Larson
 * Date            : October 19, 2018
 * Class           : EGR 326 Section 902
 * Instructor      : Dr. Nabeeh Kandalaft
 * Description     : Code to initialize eUSCI interface in IIC mode
 * that will read and write to the RTC over the IIC bus.
 * Credited Author : Professor Krug's Lecture Notes.
 ********************************************************************/
#include "driverlib.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "COMMONCLOCKS.h"
#include "ST7735.h"
#include <msp.h>
#include <stdlib.h>
#include "MotorLib.h"
#include "MSPIO.h"
#include "UART_Driver.h"
#include "KEYPAD.h"

#define BUFFER_SIZE 128
char Buffer[BUFFER_SIZE];


eUSCI_UART_Config UART2Config =
{
     EUSCI_A_UART_CLOCKSOURCE_SMCLK,
     78,
     2,
     0,
     EUSCI_A_UART_NO_PARITY,
     EUSCI_A_UART_LSB_FIRST,
     EUSCI_A_UART_ONE_STOP_BIT,
     EUSCI_A_UART_MODE,
     EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
};

int main(void)
{
    /* Halting WDT  */
    WDT_A_holdTimer();

    UART_Init(EUSCI_A1_BASE,UART2Config);

    char message[25] = "Hello World!";

    //UART_Write(EUSCI_A1_BASE, message, (sizeof(message) / sizeof(char)));
    MSPrintf(EUSCI_A1_BASE, "Hello World!\r\n");
    MSPgets(EUSCI_A1_BASE, Buffer, BUFFER_SIZE);
    MSPrintf(EUSCI_A1_BASE, "COLLIN\r\n");
    while(1){



    }

}
