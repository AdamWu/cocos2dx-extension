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

enum AES_MODE 
{
	AES_ECB = 0,
	AES_CBC,
	AES_CTR,
	AES_CCM,
};

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


// encrypt file 
const char iv[16] = {0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff};
int crypto_file(bool bEncrypt, AES_MODE mode, const char *file_in, const char *file_out, unsigned char *key)
{
	aes_context ctx;
	char *buf;
	unsigned char *result;
	unsigned long fileSize, result_length;
	FILE *file_src = fopen(file_in, "rb");
	FILE *file_dst = fopen(file_out, "wb");
	if (!file_src){
		printf("can not find file:%s", file_in);
		return 1;
	}
	if (!file_dst){
		printf("can not find file:%s", file_out);
		return 1;
	}

	fseek (file_src, 0, SEEK_END);
	fileSize = ftell(file_src);
	buf = (char*)malloc(fileSize);
	fseek (file_src, 0, SEEK_SET);
	fread(buf, 1, fileSize, file_src);
	fclose(file_src);

	// encrypt or decrypt
	aes_set_key(&ctx, key, 128);
	
	switch (mode){
	case AES_ECB:
		if (bEncrypt)
			result = aes_encrypt_ecb(&ctx, (unsigned char*)buf, fileSize, &result_length);
		else
			result = aes_decrypt_ecb(&ctx, (unsigned char*)buf, fileSize, &result_length);
		break;
	case AES_CBC:
		if (bEncrypt)
			result = aes_encrypt_cbc(&ctx, (unsigned char*)buf, fileSize, &result_length, iv);
		else
			result = aes_decrypt_cbc(&ctx, (unsigned char*)buf, fileSize, &result_length, iv);
		break;
	case AES_CTR:
		free(buf);
		printf("AES CTR mode not available now\n");
		return 2;
		break;
	case AES_CCM:
		free(buf);
		printf("AES CCM mode not available now\n");
		return 2;
		break;
	default:
		free(buf);
		return 2;
		break;
	}
	free(buf);	
	
	// crypto successful?
	if (!result){
		printf("crypto error: you may use a inconsistent key or mode for decrypt\n");
		
		fclose(file_dst);

		return 2;
	}

	fwrite(result, 1, result_length, file_dst);
	free(result);
	
	fclose(file_dst);

	return 0;
}

int main(int argc, char* argv[])
{
	
	if (argc < 4) {
		fprintf(stderr, "Usage: %s input_file output_file key mode\n", argv[0]);
		exit(1);
	}
	
	AES_MODE mode;
	mode = AES_ECB;
	if (argc > 4) {
		if (strcmp(argv[4], "ecb"))
			mode = AES_ECB;
		else if(strcmp(argv[4], "cbc"))
			mode = AES_CBC;
		else if(strcmp(argv[4], "ctr"))
			mode = AES_CTR;
		else if(strcmp(argv[4], "ccm"))
			mode = AES_CCM;
	}

	int bRet;
	bRet = crypto_file(false, mode, argv[1],argv[2], (unsigned char*)argv[3]);
	if (bRet != 0) {
		fprintf(stderr, "crypto failed, %s\n", argv[1]);
		exit(1);
	}
	
	/*
	const char *src = "D:/cocos2dx-shader/libs/extension/crypto/build/test.txt";
	const char *dst = "D:/cocos2dx-shader/libs/extension/crypto/build/test_en.txt";
	const char *dst2 = "D:/cocos2dx-shader/libs/extension/crypto/build/test_de.txt";

	unsigned char key[16] = {0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff};

	crypto_file(true, AES_ECB, src, dst, key);
	crypto_file(false, AES_ECB, dst, dst2, key);
	*/
	return 0;
}


