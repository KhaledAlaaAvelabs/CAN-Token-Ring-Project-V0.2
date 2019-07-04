# CAN-Token-Ring-Project-V0.2


• CAN network from 3 ECU (Node ID 1, 2 and 3).

• Each node on the bus has 2 states: Startup state and Normal state.

• Each ECU has led which turn on when ECU receive token.

• ECU should enter startup state when power is turned on.

At Startup State:

• The lowest address ECU transmit token to the higher address ECU and switch its state to normal state.

• Other ECUs should wait until receiving the first token and switch its state to normal state.

At Normal state:

• When token is received:

• Turn on led for 1 second.

• Pass token to higher address node after one second delay.

• Turn off the led.



#Project description:

Project_Name: FreeRTOS_Tiva 

files includes:
1- FreeRTOS_Files folder; include free RTOS implimentaion.

2- GPIO folder include; "GPIO.h, GPIO.c"

3- CAN folder include; "CAN.h, CAN.c"

4- Main folder include; main.c
