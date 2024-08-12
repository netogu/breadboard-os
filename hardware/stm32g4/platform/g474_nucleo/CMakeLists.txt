cmake_minimum_required(VERSION 3.22)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    Src/core.c
    Src/main.c
    Src/gpio.c
    Src/stm32g4xx_it.c
    Src/stm32g4xx_hal_msp.c
    Src/system_stm32g4xx.c
    Src/sysmem.c
    Src/syscalls.c
    startup_stm32g474xx.s
    # Add user sources here
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    Inc
    # Add user defined include paths
)
