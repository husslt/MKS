/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_power.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint32_t DWT1, DWT2;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */

char* password_check(char* inp_mod[20]) {
	char password_stored[20] = "1234";
	char input[20];
	uint8_t status;

	PRINTF("\r\nEnter password: ");
	//SCANF("%s", input);
	input = input_mod;
	DWT1 = DWT->CYCCNT;
	status = strcmp(input, password_stored);
	DWT2 = DWT->CYCCNT;

	PRINTF("\r\ninput: %s", input);

	if(status == 0)
		{PRINTF("\r\ninput correct");}
	else
		{PRINTF("\r\ninput invalid");}
}

int main(void)
{
    //char ch;


    /* Init board hardware. */
    /* set BOD VBAT level to 1.65V */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
    /* attach main clock divide to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
#if !defined(DONT_ENABLE_FLASH_PREFETCH)
    /* enable flash prefetch for better performance */
    SYSCON->FMCCR |= SYSCON_FMCCR_PREFEN_MASK;
#endif

    PRINTF("Start\r\n");
    //char* out = password_check();

    //PRINTF("\r\nCycles in function: %d", DWT2-DWT1);
    //PRINTF("%s", out);

    char abcd[36] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    uint32_t abcd_size = sizeof(abcd) / sizeof(abcd);
    while (1)
    {

    	uint32_t cyc;
    	uint32_t prev_cyc;
    	char* fullpass[20] = "";
    	uint32_t fullpass_size = sizeof(fullpass) / sizeof(fullpass);
    	char testchar = '';
    	for (uint8_t c = 0; i < fullpass_size; i++) {
    		for (uint8_t i = 0; i < abcd_size; i++) {
    			testchar = abcd[i];
    			fullpass[c] = testchar;
    			char* out = password_check();
    			prev_cyc = cyc;
    			cyc = DWT2-DWT1;

    			if ((i==1 && prev_cyc > cyc)) {
    				fullpass[c] = abcd[i-1];
    				break;
    			}
    			if ((i>1 && cyc>prev_cyc)) {
    				break;
    			}
    		}
    		if (c==0) {
    			break;
    		}
    	}
    	PRINTF("\r\n%s", fullpass);
        /*if(GETCHAR()==13) {
        	//ch = GETCHAR();
        	//PUTCHAR(ch);

        	// PRINTF("hello world.\r\n");
        	char* out = password_check();

        	PRINTF("\r\nCycles in function: %d", DWT2-DWT1);
        	//PRINTF("%s", out);

        }*/

    }
}
