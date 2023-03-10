 /****************************************************************************
 File Name        : wolfSSLClientTask.h
 Author           : wolfSSL Inc.
 Date Created     : March 25, 2016
 Current Revision : 1.0
 Notes            : Header file for wolfSSLClientTask.c

Copyright (C) wolfSSL, Inc. 2020
 *****************************************************************************/

#pragma once

#include "wolfssl/wolfcrypt/settings.h"

/* CA certificate to verify example.com:443 */
static const unsigned char digicert_ca_2048[] =
{
    0x30, 0x82, 0x03, 0xC5, 0x30, 0x82, 0x02, 0xAD, 0xA0, 0x03,
    0x02, 0x01, 0x02, 0x02, 0x10, 0x02, 0xAC, 0x5C, 0x26, 0x6A,
    0x0B, 0x40, 0x9B, 0x8F, 0x0B, 0x79, 0xF2, 0xAE, 0x46, 0x25,
    0x77, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
    0x0D, 0x01, 0x01, 0x05, 0x05, 0x00, 0x30, 0x6C, 0x31, 0x0B,
    0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55,
    0x53, 0x31, 0x15, 0x30, 0x13, 0x06, 0x03, 0x55, 0x04, 0x0A,
    0x13, 0x0C, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72, 0x74,
    0x20, 0x49, 0x6E, 0x63, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03,
    0x55, 0x04, 0x0B, 0x13, 0x10, 0x77, 0x77, 0x77, 0x2E, 0x64,
    0x69, 0x67, 0x69, 0x63, 0x65, 0x72, 0x74, 0x2E, 0x63, 0x6F,
    0x6D, 0x31, 0x2B, 0x30, 0x29, 0x06, 0x03, 0x55, 0x04, 0x03,
    0x13, 0x22, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72, 0x74,
    0x20, 0x48, 0x69, 0x67, 0x68, 0x20, 0x41, 0x73, 0x73, 0x75,
    0x72, 0x61, 0x6E, 0x63, 0x65, 0x20, 0x45, 0x56, 0x20, 0x52,
    0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41, 0x30, 0x1E, 0x17, 0x0D,
    0x30, 0x36, 0x31, 0x31, 0x31, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x30, 0x30, 0x5A, 0x17, 0x0D, 0x33, 0x31, 0x31, 0x31, 0x31,
    0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x5A, 0x30, 0x6C,
    0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
    0x02, 0x55, 0x53, 0x31, 0x15, 0x30, 0x13, 0x06, 0x03, 0x55,
    0x04, 0x0A, 0x13, 0x0C, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65,
    0x72, 0x74, 0x20, 0x49, 0x6E, 0x63, 0x31, 0x19, 0x30, 0x17,
    0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x10, 0x77, 0x77, 0x77,
    0x2E, 0x64, 0x69, 0x67, 0x69, 0x63, 0x65, 0x72, 0x74, 0x2E,
    0x63, 0x6F, 0x6D, 0x31, 0x2B, 0x30, 0x29, 0x06, 0x03, 0x55,
    0x04, 0x03, 0x13, 0x22, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65,
    0x72, 0x74, 0x20, 0x48, 0x69, 0x67, 0x68, 0x20, 0x41, 0x73,
    0x73, 0x75, 0x72, 0x61, 0x6E, 0x63, 0x65, 0x20, 0x45, 0x56,
    0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41, 0x30, 0x82,
    0x01, 0x22, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86,
    0xF7, 0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01,
    0x0F, 0x00, 0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 0x01, 0x01,
    0x00, 0xC6, 0xCC, 0xE5, 0x73, 0xE6, 0xFB, 0xD4, 0xBB, 0xE5,
    0x2D, 0x2D, 0x32, 0xA6, 0xDF, 0xE5, 0x81, 0x3F, 0xC9, 0xCD,
    0x25, 0x49, 0xB6, 0x71, 0x2A, 0xC3, 0xD5, 0x94, 0x34, 0x67,
    0xA2, 0x0A, 0x1C, 0xB0, 0x5F, 0x69, 0xA6, 0x40, 0xB1, 0xC4,
    0xB7, 0xB2, 0x8F, 0xD0, 0x98, 0xA4, 0xA9, 0x41, 0x59, 0x3A,
    0xD3, 0xDC, 0x94, 0xD6, 0x3C, 0xDB, 0x74, 0x38, 0xA4, 0x4A,
    0xCC, 0x4D, 0x25, 0x82, 0xF7, 0x4A, 0xA5, 0x53, 0x12, 0x38,
    0xEE, 0xF3, 0x49, 0x6D, 0x71, 0x91, 0x7E, 0x63, 0xB6, 0xAB,
    0xA6, 0x5F, 0xC3, 0xA4, 0x84, 0xF8, 0x4F, 0x62, 0x51, 0xBE,
    0xF8, 0xC5, 0xEC, 0xDB, 0x38, 0x92, 0xE3, 0x06, 0xE5, 0x08,
    0x91, 0x0C, 0xC4, 0x28, 0x41, 0x55, 0xFB, 0xCB, 0x5A, 0x89,
    0x15, 0x7E, 0x71, 0xE8, 0x35, 0xBF, 0x4D, 0x72, 0x09, 0x3D,
    0xBE, 0x3A, 0x38, 0x50, 0x5B, 0x77, 0x31, 0x1B, 0x8D, 0xB3,
    0xC7, 0x24, 0x45, 0x9A, 0xA7, 0xAC, 0x6D, 0x00, 0x14, 0x5A,
    0x04, 0xB7, 0xBA, 0x13, 0xEB, 0x51, 0x0A, 0x98, 0x41, 0x41,
    0x22, 0x4E, 0x65, 0x61, 0x87, 0x81, 0x41, 0x50, 0xA6, 0x79,
    0x5C, 0x89, 0xDE, 0x19, 0x4A, 0x57, 0xD5, 0x2E, 0xE6, 0x5D,
    0x1C, 0x53, 0x2C, 0x7E, 0x98, 0xCD, 0x1A, 0x06, 0x16, 0xA4,
    0x68, 0x73, 0xD0, 0x34, 0x04, 0x13, 0x5C, 0xA1, 0x71, 0xD3,
    0x5A, 0x7C, 0x55, 0xDB, 0x5E, 0x64, 0xE1, 0x37, 0x87, 0x30,
    0x56, 0x04, 0xE5, 0x11, 0xB4, 0x29, 0x80, 0x12, 0xF1, 0x79,
    0x39, 0x88, 0xA2, 0x02, 0x11, 0x7C, 0x27, 0x66, 0xB7, 0x88,
    0xB7, 0x78, 0xF2, 0xCA, 0x0A, 0xA8, 0x38, 0xAB, 0x0A, 0x64,
    0xC2, 0xBF, 0x66, 0x5D, 0x95, 0x84, 0xC1, 0xA1, 0x25, 0x1E,
    0x87, 0x5D, 0x1A, 0x50, 0x0B, 0x20, 0x12, 0xCC, 0x41, 0xBB,
    0x6E, 0x0B, 0x51, 0x38, 0xB8, 0x4B, 0xCB, 0x02, 0x03, 0x01,
    0x00, 0x01, 0xA3, 0x63, 0x30, 0x61, 0x30, 0x0E, 0x06, 0x03,
    0x55, 0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03, 0x02,
    0x01, 0x86, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D, 0x13, 0x01,
    0x01, 0xFF, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xFF, 0x30,
    0x1D, 0x06, 0x03, 0x55, 0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14,
    0xB1, 0x3E, 0xC3, 0x69, 0x03, 0xF8, 0xBF, 0x47, 0x01, 0xD4,
    0x98, 0x26, 0x1A, 0x08, 0x02, 0xEF, 0x63, 0x64, 0x2B, 0xC3,
    0x30, 0x1F, 0x06, 0x03, 0x55, 0x1D, 0x23, 0x04, 0x18, 0x30,
    0x16, 0x80, 0x14, 0xB1, 0x3E, 0xC3, 0x69, 0x03, 0xF8, 0xBF,
    0x47, 0x01, 0xD4, 0x98, 0x26, 0x1A, 0x08, 0x02, 0xEF, 0x63,
    0x64, 0x2B, 0xC3, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48,
    0x86, 0xF7, 0x0D, 0x01, 0x01, 0x05, 0x05, 0x00, 0x03, 0x82,
    0x01, 0x01, 0x00, 0x1C, 0x1A, 0x06, 0x97, 0xDC, 0xD7, 0x9C,
    0x9F, 0x3C, 0x88, 0x66, 0x06, 0x08, 0x57, 0x21, 0xDB, 0x21,
    0x47, 0xF8, 0x2A, 0x67, 0xAA, 0xBF, 0x18, 0x32, 0x76, 0x40,
    0x10, 0x57, 0xC1, 0x8A, 0xF3, 0x7A, 0xD9, 0x11, 0x65, 0x8E,
    0x35, 0xFA, 0x9E, 0xFC, 0x45, 0xB5, 0x9E, 0xD9, 0x4C, 0x31,
    0x4B, 0xB8, 0x91, 0xE8, 0x43, 0x2C, 0x8E, 0xB3, 0x78, 0xCE,
    0xDB, 0xE3, 0x53, 0x79, 0x71, 0xD6, 0xE5, 0x21, 0x94, 0x01,
    0xDA, 0x55, 0x87, 0x9A, 0x24, 0x64, 0xF6, 0x8A, 0x66, 0xCC,
    0xDE, 0x9C, 0x37, 0xCD, 0xA8, 0x34, 0xB1, 0x69, 0x9B, 0x23,
    0xC8, 0x9E, 0x78, 0x22, 0x2B, 0x70, 0x43, 0xE3, 0x55, 0x47,
    0x31, 0x61, 0x19, 0xEF, 0x58, 0xC5, 0x85, 0x2F, 0x4E, 0x30,
    0xF6, 0xA0, 0x31, 0x16, 0x23, 0xC8, 0xE7, 0xE2, 0x65, 0x16,
    0x33, 0xCB, 0xBF, 0x1A, 0x1B, 0xA0, 0x3D, 0xF8, 0xCA, 0x5E,
    0x8B, 0x31, 0x8B, 0x60, 0x08, 0x89, 0x2D, 0x0C, 0x06, 0x5C,
    0x52, 0xB7, 0xC4, 0xF9, 0x0A, 0x98, 0xD1, 0x15, 0x5F, 0x9F,
    0x12, 0xBE, 0x7C, 0x36, 0x63, 0x38, 0xBD, 0x44, 0xA4, 0x7F,
    0xE4, 0x26, 0x2B, 0x0A, 0xC4, 0x97, 0x69, 0x0D, 0xE9, 0x8C,
    0xE2, 0xC0, 0x10, 0x57, 0xB8, 0xC8, 0x76, 0x12, 0x91, 0x55,
    0xF2, 0x48, 0x69, 0xD8, 0xBC, 0x2A, 0x02, 0x5B, 0x0F, 0x44,
    0xD4, 0x20, 0x31, 0xDB, 0xF4, 0xBA, 0x70, 0x26, 0x5D, 0x90,
    0x60, 0x9E, 0xBC, 0x4B, 0x17, 0x09, 0x2F, 0xB4, 0xCB, 0x1E,
    0x43, 0x68, 0xC9, 0x07, 0x27, 0xC1, 0xD2, 0x5C, 0xF7, 0xEA,
    0x21, 0xB9, 0x68, 0x12, 0x9C, 0x3C, 0x9C, 0xBF, 0x9E, 0xFC,
    0x80, 0x5C, 0x9B, 0x63, 0xCD, 0xEC, 0x47, 0xAA, 0x25, 0x27,
    0x67, 0xA0, 0x37, 0xF3, 0x00, 0x82, 0x7D, 0x54, 0xD7, 0xA9,
    0xF8, 0xE9, 0x2E, 0x13, 0xA3, 0x77, 0xE8, 0x1F, 0x4A
};

