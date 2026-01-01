#include "crc.h"

int crc8(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 8, 0x07U, 0U, 0U, (bool)false, (bool)false);
}

int crc8_itu(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 8, 0x07U, 0U, 0x55U, (bool)false, (bool)false);
}

int crc8_rohc(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 8, 0x07U, 0xFFU, 0U, (bool)true, (bool)true);
}

int crc8_maxim(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 8, 0x31U, 0U, 0U, (bool)true, (bool)true);
}

int crc16_ibm(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x8005U, 0U, 0U, (bool)true, (bool)true);
}

int crc16_maxim(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x8005U, 0U, 0xFFFFU, (bool)true, (bool)true);
}

int crc16_usb(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x8005U, 0xFFFFU, 0xFFFFU, (bool)true, (bool)true);
}

int crc16_modbus(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x8005U, 0xFFFFU, 0U, (bool)true, (bool)true);
}

int crc16_ccitt(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x1021U, 0U, 0U, (bool)true, (bool)true);
}

int crc16_ccitt_false(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x1021U, 0xFFFFU, 0U, (bool)false, (bool)false);
}

int crc16_x25(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x1021U, 0xFFFFU, 0xFFFFU, (bool)true, (bool)true);
}

int crc16_xmodem(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x1021U, 0U, 0U, (bool)false, (bool)false);
}

int crc16_xmodem2(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x8408U, 0U, 0U, (bool)true, (bool)true);
}

int crc16_dnp(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 16, 0x3D65U, 0U, 0xFFFFU, (bool)true, (bool)true);
}

int crc24_q(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 24, 0x864CFBU, 0U, 0U, (bool)false, (bool)false);
}

int crc32(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 32, 0x04C11DB7U, 0xFFFFFFFFU, 0xFFFFFFFFU, (bool)true, (bool)true);
}

int crc32_c(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 32, 0x1EDC6F41U, 0xFFFFFFFFU, 0xFFFFFFFFU, (bool)true, (bool)true);
}

int crc32_koopman(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 32, 0x741B8CD7U, 0xFFFFFFFFU, 0xFFFFFFFFU, (bool)true, (bool)true);
}

int crc32_mpeg_2(const uint8_t *data, uint32_t len, uint32_t *result)
{
    return crc(data, len, result, 32, 0x04C11DB7U, 0xFFFFFFFFU, 0U, (bool)false, (bool)false);
}
