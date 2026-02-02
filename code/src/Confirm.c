/* Confirm.c */

//엘리베이터 동작 여부, 목표 층, 동작 방향
#include <Confirm.h>

//엘리베이터 동작 여부 결정 (문 여닫힘 포함)
void Confirm_state(uint8_t floor_state[4], uint8_t *Elevator_state)
{
    uint8_t num = 0; //눌린 버튼의 개수
    for (int i = 0; i < 4; i++) {
        if (floor_state[i] == 1)
            num++;
    }
    if (num != 0) //눌린 버튼이 있다면
        *Elevator_state = 1; //동작 중
    else //없다면
        *Elevator_state = 0; //정지
}
//목표 층 결정
void Confirm_floor(uint8_t direction, uint8_t Current_floor, uint8_t *Goal_floor, uint8_t floor_state[4])
{
    if (direction == 0) { //정지 상태 (num=0에서 num=1이 된 상황)
        for (int i = 0; i < 4; i++) {
            if (floor_state[i] == 1) {
                *Goal_floor = (uint8_t)i; //버튼이 눌린 곳을 목표 층으로
                return;
            }
        }
    }
    else if (direction == 1) { //올라가는 중
        if ((Current_floor == *Goal_floor) && (floor_state[Current_floor] != 1)) { //목표 층에 도달한 직후 다음 목표 층 결정할 때
            for (int i = Current_floor + 1; i < 4; i++) { //올라가는 중이었으므로, 윗층부터 가까운 순서로 확인
                if (floor_state[i] == 1) {
                    *Goal_floor = (uint8_t)i;
                    return; //버튼이 눌린 곳이 있다면, 목표 층 결정
                }
            }
            for (int i = Current_floor - 1; i >= 0; i--) { //윗층에 없다면, 아래층 가까운 순서로 확인
                if (floor_state[i] == 1) {
                    *Goal_floor = (uint8_t)i;
                    return; //버튼이 눌린 곳이 있다면, 목표 층 결정
                }
            }
        }
        else if (Current_floor != *Goal_floor) { //목표 층으로 가는 중일 때
            for (int i = Current_floor + 1; i < 4; i++) { //올라가는 중이므로, 윗층만 가까운 순서로 확인
                if (floor_state[i] == 1) {
                    *Goal_floor = (uint8_t)i;
                    return; //버튼이 눌린 곳이 있다면, 목표 층 결정
                }
            }
        }
    }
    else if (direction == 2) { //내려가는 중
        if ((Current_floor == *Goal_floor) && (floor_state[Current_floor] != 1)){ //목표 층에 도달한 직후 다음 목표 층 결정할 때
            for (int i = Current_floor - 1; i >= 0; i--) { //내려가는 중이었으므로, 이래층부터 가까운 순서로 확인
                if (floor_state[i] == 1) {
                    *Goal_floor = (uint8_t)i;
                    return; //버튼이 눌린 곳이 있다면, 목표 층 결정
                }
            }
            for (int i = Current_floor + 1; i < 4; i++) { //아래층에 없다면, 윗층 가까운 순서로 확인
                if (floor_state[i] == 1) {
                    *Goal_floor = (uint8_t)i;
                    return; //버튼이 눌린 곳이 있다면, 목표 층 결정
                }
            }
        }
        else if (Current_floor != *Goal_floor) { //목표 층으로 가는 중일 때
            for (int i = Current_floor - 1; i >= 0; i--) { //내려가는 중이므로, 아래층만 가까운 순서로 확인
                if (floor_state[i] == 1) {
                    *Goal_floor = (uint8_t)i;
                    return; //버튼이 눌린 곳이 있다면, 목표 층 결정
                }
            }
        }
    }
}
//엘리베이터 방향 결정
void Confirm_direction(uint8_t Elevator_state, uint8_t *direction, uint8_t Current_floor, uint8_t Goal_floor)
{
    if (Elevator_state == 0) //정지 상태
        *direction = 0;
    else {
        if (Current_floor < Goal_floor) //올라가는 중
            *direction = 1;
        else if (Current_floor > Goal_floor) //내려가는 중
            *direction = 2;
        //목표 층에 도달했을 때는 기존 방향 유지
    }
}
