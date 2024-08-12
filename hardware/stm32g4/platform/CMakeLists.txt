cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Include STM32 Toolchain
include("gcc-arm-none-eabi.cmake")


if(DEFINED CMAKE_PROJECT_NAME)
    message(STATUS "CMAKE_PROJECT_NAME is defined: ${CMAKE_PROJECT_NAME}")
else()
    message(STATUS "CMAKE_PROJECT_NAME is not defined, setting it manually.")
    set(CMAKE_PROJECT_NAME g474_nucleo)
endif()


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()


# Core project settings
project(${CMAKE_PROJECT_NAME} LANGUAGES C ASM)
message("Build type: " ${CMAKE_BUILD_TYPE})


add_executable(${CMAKE_PROJECT_NAME})

# Include STM32G4_HAL and Board Platform
add_subdirectory(stm32g4_hal)
add_subdirectory(g474_nucleo)

# Create an executable object type

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Convert ELF to BIN script
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.bin
    COMMENT "Converting ELF to BIN"
)

# Flashing Script using stlink
add_custom_target(flash
    COMMAND st-flash --format binary write ${CMAKE_PROJECT_NAME}.bin 0x8000000
    COMMENT "Converting ELF to BIN"
)

# Options
option(BUILD_AS_APP "Build as a standalone image for stm32" ON)


target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	USE_NUCLEO_64 
	USE_HAL_DRIVER 
	STM32G474xx
    $<$<CONFIG:Debug>:DEBUG>
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    # Add user defined libraries
)
