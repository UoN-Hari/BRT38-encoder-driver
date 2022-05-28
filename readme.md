# BRT38-encoder-driver
## Hardware Information
MCU: STM32F407IGH6, RoboMaster Dev Board type C  
Encoder: BRT38

### Connection  
MCU <---- CAN 1 ----> BRT38  

## Software Information  
IDE: STM32CubeIDE v1.8.0  
Programming language: C++  
Firmware Package: STM32Cube FW_F4 v1.26.2  
System: FreeRTOS v10.3.1  

### Clock Settings  
Clock frequency: 168 MHz  
Clock source: HSE 12 MHz
Timebase source: TIM1

### Enabled Interrupt  
CAN1 TX  
CAN1 RX0  

### Thread Information
Thread number: 1  
Thread frequency: 1 kHz  
Newlib settings: Enabled  