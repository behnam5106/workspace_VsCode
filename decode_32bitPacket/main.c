/*
BJ -- Jun 2024
32-bit Packet Decoder -- Embedded Programming
imagin that the 32 bit packet of data is define in 8 parts like this:

Part8  Part7  Part6       Part5  Part4   Part3             Part2   Part1
[0]    [00]   [00000000]  [000]  [000]   [0000 0000 0000]  [0]     [00]
*/

#include <stdint.h>
#include <stdio.h>

// Define the packet structure to store decoded fields
struct packet {

    //you can also define your struct like this, but the size of the struct will be increased
    /*
    uint8_t part1;
    uint8_t part2;
    uint16_t part3;
    uint8_t part4;
    uint8_t part5;
    uint8_t part6;
    uint8_t part7;
    uint8_t part8;
    */

    uint32_t part1 :2;
    uint32_t part2 :1;
    uint32_t part3 :12;
    uint32_t part4 :3;
    uint32_t part5 :3;
    uint32_t part6 :8;
    uint32_t part7 :2;
    uint32_t part8 :1;
    
};

int main()
{
    printf("32-bit Packet Decoder -- Embedded Programming \n");

    uint32_t packetData;
    printf("please enter the 32-bit packet data in hexadecimal format: \n");
    scanf("%x",&packetData);


    // Create an instance of the packet struct
    struct packet fram;

    // Extract fields from the 32-bit packet using bitwise operations
    fram.part1 = (uint8_t)(packetData & 0x03);
    fram.part2 = (uint8_t)(packetData >>2 & 0x1);
    fram.part3 = (uint16_t)(packetData >>3 & 0xFFF);
    fram.part4 = (uint8_t)(packetData >>15 & 0x7);
    fram.part5 = (uint8_t)(packetData >>18 & 0x7);
    fram.part7 = (uint8_t)(packetData >>21 & 0xFF);
    fram.part6 = (uint8_t)(packetData >>29 & 0x3);
    fram.part8 = (uint8_t)(packetData >>31 & 0x1);
    
    // Display the extracted fields
    printf("part1 is : %x \n", fram.part1);
    printf("part2 is : %x \n", fram.part2);
    printf("part3 is : %x \n", fram.part3);
    printf("part4 is : %x \n", fram.part4);
    printf("part5 is : %x \n", fram.part5);
    printf("part7 is : %x \n", fram.part7);
    printf("part6 is : %x \n", fram.part6);
    printf("part8 is : %x \n", fram.part8);
   
   // Display the size of the struct
    printf("Size of struct is: %d bytes \n", (int)sizeof(fram));

    return 0;
}