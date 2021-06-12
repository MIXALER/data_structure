#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

long my_pow(int x, int y)
{
    long res = 1;
    for (int i = 0; i < y; ++i)
    {
        res = res * x;
    }
    return res;
}

uint32_t *encrypt_tea(uint32_t plain[2], uint32_t cipher[2], uint32_t key[4])
{
    // Your code here
    uint32_t sum = 0;
    uint32_t delta = 0x9E3779B9;
    cipher[0] = plain[0];
    cipher[1] = plain[1];
    for (int i = 0; i < 1024; ++i)
    {
        sum = ((sum + delta) % my_pow(2, 32));
        uint32_t tmp1 = ((cipher[1] << 4) + key[0]) % my_pow(2, 32);
        uint32_t tmp2 = (cipher[1] + sum) % my_pow(2, 32);
        uint32_t tmp3 = ((cipher[1] >> 5) + key[1]) % my_pow(2, 32);
        cipher[0] = (cipher[0] + (tmp1 ^ tmp2 ^ tmp3)) % my_pow(2, 32);
        uint32_t tmp4 = ((cipher[0] << 4) + key[2]) % my_pow(2, 32);
        uint32_t tmp5 = (cipher[0] + sum) % my_pow(2, 32);
        uint32_t tmp6 = ((cipher[0] >> 5) + key[3]) % my_pow(2, 32);
        cipher[1] = (cipher[1] + (tmp4 ^ tmp5 ^ tmp6)) % my_pow(2, 32);
    }
    return cipher;
}

uint32_t *decrypt_tea(uint32_t cipher[2], uint32_t plain[2], uint32_t key[4])
{
    // Your code here
    uint32_t sum = 0xDDE6E400;
    uint32_t delta = 0X9E3779B9;
    for (int i = 0; i < 1024; ++i)
    {
        uint32_t tmp4 = ((cipher[0] << 4) + key[2]) % my_pow(2, 32);
        uint32_t tmp5 = (cipher[0] + sum) % my_pow(2, 32);
        uint32_t tmp6 = ((cipher[0] >> 5) + key[3]) % my_pow(2, 32);
        cipher[1] = (cipher[1] - (tmp4 ^ tmp5 ^ tmp6)) % my_pow(2, 32);
        uint32_t tmp1 = ((cipher[1] << 4) + key[0]) % my_pow(2, 32);
        uint32_t tmp2 = (cipher[1] + sum) % my_pow(2, 32);
        uint32_t tmp3 = ((cipher[1] >> 5) + key[1]) % my_pow(2, 32);
        cipher[0] = (cipher[0] - (tmp1 ^ tmp2 ^ tmp3)) % my_pow(2, 32);
        sum = (sum - delta) % my_pow(2, 32);
    }
    plain[0] = cipher[0];
    plain[1] = cipher[1];

    return plain;
}

uint64_t *encrypt_tea_ctr(uint64_t *plain, uint32_t key[4], uint64_t nonce, uint64_t *cipher, uint32_t num_blocks)
{
    // Your code here
    for (int i = 0; i < num_blocks; ++i)
    {
        uint32_t plain_tmp_32[2];
        uint32_t cipher_tmp_32[2];
        plain_tmp_32[0] = plain[i] >> 32;
        plain_tmp_32[1] = plain[i];

        uint32_t *en_res = encrypt_tea(plain_tmp_32, cipher_tmp_32, key);
        cipher[i] = en_res[0];
        cipher[i] = (cipher[i] << 32);
        cipher[i] |= en_res[1];
    }

    return cipher;
}

uint64_t *decrypt_tea_ctr(uint64_t *cipher, uint32_t key[4], uint64_t nonce, uint64_t *plain, uint32_t num_blocks)
{
    // Your code here
    for (int i = 0; i < num_blocks; ++i)
    {
        uint32_t plain_tmp_32[2];
        uint32_t cipher_tmp_32[2];
        cipher_tmp_32[0] = cipher[i] >> 32;
        cipher_tmp_32[1] = cipher[i];

        uint32_t *de_res = decrypt_tea(cipher_tmp_32, plain_tmp_32, key);
        plain[i] = de_res[0];
        plain[i] = (plain[i] << 32);
        plain[i] |= de_res[1];
    }
    return plain;
}