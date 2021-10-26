#include <linux/can.h>
#include <linux/can/raw.h>

int getSocket();

typedef struct
{
    canid_t can_id; /* 32 bit CAN_ID + EFF/RTR/ERR flags */
    __u8 can_dlc;   /* data length code: 0 .. 8 */
    __u8 data[8] __attribute__((aligned(8)));
    time_t timestamp;
} can_packet;

can_packet packetCapture(int fd);

void printFrame(can_packet frame);