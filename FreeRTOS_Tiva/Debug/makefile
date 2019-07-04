################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./CAN/CAN.obj" \
"./FreeRTOS_Files/croutine.obj" \
"./FreeRTOS_Files/event_groups.obj" \
"./FreeRTOS_Files/heap_1.obj" \
"./FreeRTOS_Files/list.obj" \
"./FreeRTOS_Files/port.obj" \
"./FreeRTOS_Files/portasm.obj" \
"./FreeRTOS_Files/queue.obj" \
"./FreeRTOS_Files/stream_buffer.obj" \
"./FreeRTOS_Files/tasks.obj" \
"./FreeRTOS_Files/timers.obj" \
"./FreeRTOS_Files/tm4c123bh6pm_startup_ccs.obj" \
"./GPIO/GPIO.obj" \
"../FreeRTOS_Files/tm4c123bh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/ti/TivaWare_C_Series-2.1.4.178/driverlib/ccs/Debug/driverlib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include CAN/subdir_vars.mk
-include FreeRTOS_Files/subdir_vars.mk
-include GPIO/subdir_vars.mk
-include subdir_rules.mk
-include CAN/subdir_rules.mk
-include FreeRTOS_Files/subdir_rules.mk
-include GPIO/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
FreeRTOS_Tiva.out \

EXE_OUTPUTS__QUOTED += \
"FreeRTOS_Tiva.out" \

BIN_OUTPUTS += \
FreeRTOS_Tiva.hex \

BIN_OUTPUTS__QUOTED += \
"FreeRTOS_Tiva.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "FreeRTOS_Tiva.out"

# Tool invocations
FreeRTOS_Tiva.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123BH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"FreeRTOS_Tiva.map" --heap_size=0 --stack_size=512 -i"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/lib" -i"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="FreeRTOS_Tiva_linkInfo.xml" --rom_model -o "FreeRTOS_Tiva.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

FreeRTOS_Tiva.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armhex"  -o "FreeRTOS_Tiva.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "CAN\CAN.obj" "FreeRTOS_Files\croutine.obj" "FreeRTOS_Files\event_groups.obj" "FreeRTOS_Files\heap_1.obj" "FreeRTOS_Files\list.obj" "FreeRTOS_Files\port.obj" "FreeRTOS_Files\portasm.obj" "FreeRTOS_Files\queue.obj" "FreeRTOS_Files\stream_buffer.obj" "FreeRTOS_Files\tasks.obj" "FreeRTOS_Files\timers.obj" "FreeRTOS_Files\tm4c123bh6pm_startup_ccs.obj" "GPIO\GPIO.obj" 
	-$(RM) "main.d" "CAN\CAN.d" "FreeRTOS_Files\croutine.d" "FreeRTOS_Files\event_groups.d" "FreeRTOS_Files\heap_1.d" "FreeRTOS_Files\list.d" "FreeRTOS_Files\port.d" "FreeRTOS_Files\queue.d" "FreeRTOS_Files\stream_buffer.d" "FreeRTOS_Files\tasks.d" "FreeRTOS_Files\timers.d" "FreeRTOS_Files\tm4c123bh6pm_startup_ccs.d" "GPIO\GPIO.d" 
	-$(RM) "FreeRTOS_Files\portasm.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