/* function prototypes */

int WolfCryptTest(void);

int  md2_test(void);
int  md5_test(void);
int  md4_test(void);
int  sha_test(void);
int  sha256_test(void);
int  sha512_test(void);
int  sha384_test(void);
int  hmac_md5_test(void);
int  hmac_sha_test(void);
int  hmac_sha256_test(void);
int  hmac_sha384_test(void);
int  hmac_sha512_test(void);
int  hmac_blake2b_test(void);
int  hkdf_test(void);
int  arc4_test(void);
int  chacha_test(void);
int  chacha20_poly1305_aead_test(void);
int  des_test(void);
int  des3_test(void);
int  aes_test(void);
int  poly1305_test(void);
int  aesgcm_test(void);
int  gmac_test(void);
int  aesccm_test(void);
int  camellia_test(void);
int  rsa_test(void);
int  dh_test(void);
int  dsa_test(void);
int  srp_test(void);
int  random_test(void);
int  pwdbased_test(void);
int  ripemd_test(void);
int  openssl_test(void);   /* test mini api */
int  pbkdf1_test(void);
int  pkcs12_test(void);
int  pbkdf2_test(void);
#ifdef HAVE_ECC
int  ecc_test(void);
#ifdef HAVE_ECC_ENCRYPT
int  ecc_encrypt_test(void);
#endif
#endif
#ifdef HAVE_CURVE25519
int  curve25519_test(void);
#endif
#ifdef HAVE_ED25519
int  ed25519_test(void);
#endif
#ifdef HAVE_BLAKE2
int  blake2b_test(void);
#endif
#ifdef HAVE_LIBZ
int compress_test(void);
#endif
#ifdef HAVE_PKCS7
int pkcs7enveloped_test(void);
int pkcs7signed_test(void);
#endif
#if defined(WOLFSSL_CERT_EXT) && defined(WOLFSSL_TEST_CERT)
int  certext_test(void);
#endif
