#ifndef _AES_H
#define _AES_H


#ifndef uint8
#define uint8  unsigned char
#endif

#ifndef uint32
#define uint32 unsigned long int
#endif

#define AES_BLOCK_SIZE 16

typedef struct
{
    uint32 erk[64];     /* encryption round keys */
    uint32 drk[64];     /* decryption round keys */
    int nr;             /* number of rounds */
}
aes_context;

// 16-128, 24-192, 32-256
extern int  aes_set_key( aes_context *ctx, uint8 *key, int nbits );
extern void aes_encrypt( aes_context *ctx, uint8 input[16], uint8 output[16] );
extern void aes_decrypt( aes_context *ctx, uint8 input[16], uint8 output[16] );

/* ecb mode */
extern unsigned char* aes_encrypt_ecb(aes_context *ctx, uint8 *input, uint32 length, uint32 *ret_length);
extern unsigned char* aes_decrypt_ecb(aes_context *ctx, uint8 *input, uint32 length, uint32 *ret_length);

/* cbc mode */
extern unsigned char* aes_encrypt_cbc(aes_context *ctx, uint8 *input, uint32 length, uint32 *ret_length, const char* iv);
extern unsigned char* aes_decrypt_cbc(aes_context *ctx, uint8 *input, uint32 length, uint32 *ret_length, const char* iv);

/* ctr mode */
extern void aes_encrypt_ctr(aes_context *ctx, uint8 *input, uint32 length, uint8 *output);

/* ccm mode */
extern void aes_encrypt_ccm(aes_context *ctx, uint8 *input, uint32 length, uint8 *output);

#endif /* aes.h */