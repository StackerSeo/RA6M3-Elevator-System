/* CAN.c */

#include <CAN.h>

void Send_to_PC(uint8_t identifier, uint8_t N)
{
    uint8_t message[8]; //8byte message
    switch (identifier) {
        //처음 Program 실행 시
        case 0 : message[0] = 0x43; //C
                 message[1] = 0x41; //A
                 message[2] = 0x4E; //N
                 message[3] = 0x20; //SPACE
                 message[4] = 0x4F; //O
                 message[5] = 0x4B; //K
                 message[6] = 0x41; //A
                 message[7] = 0x59; //Y
                 break;
        //DC Motor 작동이 시작할 때
        case 1 : message[0] = 0x4D; //M
                 message[1] = 0x4F; //O
                 message[2] = 0x56; //V
                 message[3] = 0x45; //E
                 message[4] = 0x54; //T
                 message[5] = 0x4F; //O
                 message[6] = 0x20; //SPACE
                 message[7] = DECtoASCII(N); //input N
                 break;
        //DC Motor 작동이 끝날 때
        case 2 : message[0] = 0x41; //A
                 message[1] = 0x52; //R
                 message[2] = 0x52; //R
                 message[3] = 0x49; //I
                 message[4] = 0x54; //T
                 message[5] = 0x4F; //O
                 message[6] = 0x20; //SPACE
                 message[7] = DECtoASCII(N); //input N
                 break;
        //문열림 시작할 때
        case 3 : message[0] = 0x44; //D
                 message[1] = 0x52; //R
                 message[2] = 0x20; //SPACE
                 message[3] = 0x4F; //O
                 message[4] = 0x50; //P
                 message[5] = 0x45; //E
                 message[6] = 0x4E; //N
                 message[7] = 0x21; //!
                 break;
        //문닫힘 시작할 때
        case 4 : message[0] = 0x44; //D
                 message[1] = 0x52; //R
                 message[2] = 0x43; //C
                 message[3] = 0x4C; //L
                 message[4] = 0x4F; //O
                 message[5] = 0x53; //S
                 message[6] = 0x45; //E
                 message[7] = 0x21; //!
                 break;
        //그 외
        default : message[0] = 0x44; //D
                  message[1] = 0x45; //E
                  message[2] = 0x46; //F
                  message[3] = 0x41; //A
                  message[4] = 0x55; //U
                  message[5] = 0x4C; //L
                  message[6] = 0x54; //T
                  message[7] = 0x21; //!
                  break;
    }
    Send_message(message, sizeof(message));
}
void Send_message(uint8_t *message, uint8_t message_length)
{
    can_frame_t tx_frame;

    //reset
    memset(&tx_frame, 0, sizeof(can_frame_t));
    tx_frame.id = 0x123;
    tx_frame.type = CAN_FRAME_TYPE_DATA;
    tx_frame.id_mode = CAN_ID_MODE_STANDARD;
    tx_frame.data_length_code = message_length;

    //전송할 message 복사
    memcpy(tx_frame.data, message, message_length);

    // CAN 메시지 전송
    R_CAN_Write(&g_can0_ctrl, 0, &tx_frame);
}
//10진수를 ASCII code로 변환
uint8_t DECtoASCII(uint8_t N) {
    return N + '0';
}
