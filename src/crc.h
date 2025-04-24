/*
 * Copyright (c) 2006-2021, nayooooo
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
 * @param order The order of polynomials.
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

int crc32(const uint8_t *data, uint32_t len, uint32_t *result);

#endif /* __CRC_H__ */
