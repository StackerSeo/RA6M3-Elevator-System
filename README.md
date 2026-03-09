# RA6M3-Elevator-System
RA6M3 기반 엘리베이터 시스템: 4층 스위치 입력 및 DC/서보 모터 제어와 CAN 통신 모니터링 구현
- RA6M3 MCU를 활용하여 입력 처리부터 복합 모터 제어, CAN 통신 모니터링까지 구현한 종합 엘리베이터 제어 시스템

---

## Key Features
- Full Interaction: 4개 층 스위치 입력을 통한 개별 호출 및 우선순위 이동 로직 구현
- Dual Motor Precision Control:
  - DC Motor: PWM 제어를 통해 엘리베이터의 부드러운 승강 및 층간 정지 구현
  - Servo Motor: 도착 시 엘리베이터 문(Door)의 개폐 동작 제어
- Visual & Audio Feedback:
  - 7-Segment로 현재 위치 표시 및 LED로 호출 대기 상태 가시화
  - DAC 스피커를 사용하여 층 도착 시 안내 멜로디 출력
- Real-time CAN Monitoring: CAN 통신 프로토콜을 설계하여 PC에서 현재 층, 모터 상태, 입력 로그를 실시간 확인 가능

## Tech Stack
- MCU: Renesas RA6M3 (R7FA6M3AH3CFC)
- Development Environment: e2 studio, FSP (Flexible Software Package)
- Language: C (Firmware)

## System Architecture

```mermaid
graph TD
    %% 입력부
    subgraph Inputs [User Interface - Input]
        SW1[1F Switch] --- MCU
        SW2[2F Switch] --- MCU
        SW3[3F Switch] --- MCU
        SW4[4F Switch] --- MCU
    end

    %% 중앙 제어
    subgraph Control_Unit [Main Controller]
        MCU((RA6M3 MCU))
    end

    %% 출력부
    subgraph Outputs [Actuators & Display]
        MCU ---|GPIO/Scan| FND[7-Seg: Floor Display]
        MCU ---|GPIO| LED[Call Indicators]
        MCU ==>|PWM| DC[DC Motor: Lift]
        MCU ==>|PWM| SERVO[Servo Motor: Door]
        MCU ---|DAC| SPK[Speaker: Arrival Chime]
    end

    %% 통신
    subgraph Communication [Monitoring]
        MCU == "CAN Bus" ==> PC[PC GUI Monitor]
    end

    %% 스타일링
    style MCU fill:#f9f,stroke:#333,stroke-width:2px
    style Control_Unit fill:#fff5f5,stroke:#ff0000,stroke-dasharray: 5 5

```
---

## Project Structure
```text
├── code/                          # RA6M3 C 소스 코드 (e2 studio Project)
│   ├── .settings/                 # 컴파일러 옵션 및 프로젝트 환경 설정 (숨김 폴더)
│   ├── ra/                        # FSP 라이브러리 소스 및 드라이버 본체
│   ├── ra_cfg/                    # FSP 구성(Configuration) 헤더 파일
│   ├── ra_gen/                    # FSP에서 자동 생성한 설정 코드
│   ├── script/                    # 링커 스크립트 (.ld) 등 빌드 관련 스크립트
│   ├── src/                       # 엘리베이터 제어 로직 및 CAN 통신 드라이버
│   ├── configuration.xml          # FSP 그래픽 설정 저장 파일
│   └── R7FA6M3AH3CFC.pincfg       # MCU 핀 할당 설정 파일
|
├── docs/                          # 설계 문서 및 시스템 다이어그램
│   ├── Hardware_Setup.md          # 회로 구성 및 하드웨어 연결 가이드
│   ├── Communication_Protocol.md  # 통신 프로토콜 정의
│   └── Software_Implementation.md # 소프트웨어 알고리즘 및 구현 방식
|
├── video/                         # 시스템 동작 및 엘리베이터 제어 시연 영상
|
└── README.md                      # 프로젝트 개요, 시스템 아키텍처 등 안내 문서
```
