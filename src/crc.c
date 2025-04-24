#include "crc.h"

static uint32_t reflect(uint32_t data, uint8_t bits)
{
    if (bits <= 1 || bits > 32) return data;

    uint32_t result = 0;
    for (uint8_t i = 0; i < bits; i++)
    {
        result |= ((data >> i) & 0x1) << (bits - 1 - i);
    }
    return result;
}

int crc(const uint8_t *data, uint32_t len, uint32_t *result,
        uint8_t order, uint32_t poly, uint32_t init, uint32_t xorout,
        bool refin, bool refout)
{
    if (order <= 0 || order > 32 || data == NULL || len <= 0 || result == NULL)
    {
        return -1;
    }

    uint32_t mask = (order == 32) ? 0xFFFFFFFF : (1UL << order) - 1;
    poly &= mask;
    init &= mask;
    xorout &= mask;

    uint32_t res = 0;
    uint8_t bit_counter_for_init = 0;
    for (uint32_t i = 0; i < len; i++)
    {
        uint8_t byte = data[i];
        if (refin)
        {
            byte = reflect(byte, 8);
        }
        for (uint8_t j = 0; j < 8; j++)
        {
            uint8_t top_bit = (res >> (order - 1)) & 1;
            res = (res << 1) & mask;
            res |= byte >> (7 - j) & 0x01;
            if (bit_counter_for_init < order)
            {
                bit_counter_for_init ++;
                if (bit_counter_for_init == order)
                {
                    res ^= init;
                }
            }
            if (top_bit)
            {
                res ^= poly;
            }
        }
    }
    for (uint8_t i = 0; i < order; i++)
    {
        uint8_t top_bit = (res >> (order - 1)) & 1;
        res = (res << 1) & mask;
        if (top_bit)
        {
            res ^= poly;
        }
    }
    if (refout)
    {
        res = reflect(res, order);
    }
    res ^= xorout;
    res &= mask;
    *result = res;

    return 0;
}

int crc32(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 32, 0x04C11DB7U, 0xFFFFFFFFU, 0xFFFFFFFFU, (bool)true, (bool)true);
}
