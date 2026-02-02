# Communication Protocol (CAN Bus)

본 프로젝트는 CAN 2.0B 표준을 사용하여 엘리베이터의 실시간 상태를 송신합니다.

## 1. CAN Configuration
- Baudrate: 500 kbps
- Standard ID: 11-bit

## 2. Message Format (ID: 0x100)
엘리베이터 상태 데이터 (MCU -> PC)

| Byte | Data | Description |
| :--- | :--- | :--- |
| 0 | Current Floor | 1 (0x01) ~ 4 (0x04) |
| 1 | Lift Status | 0: IDLE, 1: UP, 2: DOWN |
| 2 | Door Status | 0: CLOSED, 1: OPENING, 2: OPENED, 3: CLOSING |
| 3 | Last Registered | 마지막으로 눌린 스위치 번호 |

## 3. Control Command (ID: 0x200)
PC에서 강제 제어 시 사용 (PC -> MCU)
- Data[0]: Target Floor (1~4)
