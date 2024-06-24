/*
BJ -- Jun 2024
32-bit Packet Decoder -- Embedded Programming
imagin that the 32 bit packet of data is define in 8 parts like this:

Part8  Part7  Part6       Part5  Part4   Part3             Part2   Part1
[0]    [00]   [00000000]  [000]  [000]   [0000 0000 0000]  [0]     [00]

******   Do not need to shif the bits regard of using Union structure.   ******
*/

#include <stdint.h>
#include <stdio.h>

// Define the packet structure to store decoded fields

union Packet{
    uint32_t packetValue;
    struct {
        uint32_t part1 :2;
        uint32_t part2 :1;
        uint32_t part3 :12;
        uint32_t part4 :3;
        uint32_t part5 :3;
        uint32_t part6 :8;
        uint32_t part7 :2;
        uint32_t part8 :1;    
    } packetFields;
} ;


int main(void)
{
    printf("32-bit Packet Decoder -- Embedded Programming \n");

    // Create an instance of the Packet Union
    union Packet frame;

    printf("please enter the 32-bit packet data in hexadecimal format: \n");
    scanf("%x",&frame.packetValue);

    
    // Display the extracted fields
    printf("part1 is : %x \n", frame.packetFields.part1);
    printf("part2 is : %x \n", frame.packetFields.part2);
    printf("part3 is : %x \n", frame.packetFields.part3);
    printf("part4 is : %x \n", frame.packetFields.part4);
    printf("part5 is : %x \n", frame.packetFields.part5);
    printf("part6 is : %x \n", frame.packetFields.part6);
    printf("part7 is : %x \n", frame.packetFields.part7);
    printf("part8 is : %x \n", frame.packetFields.part8);
   
   // Display the size of the struct
    printf("Size of struct is: %d bytes \n", (int)sizeof(frame.packetFields));

    return 0;
}