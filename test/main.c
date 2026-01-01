#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../src/crc.h"

#define CRC_BYTES           (100)

static void test_init(void)
{
    srand(time(NULL));
}

static int generateData(uint8_t *data, uint16_t size)
{
    if (data == NULL) {
        return -1;
    }

    for (uint16_t i = 0; i < size; i++) {
        data[i] = rand() & 0xFF;
    }

    return size;
}

static void printData(uint8_t *data, uint32_t len, const char *tag)
{
    if (data == NULL) {
        printf("data is NULL\n");
        printf("print data fail\n");
        return;
    }

    printf("\n==================================================\n");
    if (tag == NULL) {
        printf("print data:\n");
    } else {
        printf("%s:\n", tag);
    }
    for (uint32_t i = 0; i < len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n==================================================\n");
}

int main()
{
    uint8_t data[CRC_BYTES] = { 0 };
    uint32_t len = 0;
    uint64_t crc = 0;

    test_init();
    
    len = generateData(data, CRC_BYTES);
    if (len < 0) {
        printf("generate data fail!\n");
        return len;
    }
    printData(data, len, "generate data");

    if (crc64_ecma(data, len, &crc)) {
        printf("calc crc fail!\n");
        return -1;
    }
    printf("crc: %016llx\n", crc);

    return 0;
}
