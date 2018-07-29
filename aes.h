#ifndef AES_H_
#define AES_H_

#include <Arduino.h>

#ifdef __cplusplus
extern "C"{
#endif

#define AES_256_ROUNDS 14
#define AES_192_ROUNDS 12
#define AES_128_ROUNDS 10

// Uncomment this (or compile with -DOPT_8_BIT) to optimise for an 8 bit architecture
#ifdef ARDUINO_ARCH_AVR
#define AES_OPT_8_BIT
#endif

#ifdef AES_OPT_8_BIT
  typedef uint8_t counter;
#else
  typedef unsigned int counter;
#endif

// AES-256

typedef struct aes_256_context_t_ {
  uint8_t round_key[(AES_256_ROUNDS + 1) * 16];
} aes_256_context_t;

void aes_256_init    (aes_256_context_t * const context, const uint8_t * const key);
void aes_256_encrypt (const aes_256_context_t * const context, uint8_t * const block);
void aes_256_decrypt (const aes_256_context_t * const context, uint8_t * const block);

// AES-192

typedef struct aes_192_context_t_ {
  uint8_t round_key[(AES_192_ROUNDS + 1) * 16];
} aes_192_context_t;

void aes_192_init    (aes_192_context_t * const context, const uint8_t * const key);
void aes_192_encrypt (const aes_192_context_t * const context, uint8_t * const block);
void aes_192_decrypt (const aes_192_context_t * const context, uint8_t * const block);

// AES-128

typedef struct aes_128_context_t_ {
  uint8_t round_key[(AES_128_ROUNDS + 1) * 16];
} aes_128_context_t;

void aes_128_init    (aes_128_context_t * const context, const uint8_t * const key);
void aes_128_encrypt (const aes_128_context_t * const context, uint8_t * const block);
void aes_128_decrypt (const aes_128_context_t * const context, uint8_t * const block);

#ifdef __cplusplus
} // extern "C"
#endif

#endif

