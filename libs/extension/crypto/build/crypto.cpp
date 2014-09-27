#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

void test_aes_ecb()
{
	aes_context ctx;
	/*
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
	*/

	printf("* ECB mode more:\n");
	unsigned char input[3] = {0x6b,0xc1,0xbe};
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

// file crypto key
unsigned char key[16] = {0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x60,0x3d,0xeb,0x10,0x15,0xca,0x71};

// encrypt file 
int crypto_file(bool bEncrypt, const char *file_in, const char *file_out)
{
	aes_context ctx;
	char *buf;
	unsigned char *result;
	unsigned long fileSize, result_length;
	FILE *file_src = fopen(file_in, "rb");
	FILE *file_dst = fopen(file_out, "wb");
	if (!file_src){
		printf("can not find file:%s", file_in);
		return -1;
	}
	if (!file_dst){
		printf("can not find file:%s", file_out);
		return -1;
	}

	fseek (file_src, 0, SEEK_END);
	fileSize = ftell(file_src);
	buf = (char*)malloc(fileSize);
	fseek (file_src, 0, SEEK_SET);
	fread(buf, 1, fileSize, file_src);
	fclose(file_src);

	// encrypt or decrypt
	aes_set_key(&ctx, key, 128);
	
	if (bEncrypt)
		result = aes_encrypt_ecb(&ctx, (unsigned char*)buf, fileSize, &result_length);
	else
		result = aes_decrypt_ecb(&ctx, (unsigned char*)buf, fileSize, &result_length);
		
	fwrite(result, 1, result_length, file_dst);
	fclose(file_dst);

	return 0;
}

int main(int argc, char* argv[])
{
	const char *src = "E:/cocos2dx-extension/libs/extension/crypto/build/test.txt";
	const char *dst = "E:/cocos2dx-extension/libs/extension/crypto/build/test_en.txt";
	const char *dst2 = "E:/cocos2dx-extension/libs/extension/crypto/build/test_de.txt";

	crypto_file(true, src, dst);
	//crypto_file(false, dst, dst2);

	return 0;
}


