# Software Implementation

## 1. Elevator State Machine
엘리베이터의 동작은 다음과 같은 상태 기반 로직으로 구동됩니다.

1. IDLE: 호출을 기다리는 대기 상태.
2. MOVING: 목적지 층으로 DC 모터 구동 (PWM 제어).
3. ARRIVED: 목적지 도착 시 모터 정지 및 DAC 안내음 출력.
4. DOOR_OPEN: 서보 모터를 90도로 회전하여 문 개방.
5. DOOR_CLOSE: 일정 시간 후 서보 모터를 0도로 회전하여 문 폐쇄.

## 2. Dynamic Scanning (7-Segment)
- 타이머 인터럽트를 활용하여 1ms 주기로 7-Segment를 스캐닝하여 현재 층수를 잔상 효과로 표시합니다.

## 3. CAN Interrupt
- 수신 인터럽트를 통해 PC로부터 오는 강제 호출 명령을 실시간으로 처리합니다.
