#include <stdint.h>
#include <stdio.h>


struct packet {
    uint8_t crc;
    uint8_t status;
    uint8_t payload;
    uint8_t cha;
    uint8_t sensor;
    uint8_t long_addr;
    uint8_t short_addr;
    uint8_t addr_mode;
    /*
    uint32_t crc :2;
    uint32_t status :1;
    uint32_t payload :12;
    uint32_t cha :3;
    uint32_t sensor :3;
    uint32_t long_addr :8;
    uint32_t short_addr :2;
    uint32_t addr_mode :1;
    */
};

int main()
{
    printf("hi ben \n");

    uint32_t packetData;
    printf("please enter the packet data \n");
    fflush(stdout);
    scanf("%x",&packetData);

    struct packet fram;

    fram.crc = (uint8_t)(packetData & 0x03);
    fram.status = (uint8_t)(packetData >>2 & 0x1);
    fram.payload = (uint16_t)(packetData >>3 & 0xFFF);
    fram.cha = (uint8_t)(packetData >>15 & 0x7);
    fram.sensor = (uint8_t)(packetData >>18 & 0x7);
    fram.short_addr = (uint8_t)(packetData >>21 & 0xFF);
    fram.long_addr = (uint8_t)(packetData >>29 & 0x3);
    fram.addr_mode = (uint8_t)(packetData >>31 & 0x1);

    printf("crc is : %x \n", fram.crc);
    fflush(stdout);
    printf("ststus is : %x \n", fram.status);
    fflush(stdout);
    printf("payload is : %x \n", fram.payload);
    fflush(stdout);
    printf("cha is : %x \n", fram.cha);
    fflush(stdout);
    printf("sensor is : %x \n", fram.sensor);
    fflush(stdout);
    printf("short_addr is : %x \n", fram.short_addr);
    fflush(stdout);
    printf("long_addr is : %x \n", fram.long_addr);
    fflush(stdout);
    printf("addr_mode is : %x \n", fram.addr_mode);
    fflush(stdout);
   
    printf("size of struct is %d \n", sizeof(fram));

    return 0;
}