//For M0: export TARGET="${SCALE_HW}/target/lpc1114fn28"

//For M3: export TARGET="${SCALE_HW}/target/lpc1313fbd48"
//Make & Program: sudo  make --no-builtin-rules -f ${TARGET}/build/lib/scale.mk BSP="${TARGET}/build" USB="/dev/ttyUSB0" PROJECT="tinyAES" PROJECT_SOURCES="tinyAES.c aes.c" PROJECT_HEADERS="tinyAES.h aes.h" clean all program
#include "tinyAES.h"
#include "aes.h"

int main( int argc, char* argv[] ) {
 if( !scale_init( &SCALE_CONF ) ) {
    return -1;
  }
 
  uint8_t plain[16];
  uint8_t cipher[16];
  // 128bit key
  uint8_t key[16] =        { (uint8_t) 0x2b, (uint8_t) 0x7e, (uint8_t) 0x15, (uint8_t) 0x16, (uint8_t) 0x28, (uint8_t) 0xae, (uint8_t) 0xd2, (uint8_t) 0xa6, (uint8_t) 0xab, (uint8_t) 0xf7, (uint8_t) 0x15, (uint8_t) 0x88, (uint8_t) 0x09, (uint8_t) 0xcf, (uint8_t) 0x4f, (uint8_t) 0x3c };
  struct AES_ctx ctx;
  AES_init_ctx(&ctx, key);
  while( true ) {

             	for( int i = 0; i < 16; i++ ) 
	     	{
              		plain[i]=(uint8_t)scale_uart_rd(SCALE_UART_MODE_BLOCKING);
             	} 
		AES_ECB_encrypt(&ctx,plain);
    		for( int i = 0; i <16; i++ ) 
		{
     			 scale_uart_wr(SCALE_UART_MODE_BLOCKING,( (char)plain[ i ] ));
    		}
  }

  return 0;
}
