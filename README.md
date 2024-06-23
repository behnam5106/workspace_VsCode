32-bit Packet Decoder -- Embedded Programming

Overview:
This repository contains a simple C program that decodes a 32-bit packet of data into its constituent parts. 
The packet is divided into eight parts with varying bit sizes. The program takes a 32-bit hexadecimal input from the user, decodes it, 
and displays the individual parts.

Packet Structure:
The 32-bit packet is defined as follows:

Part8  Part7  Part6       Part5  Part4   Part3             Part2   Part1
[0]    [00]   [00000000]  [000]  [000]   [0000 0000 0000]  [0]     [00]


c
Copy code
#include <stdint.h>
#include <stdio.h>

// Define the packet structure to store decoded fields
struct packet {
    uint32_t part1 : 2;
    uint32_t part2 : 1;
    uint32_t part3 : 12;
    uint32_t part4 : 3;
    uint32_t part5 : 3;
    uint32_t part6 : 8;
    uint32_t part7 : 2;
    uint32_t part8 : 1;
};
Main Function
c
Copy code
int main() {
    printf("32-bit Packet Decoder -- Embedded Programming \n");

    uint32_t packetData;
    printf("please enter the 32-bit packet data in hexadecimal format: \n");
    scanf("%x", &packetData);

    // Create an instance of the packet struct
    struct packet fram;

    // Extract fields from the 32-bit packet using bitwise operations
    fram.part1 = (uint8_t)(packetData & 0x03);
    fram.part2 = (uint8_t)(packetData >> 2 & 0x1);
    fram.part3 = (uint16_t)(packetData >> 3 & 0xFFF);
    fram.part4 = (uint8_t)(packetData >> 15 & 0x7);
    fram.part5 = (uint8_t)(packetData >> 18 & 0x7);
    fram.part6 = (uint8_t)(packetData >> 21 & 0xFF);
    fram.part7 = (uint8_t)(packetData >> 29 & 0x3);
    fram.part8 = (uint8_t)(packetData >> 31 & 0x1);

    // Display the extracted fields
    printf("part1 is : %x \n", fram.part1);
    printf("part2 is : %x \n", fram.part2);
    printf("part3 is : %x \n", fram.part3);
    printf("part4 is : %x \n", fram.part4);
    printf("part5 is : %x \n", fram.part5);
    printf("part6 is : %x \n", fram.part6);
    printf("part7 is : %x \n", fram.part7);
    printf("part8 is : %x \n", fram.part8);

    // Display the size of the struct
    printf("Size of struct is: %d bytes \n", (int)sizeof(fram));

    return 0;
}


Comments and Notes:
The packet structure uses bit fields to define each part of the packet. This approach ensures that the structure size is minimized.
The program uses bitwise operations to extract each part from the 32-bit input.
The size of the structure is displayed to show the memory footprint of the packet structure.
This repository provides a simple yet effective way to decode a 32-bit packet, making it a useful tool for embedded programming tasks.
