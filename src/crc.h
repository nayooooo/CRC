/*
 * Copyright (c) 2025-2026, nayooooo
 *
 * SPDX-License-Identifier: MIT
 *
 * @brief Can calculate CRC with a width of 1-32 bits.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-04-24     nayooooo     the first version
 */

#ifndef __CRC_H__
#define __CRC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

#define USE_CRC_REF_TABEL       (0)

/**
 * @brief Calculate the CRC check result of the data.
 *
 * @param data Data to be verified, 0 is the left, len - 1 is the right.
 * @param len The length of the data to be verified (in byte).
 * @param result CRC verification result.
 * @param order The order of polynomials, 1-32.
 * @param poly The polynomial.
 * @param init The initial value.
 * @param xorout The XOR value of the result.
 * @param refin Input reflect.
 * @param refout Output reflect.
 * @return
 */
int crc(const uint8_t *data, uint32_t len, uint32_t *result,
        uint8_t order, uint32_t poly, uint32_t init, uint32_t xorout,
        bool refin, bool refout);

/**
 * @brief Calculate the CRC check result of the data.
 *
 * @param data Data to be verified, 0 is the left, len - 1 is the right.
 * @param len The length of the data to be verified (in byte).
 * @param result CRC verification result.
 * @param order The order of polynomials, 1-64.
 * @param poly The polynomial.
 * @param init The initial value.
 * @param xorout The XOR value of the result.
 * @param refin Input reflect.
 * @param refout Output reflect.
 * @return
 */
int crc_expand64(const uint8_t *data, uint32_t len, uint64_t *result,
                uint8_t order, uint64_t poly, uint64_t init, uint64_t xorout,
                bool refin, bool refout);

int crc8(const uint8_t *data, uint32_t len, uint32_t *result);
int crc8_itu(const uint8_t *data, uint32_t len, uint32_t *result);
int crc8_rohc(const uint8_t *data, uint32_t len, uint32_t *result);
int crc8_maxim(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_ibm(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_maxim(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_usb(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_modbus(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_ccitt(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_ccitt_false(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_x25(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_xmodem(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_xmodem2(const uint8_t *data, uint32_t len, uint32_t *result);
int crc16_dnp(const uint8_t *data, uint32_t len, uint32_t *result);
int crc24_q(const uint8_t *data, uint32_t len, uint32_t *result);
int crc32(const uint8_t *data, uint32_t len, uint32_t *result);
int crc32_c(const uint8_t *data, uint32_t len, uint32_t *result);
int crc32_koopman(const uint8_t *data, uint32_t len, uint32_t *result);
int crc32_mpeg_2(const uint8_t *data, uint32_t len, uint32_t *result);
int crc64_iso(const uint8_t *data, uint32_t len, uint64_t *result);
int crc64_ecma(const uint8_t *data, uint32_t len, uint64_t *result);

#ifdef __cplusplus
}
#endif

#endif /* __CRC_H__ */
