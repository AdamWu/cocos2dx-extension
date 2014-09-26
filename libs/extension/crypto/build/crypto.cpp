#include <string.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "aes/aes.h"
#include "xxtea/xxtea.h"
#include "md5/md5.h"

#ifdef __cplusplus
}
#endif

/*********************** FUNCTION DEFINITIONS ***********************/
void print_hex(unsigned char str[], int len)
{
	int idx;

	for(idx = 0; idx < len; idx++)
		printf("%02x", str[idx]);
}

void test_aes()
{
	/*
	 * Rijndael Monte Carlo Test: ECB mode
	 * source: NIST - rijndael-vals.zip
	 */

	static unsigned char AES_enc_test[3][16] =
	{
		{ 0xA0, 0x43, 0x77, 0xAB, 0xE2, 0x59, 0xB0, 0xD0,
		  0xB5, 0xBA, 0x2D, 0x40, 0xA5, 0x01, 0x97, 0x1B },
		{ 0x4E, 0x46, 0xF8, 0xC5, 0x09, 0x2B, 0x29, 0xE2,
		  0x9A, 0x97, 0x1A, 0x0C, 0xD1, 0xF6, 0x10, 0xFB },
		{ 0x1F, 0x67, 0x63, 0xDF, 0x80, 0x7A, 0x7E, 0x70,
		  0x96, 0x0D, 0x4C, 0xD3, 0x11, 0x8E, 0x60, 0x1A }
	};
    
	static unsigned char AES_dec_test[3][16] =
	{
		{ 0xF5, 0xBF, 0x8B, 0x37, 0x13, 0x6F, 0x2E, 0x1F,
		  0x6B, 0xEC, 0x6F, 0x57, 0x20, 0x21, 0xE3, 0xBA },
		{ 0xF1, 0xA8, 0x1B, 0x68, 0xF6, 0xE5, 0xA6, 0x27,
		  0x1A, 0x8C, 0xB2, 0x4E, 0x7D, 0x94, 0x91, 0xEF },
		{ 0x4D, 0xE0, 0xC6, 0xDF, 0x7C, 0xB1, 0x69, 0x72,
		  0x84, 0x60, 0x4D, 0x60, 0x27, 0x1B, 0xC5, 0x9A }
	};
   
    int m, n, i, j;
    aes_context ctx;
    unsigned char buf[16];
    unsigned char key[32];

    for( m = 0; m < 2; m++ )
    {
        printf( "\n Rijndael Monte Carlo Test (ECB mode) - " );

        if( m == 0 ) printf( "encryption\n\n" );
        if( m == 1 ) printf( "decryption\n\n" );

        for( n = 0; n < 3; n++ )
        {
            printf( " Test %d, key size = %3d bits: ",
                    n + 1, 128 + n * 64 );

            fflush( stdout );

            memset( buf, 0, 16 );
            memset( key, 0, 16 + n * 8 );

            for( i = 0; i < 400; i++ )
            {
				aes_set_key(&ctx, key, 128 + n * 64);
                for( j = 0; j < 9999; j++ )
                {
                    if( m == 0 ) aes_encrypt( &ctx, buf, buf );
                    if( m == 1 ) aes_decrypt( &ctx, buf, buf );
                }

                if( n > 0 )
                {
                    for( j = 0; j < (n << 3); j++ )
                    {
                        key[j] ^= buf[j + 16 - (n << 3)];
                    }
                }

                if( m == 0 ) aes_encrypt( &ctx, buf, buf );
                if( m == 1 ) aes_decrypt( &ctx, buf, buf );

                for( j = 0; j < 16; j++ )
                {
                    key[j + (n << 3)] ^= buf[j];
                }
            }

            if( ( m == 0 && memcmp( buf, AES_enc_test[n], 16 ) != 0 ) ||
                ( m == 1 && memcmp( buf, AES_dec_test[n], 16 ) != 0 ) )
            {
                printf( "failed!\n" );
            }
            printf( "passed.\n" );
        }
    }

}


void test_aes_ecb()
{
	aes_context ctx;
	unsigned char enc_buf[128];
	unsigned char plaintext[2][16] = {
		{0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a},
		{0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51}
	};
	unsigned char ciphertext[2][16] = {
		{0xf3,0xee,0xd1,0xbd,0xb5,0xd2,0xa0,0x3c,0x06,0x4b,0x5a,0x7e,0x3d,0xb1,0x81,0xf8},
		{0x59,0x1c,0xcb,0x10,0xd4,0x10,0xed,0x26,0xdc,0x5b,0xa7,0x4a,0x31,0x36,0x28,0x70}
	};
	unsigned char key[1][32] = {
		{0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
	};
	int pass = 1;

	// Raw ECB mode.
	printf("* ECB mode:\n");
	aes_set_key(&ctx, key[0], 256);
	for(int idx = 0; idx < 2; idx++) {
		unsigned long ret_length;
		unsigned char *result = aes_encrypt_ecb(&ctx, plaintext[idx], 16 ,&ret_length);
		printf("\nPlaintext    : ");
		print_hex(plaintext[idx], 16);
		printf("\n-encrypted to: ");
		print_hex(result, 16);
		pass = pass && !memcmp(result, ciphertext[idx], 16);

		result = aes_decrypt_ecb(&ctx, ciphertext[idx], 16 ,&ret_length);
		printf("\nCiphertext   : ");
		print_hex(ciphertext[idx], 16);
		printf("\n-decrypted to: ");
		print_hex(result, 16);
		pass = pass && !memcmp(result, plaintext[idx], 16);

		printf("\n");
	}
	if (pass == 1) printf("pass\n");
	else printf("no pass\n");

	printf("* ECB mode more:\n");
	unsigned char input[3] = {	0x6b,0xc1,0xbe};
	unsigned char _key[16] = {0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x60,0x3d,0xeb,0x10,0x15,0xca,0x71};
	aes_set_key(&ctx, _key, 256);
	unsigned long ret_length;
	unsigned char *result = aes_encrypt_ecb(&ctx, input, 3, &ret_length);
	printf("\nPlaintext    : ");
	print_hex(input, 3);
	printf("\n-encrypted to: ");
	print_hex(result, ret_length);
	result = aes_decrypt_ecb(&ctx, result,ret_length, &ret_length);
	printf("\n-decrypted to: ");
	print_hex(result, ret_length);
	printf("\n");
}

int main(int argc, char* argv[])
{
	test_aes_ecb();
	unsigned char str[3] = {0xF5, 0xBF, 0x8B};
	unsigned char key[3] = {0x55, 0xBF, 0x8B};
	xxtea_long ret_length;
	xxtea_encrypt(str, 3, key, 3, &ret_length);
	return 0;
}


