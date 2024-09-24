/**
 * AES encrypt algorithms handler module for Beast
 * @author: liexusong
 */

#include <stdlib.h>
#include <string.h>
#include "beast_log.h"
#include "beast_module.h"
#include "aes_algo_lib.c"

static uint8_t key[] = {
	0x1f, 0x2d, 0x51, 0x47, 0x36, 0xdf, 0xc7, 0xb6,
	0xdf, 0xa7, 0x35, 0x78, 0x09, 0xde, 0x4d, 0x2f,
};


int aes_encrypt_handler(char *inbuf, int len,
	char **outbuf, int *outlen)
{
	int blocks, i;
	char *out;
	char in[16];

	blocks = len / 16;
	if (len % 16) { /* not enough one block (16 bytes) */
		blocks += 1;
	}

	out = malloc(blocks * 16);
	if (!out) {
		beast_write_log(beast_log_error,
            "Out of memory when allocate `%d' size by encrypt(AES)", blocks*16);
		return -1;
	}

	for (i = 0; i < blocks; i++) {
		int size;

		memset(in, 0, 16);

		if (i == blocks - 1 && (len % 16)) { /* the last block */
			size = len % 16;
		} else {
			size = 16;
		}

		memcpy(in, inbuf + i * 16, size);

		AES128_ECB_encrypt(in, key, out + i * 16);
	}

	*outbuf = out;
	*outlen = blocks * 16;

	return 0;
}


int aes_decrypt_handler(char *inbuf, int len,
	char **outbuf, int *outlen)
{
	int blocks, i;
	char *out;

	if (len % 16) {
		return -1;
	}

	blocks = len / 16;

	out = malloc(blocks * 16);
	if (!out) {
		beast_write_log(beast_log_error,
            "Out of memory when allocate `%d' size by decrypt(AES)", blocks*16);
		return -1;
	}

	for (i = 0; i < blocks; i++) {
		AES128_ECB_decrypt(inbuf + i * 16, key, out + i * 16);
	}

	*outbuf = out;
	*outlen = blocks * 16;

	return 0;
}


void aes_free_handler(void *ptr)
{
    if (ptr) {
        free(ptr);
    }
}

struct beast_ops aes_handler_ops = {
	"aes-algo",
	aes_encrypt_handler,
	aes_decrypt_handler,
	aes_free_handler,
	NULL
};
