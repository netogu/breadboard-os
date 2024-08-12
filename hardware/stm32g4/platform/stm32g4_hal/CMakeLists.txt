cmake_minimum_required(VERSION 3.22)


target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    STM32G4xx_HAL_Driver/Inc
    STM32G4xx_HAL_Driver/Inc/Legacy
    CMSIS/Device/ST/STM32G4xx/Include
    CMSIS/Include
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc_ex.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ex.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ramfunc.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_gpio.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_exti.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma_ex.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr_ex.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_cortex.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_tim.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_tim_ex.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_usart.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_usart_ex.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart_ex.c
    STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart.c
)



