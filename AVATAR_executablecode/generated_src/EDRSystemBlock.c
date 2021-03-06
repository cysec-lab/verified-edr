#include "EDRSystemBlock.h"

#define STATE__START__STATE 0
#define STATE__EDRSystemStartState 1
#define STATE__PacketCaptureState 2
#define STATE__PacketParseState 3
#define STATE__ParseSpeedState 4
#define STATE__CheckValidationResultState 5
#define STATE__RecordInEDRState 6
#define STATE__CheckRecordInEDRResultState 7
#define STATE__WroteEventToRecordState 8
#define STATE__EDRSystemEndState 9
#define STATE__EDRErrorState 10
#define STATE__NormalLoopState 11
#define STATE__ValidationErrorState 12
#define STATE__ParseDoorState 13
#define STATE__ParseIndicatorState 14
#define STATE__STOP__STATE 15

void *mainFunc__EDRSystemBlock(void *arg)
{
    int32_t fd;
    int64_t timestamp;
    can_packet canPacket;
    uint32_t canID;
    uint8_t canDLC;
    uint8_t *data;
    fstar_uint16 speed;
    uint16_t speedValue;
    fstar_uint8 indicator;
    uint8_t indicatorValue;
    fstar_uint8 door;
    uint8_t doorValue;
    C_String_t message;
    uint32_t code;
    int32_t recordInEDRResult;

    int __currentState = STATE__START__STATE;

    char *__myname = (char *)arg;

    pthread_cond_init(&__myCond__EDRSystemBlock, NULL);

    fillListOfRequests(&__list__EDRSystemBlock, __myname, &__myCond__EDRSystemBlock, &__mainMutex);
    // printf("my name = %s\n", __myname);

    /* Main loop on states */
    while (__currentState != STATE__STOP__STATE)
    {
        switch (__currentState)
        {
        case STATE__START__STATE:
            __currentState = STATE__EDRSystemStartState;
            break;

        case STATE__EDRSystemStartState:
            fd = getSocket();
            __currentState = STATE__PacketCaptureState;
            break;

        case STATE__PacketCaptureState:
            canPacket = packetCapture(fd);
            canID = canPacket.can_id;
            canDLC = canPacket.can_dlc;
            data = canPacket.data;
            timestamp = canPacket.timestamp;
            __currentState = STATE__PacketParseState;
            break;

        case STATE__PacketParseState:
            if (canID != 0x1b4 && canID != 0x188 && canID != 0x19b)
            {
                makeNewRequest(&__req0__EDRSystemBlock, 254, IMMEDIATE, 0, 0, 0, 0, __params0__EDRSystemBlock);
                addRequestToList(&__list__EDRSystemBlock, &__req0__EDRSystemBlock);
            }
            if (canID == 0x1b4)
            {
                makeNewRequest(&__req1__EDRSystemBlock, 303, IMMEDIATE, 0, 0, 0, 0, __params1__EDRSystemBlock);
                addRequestToList(&__list__EDRSystemBlock, &__req1__EDRSystemBlock);
            }
            if (canID == 0x188)
            {
                makeNewRequest(&__req2__EDRSystemBlock, 307, IMMEDIATE, 0, 0, 0, 0, __params2__EDRSystemBlock);
                addRequestToList(&__list__EDRSystemBlock, &__req2__EDRSystemBlock);
            }
            if (canID == 0x19b)
            {
                makeNewRequest(&__req3__EDRSystemBlock, 311, IMMEDIATE, 0, 0, 0, 0, __params3__EDRSystemBlock);
                addRequestToList(&__list__EDRSystemBlock, &__req3__EDRSystemBlock);
            }
            if (nbOfRequests(&__list__EDRSystemBlock) == 0)
            {
                debug2Msg(__myname, "No possible request");
                __currentState = STATE__STOP__STATE;
                break;
            }
            __returnRequest__EDRSystemBlock = executeListOfRequests(&__list__EDRSystemBlock);
            clearListOfRequests(&__list__EDRSystemBlock);
            if (__returnRequest__EDRSystemBlock == &__req0__EDRSystemBlock)
            {
                __currentState = STATE__PacketCaptureState;
            }
            else if (__returnRequest__EDRSystemBlock == &__req1__EDRSystemBlock)
            {
                __currentState = STATE__ParseSpeedState;
            }
            else if (__returnRequest__EDRSystemBlock == &__req2__EDRSystemBlock)
            {
                __currentState = STATE__ParseIndicatorState;
            }
            else if (__returnRequest__EDRSystemBlock == &__req3__EDRSystemBlock)
            {
                __currentState = STATE__ParseDoorState;
            }
            break;

        case STATE__ParseSpeedState:
            speed = parseSpeed(canID, canDLC, data);
            code = speed.error.code;
            message = speed.error.message;
            speedValue = speed.value;
            __currentState = STATE__CheckValidationResultState;
            break;

        case STATE__CheckValidationResultState:
            if (code == 0)
            {
                makeNewRequest(&__req0__EDRSystemBlock, 377, IMMEDIATE, 0, 0, 0, 0, __params0__EDRSystemBlock);
                addRequestToList(&__list__EDRSystemBlock, &__req0__EDRSystemBlock);
            }
            if (code > 0)
            {
                makeNewRequest(&__req1__EDRSystemBlock, 380, IMMEDIATE, 0, 0, 0, 0, __params1__EDRSystemBlock);
                addRequestToList(&__list__EDRSystemBlock, &__req1__EDRSystemBlock);
            }
            if (nbOfRequests(&__list__EDRSystemBlock) == 0)
            {
                debug2Msg(__myname, "No possible request");
                __currentState = STATE__STOP__STATE;
                break;
            }
            __returnRequest__EDRSystemBlock = executeListOfRequests(&__list__EDRSystemBlock);
            clearListOfRequests(&__list__EDRSystemBlock);
            if (__returnRequest__EDRSystemBlock == &__req0__EDRSystemBlock)
            {
                __currentState = STATE__RecordInEDRState;
            }
            else if (__returnRequest__EDRSystemBlock == &__req1__EDRSystemBlock)
            {
                __currentState = STATE__ValidationErrorState;
            }
            break;

        case STATE__RecordInEDRState:
            recordInEDRResult = recordInEDR(canID, timestamp, speedValue, indicatorValue, doorValue);
            __currentState = STATE__CheckRecordInEDRResultState;
            break;

        case STATE__CheckRecordInEDRResultState:
            if (recordInEDRResult == 0)
            {
                makeNewRequest(&__req0__EDRSystemBlock, 280, IMMEDIATE, 0, 0, 0, 0, __params0__EDRSystemBlock);
                addRequestToList(&__list__EDRSystemBlock, &__req0__EDRSystemBlock);
            }
            if (recordInEDRResult == 1)
            {
                makeNewRequest(&__req1__EDRSystemBlock, 285, IMMEDIATE, 0, 0, 0, 0, __params1__EDRSystemBlock);
                addRequestToList(&__list__EDRSystemBlock, &__req1__EDRSystemBlock);
            }
            if (recordInEDRResult == 2)
            {
                makeNewRequest(&__req2__EDRSystemBlock, 289, IMMEDIATE, 0, 0, 0, 0, __params2__EDRSystemBlock);
                addRequestToList(&__list__EDRSystemBlock, &__req2__EDRSystemBlock);
            }
            if (nbOfRequests(&__list__EDRSystemBlock) == 0)
            {
                debug2Msg(__myname, "No possible request");
                __currentState = STATE__STOP__STATE;
                break;
            }
            __returnRequest__EDRSystemBlock = executeListOfRequests(&__list__EDRSystemBlock);
            clearListOfRequests(&__list__EDRSystemBlock);
            if (__returnRequest__EDRSystemBlock == &__req0__EDRSystemBlock)
            {
                __currentState = STATE__NormalLoopState;
            }
            else if (__returnRequest__EDRSystemBlock == &__req1__EDRSystemBlock)
            {
                __currentState = STATE__WroteEventToRecordState;
            }
            else if (__returnRequest__EDRSystemBlock == &__req2__EDRSystemBlock)
            {
                __currentState = STATE__EDRErrorState;
            }
            break;

        case STATE__WroteEventToRecordState:
            __currentState = STATE__EDRSystemEndState;
            break;

        case STATE__EDRSystemEndState:
            __currentState = STATE__STOP__STATE;
            break;

        case STATE__EDRErrorState:
            __currentState = STATE__PacketCaptureState;
            break;

        case STATE__NormalLoopState:
            __currentState = STATE__PacketCaptureState;
            break;

        case STATE__ValidationErrorState:
            __currentState = STATE__PacketCaptureState;
            break;

        case STATE__ParseDoorState:
            door = parseDoor(canID, canDLC, data);
            code = door.error.code;
            message = door.error.message;
            doorValue = door.value;
            __currentState = STATE__CheckValidationResultState;
            break;

        case STATE__ParseIndicatorState:
            indicator = parseIndicator(canID, canDLC, data);
            code = indicator.error.code;
            message = indicator.error.message;
            indicatorValue = indicator.value;
            __currentState = STATE__CheckValidationResultState;
            break;
        }
    }
    // printf("Exiting = %s\n", __myname);
    return NULL;
}
