#include <Arduino.h> //dummy arduino.h for compiling arduino code on desktop systems
#include <aes.h>
#include <cstdio>

#define BLKSZ 16

void verify(const uint8_t * const input, const uint8_t * const output, const uint8_t * const test)
{
  //verify
  bool verifyOk=true;
  for(int i=0;i<BLKSZ;++i)
    if(*(test+i)!=*(output+i))
    {
      verifyOk=false;
      break;
    }
  printf("Input data : ");
  for(int i=0;i<BLKSZ;++i)
    printf("0x%02x ",*(input+i));
  printf("<<END\n");
  printf("Output data: ");
  for(int i=0;i<BLKSZ;++i)
    printf("0x%02x ",*(output+i));
  printf("<<END\n");
  printf("Test data  : ");
  for(int i=0;i<BLKSZ;++i)
    printf("0x%02x ",*(test+i));
  printf("<<END\n");
  printf(verifyOk?"Verify OK.\n\n":"Verify failed!\n\n");
}

void encrypt128(const uint8_t * const key, const uint8_t * const input, const uint8_t * const output)
{
  //copy input block
  uint8_t test[BLKSZ];
  for(int i=0;i<BLKSZ;++i)
    *(test+i)=*(input+i);
  //encrypt
  aes_128_context_t context;
  aes_128_init(&context, key);
  aes_128_encrypt(&context, test);
  printf("Encrypt AES128 test\n");
  verify(input,output,test);
}

void decrypt128(const uint8_t * const key, const uint8_t * const input, const uint8_t * const output)
{
  //copy input block
  uint8_t test[BLKSZ];
  for(int i=0;i<BLKSZ;++i)
    *(test+i)=*(input+i);
  //encrypt
  aes_128_context_t context;
  aes_128_init(&context, key);
  aes_128_decrypt(&context, test);
  printf("Decrypt AES128 test\n");
  verify(input,output,test);
}

void encrypt192(const uint8_t * const key, const uint8_t * const input, const uint8_t * const output)
{
  //copy input block
  uint8_t test[BLKSZ];
  for(int i=0;i<BLKSZ;++i)
    *(test+i)=*(input+i);
  //encrypt
  aes_192_context_t context;
  aes_192_init(&context, key);
  aes_192_encrypt(&context, test);
  printf("Encrypt AES192 test\n");
  verify(input,output,test);
}

void decrypt192(const uint8_t * const key, const uint8_t * const input, const uint8_t * const output)
{
  //copy input block
  uint8_t test[BLKSZ];
  for(int i=0;i<BLKSZ;++i)
    *(test+i)=*(input+i);
  //encrypt
  aes_192_context_t context;
  aes_192_init(&context, key);
  aes_192_decrypt(&context, test);
  printf("Decrypt AES192 test\n");
  verify(input,output,test);
}

void encrypt256(const uint8_t * const key, const uint8_t * const input, const uint8_t * const output)
{
  //copy input block
  uint8_t test[BLKSZ];
  for(int i=0;i<BLKSZ;++i)
    *(test+i)=*(input+i);
  //encrypt
  aes_256_context_t context;
  aes_256_init(&context, key);
  aes_256_encrypt(&context, test);
  printf("Encrypt AES256 test\n");
  verify(input,output,test);
}

void decrypt256(const uint8_t * const key, const uint8_t * const input, const uint8_t * const output)
{
  //copy input block
  uint8_t test[BLKSZ];
  for(int i=0;i<BLKSZ;++i)
    *(test+i)=*(input+i);
  //encrypt
  aes_256_context_t context;
  aes_256_init(&context, key);
  aes_256_decrypt(&context, test);
  printf("Decrypt AES256 test\n");
  verify(input,output,test);
}

