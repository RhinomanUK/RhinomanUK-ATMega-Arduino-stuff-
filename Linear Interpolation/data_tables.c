/* Datatables.c
*
* Just some test code for EPROM and FLASH r/w routines
*
* Define the default ECU configuration aka 'the base map'
* We could use EPROM or FLASH memory
* reserve some data areas using a modified linker script.
*
* EEPROM is 4k
* SRAM is 8k
* J Holland
* 4th January 2021
* v0.1
*/

#include <stdint.h>




/************************************ Place in EEPROM *****************************************/


/* CTS tables - random data */
const uint8_t CTS_VLimits[2] __attribute__ ((section (".EEPROM_DATA"))) = 
	{ 0x10, 0xF0 }; 	/* voltage limits for diagnostics */
		
const uint8_t CTS_Default	__attribute__ ((section (".EEPROM_DATA"))) = 
	0x40;					/* default if sensor fault detected */

const uint8_t CTS_Index[16] __attribute__ ((section (".EEPROM_DATA"))) = 
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 };
		
const uint8_t ColdStartFuel [16] __attribute__ ((section (".EEPROM_DATA"))) = 
	{ 0xFF, 0xFF, 0xFF, 0x80, 0x50, 0x40, 0x18, 0x14, 0x10, 0x0B, 0x07, 0x07, 0x07, 0x07, 0x08, 0x08 };
		
const uint8_t CTSCompFuel [16] __attribute__ ((section (".EEPROM_DATA"))) = 
	{ 0x9C, 0x90, 0x45, 0x30, 0x20, 0x15, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04 };
		
const uint8_t CTSAccEnrich1 [16] __attribute__ ((section (".EEPROM_DATA"))) = 
	{ 0x9C, 0x90, 0x45, 0x30, 0x20, 0x15, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04 };
		
const uint8_t CTSAccEnrich2 [16] __attribute__ ((section (".EEPROM_DATA"))) = 
	{ 0x9C, 0x90, 0x45, 0x30, 0x20, 0x15, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04 };
		
const uint8_t CTSAccEnrich3 [16] __attribute__ ((section (".EEPROM_DATA"))) = 
	{ 0x9C, 0x90, 0x45, 0x30, 0x20, 0x15, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04 };
		
	/* VE table */
const uint8_t Base_Ign_LUT[16][16] __attribute__ ((section (".EEPROM_DATA")))= { 
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 }
	};



/******************************* Place in FLASH ***********************************************/


/* IAT  tables - random data */
const uint8_t IAT_VLimits[2] __attribute__ ((section (".FLASH_DATA"))) = 
	{ 0x10, 0xF0 }; 	/* voltage limits for diagnostics */
		
const uint8_t IAT_Default __attribute__ ((section (".FLASH_DATA")))	= 
	0x40;					/* default if sensor fault detected */

const uint8_t IAT_Index[16] __attribute__ ((section (".FLASH_DATA"))) = 
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 };

/* Voltage correction tables - random data */
const uint8_t InjDeadTime_LUT[16] __attribute__ ((section (".FLASH_DATA"))) = 
	{ 0xFF, 0xFF, 0xFF, 0x80, 0x50, 0x40, 0x18, 0x14, 0x10, 0x0B, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00 };
		
const uint8_t IgnDwell_LUT[16] __attribute__ ((section (".FLASH_DATA"))) = 
	{ 0xFF, 0xFF, 0xFF, 0x80, 0x50, 0x40, 0x18, 0x14, 0x10, 0x0B, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00 };

/* VE table */
const uint8_t VE_LUT[16][16] __attribute__ ((section (".FLASH_DATA"))) = {
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 }
	};

/* AFR table */
const uint8_t AFR_LUT[16][16] __attribute__ ((section (".FLASH_DATA"))) = { 
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 },
	{ 0x1A, 0x1D, 0x22, 0x2A, 0x35, 0x44, 0x56, 0x6A, 0x7F, 0x93, 0xA6, 0xB6, 0xC4, 0xCF, 0xD8, 0xE0 }
	};




