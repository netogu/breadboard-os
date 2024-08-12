#include "core.h"
#include <string.h>
#include <stdio.h>

#define BUILD_AS_APP
#ifdef BUILD_AS_APP
int main(void){
    board_init();

    int counter = 0;
    uint8_t str[30] = {0};
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        sprintf((char *) str, "Counter = %d \r\n", counter++);
        HAL_UART_Transmit(&hlpuart1, str, sizeof(str), 10000);
        HAL_Delay(100);

    }
}
#endif