int main()
{
  // using test vectors from this document: http://csrc.nist.gov/publications/nistpubs/800-38a/sp800-38a.pdf
  //F.1.1
  //ECB-AES128.Encrypt
  const uint8_t key_128[]={0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
  const uint8_t plaintext1[]={0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a};
  const uint8_t plaintext2[]={0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51};
  const uint8_t plaintext3[]={0x30,0xc8,0x1c,0x46,0xa3,0x5c,0xe4,0x11,0xe5,0xfb,0xc1,0x19,0x1a,0x0a,0x52,0xef};
  const uint8_t plaintext4[]={0xf6,0x9f,0x24,0x45,0xdf,0x4f,0x9b,0x17,0xad,0x2b,0x41,0x7b,0xe6,0x6c,0x37,0x10};
  const uint8_t ciphertext1_128[]={0x3a,0xd7,0x7b,0xb4,0x0d,0x7a,0x36,0x60,0xa8,0x9e,0xca,0xf3,0x24,0x66,0xef,0x97};
  const uint8_t ciphertext2_128[]={0xf5,0xd3,0xd5,0x85,0x03,0xb9,0x69,0x9d,0xe7,0x85,0x89,0x5a,0x96,0xfd,0xba,0xaf};
  const uint8_t ciphertext3_128[]={0x43,0xb1,0xcd,0x7f,0x59,0x8e,0xce,0x23,0x88,0x1b,0x00,0xe3,0xed,0x03,0x06,0x88};
  const uint8_t ciphertext4_128[]={0x7b,0x0c,0x78,0x5e,0x27,0xe8,0xad,0x3f,0x82,0x23,0x20,0x71,0x04,0x72,0x5d,0xd4};

  encrypt128(key_128,plaintext1,ciphertext1_128);
  encrypt128(key_128,plaintext2,ciphertext2_128);
  encrypt128(key_128,plaintext3,ciphertext3_128);
  encrypt128(key_128,plaintext4,ciphertext4_128);

  decrypt128(key_128,ciphertext1_128,plaintext1);
  decrypt128(key_128,ciphertext2_128,plaintext2);
  decrypt128(key_128,ciphertext3_128,plaintext3);
  decrypt128(key_128,ciphertext4_128,plaintext4);

  //F.1.3
  //ECB-AES192.Encrypt
  const uint8_t key_192[]={0x8e,0x73,0xb0,0xf7,0xda,0x0e,0x64,0x52,0xc8,0x10,0xf3,0x2b,0x80,0x90,0x79,0xe5,0x62,0xf8,0xea,0xd2,0x52,0x2c,0x6b,0x7b};
  const uint8_t ciphertext1_192[]={0xbd,0x33,0x4f,0x1d,0x6e,0x45,0xf2,0x5f,0xf7,0x12,0xa2,0x14,0x57,0x1f,0xa5,0xcc};
  const uint8_t ciphertext2_192[]={0x97,0x41,0x04,0x84,0x6d,0x0a,0xd3,0xad,0x77,0x34,0xec,0xb3,0xec,0xee,0x4e,0xef};
  const uint8_t ciphertext3_192[]={0xef,0x7a,0xfd,0x22,0x70,0xe2,0xe6,0x0a,0xdc,0xe0,0xba,0x2f,0xac,0xe6,0x44,0x4e};
  const uint8_t ciphertext4_192[]={0x9a,0x4b,0x41,0xba,0x73,0x8d,0x6c,0x72,0xfb,0x16,0x69,0x16,0x03,0xc1,0x8e,0x0e};

  encrypt192(key_192,plaintext1,ciphertext1_192);
  encrypt192(key_192,plaintext2,ciphertext2_192);
  encrypt192(key_192,plaintext3,ciphertext3_192);
  encrypt192(key_192,plaintext4,ciphertext4_192);

  decrypt192(key_192,ciphertext1_192,plaintext1);
  decrypt192(key_192,ciphertext2_192,plaintext2);
  decrypt192(key_192,ciphertext3_192,plaintext3);
  decrypt192(key_192,ciphertext4_192,plaintext4);

  //F.1.5
  //ECB-AES256.Encrypt
  const uint8_t key_256[]={0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4};
  const uint8_t ciphertext1_256[]={0xf3,0xee,0xd1,0xbd,0xb5,0xd2,0xa0,0x3c,0x06,0x4b,0x5a,0x7e,0x3d,0xb1,0x81,0xf8};
  const uint8_t ciphertext2_256[]={0x59,0x1c,0xcb,0x10,0xd4,0x10,0xed,0x26,0xdc,0x5b,0xa7,0x4a,0x31,0x36,0x28,0x70};
  const uint8_t ciphertext3_256[]={0xb6,0xed,0x21,0xb9,0x9c,0xa6,0xf4,0xf9,0xf1,0x53,0xe7,0xb1,0xbe,0xaf,0xed,0x1d};
  const uint8_t ciphertext4_256[]={0x23,0x30,0x4b,0x7a,0x39,0xf9,0xf3,0xff,0x06,0x7d,0x8d,0x8f,0x9e,0x24,0xec,0xc7};

  encrypt256(key_256,plaintext1,ciphertext1_256);
  encrypt256(key_256,plaintext2,ciphertext2_256);
  encrypt256(key_256,plaintext3,ciphertext3_256);
  encrypt256(key_256,plaintext4,ciphertext4_256);

  decrypt256(key_256,ciphertext1_256,plaintext1);
  decrypt256(key_256,ciphertext2_256,plaintext2);
  decrypt256(key_256,ciphertext3_256,plaintext3);
  decrypt256(key_256,ciphertext4_256,plaintext4);

  return 0;
}
