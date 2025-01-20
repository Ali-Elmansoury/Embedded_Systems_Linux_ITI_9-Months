#include "GPIO.h"

#define BCM2837_GPIO_REGISTERS ((volatile BCM2837_strGPIO_REGISTERS_t *)GPIO_BASE)

void delay_us(uint32_t us) {
    uint32_t start = SYSTIMERCLO; // Get the current timer value
    while ((SYSTIMERCLO - start) < us) {
        // Wait until the desired number of microseconds has passed
    }
}

void delay_ms(uint32_t ms) {
    delay_us(ms * 1000); // Convert milliseconds to microseconds
}

int main(void)
{
    CLEAR_PIN_DIR(BCM2837_GPIO_REGISTERS->GPFSEL0,GPIO_PIN_4);
    SET_PIN_DIR_OUTPUT(BCM2837_GPIO_REGISTERS->GPFSEL0,GPIO_PIN_4);

    CLEAR_PIN_DIR(BCM2837_GPIO_REGISTERS->GPFSEL1,GPIO_PIN_17);
    SET_PIN_DIR_OUTPUT(BCM2837_GPIO_REGISTERS->GPFSEL1,GPIO_PIN_17);

    CLEAR_PIN_DIR(BCM2837_GPIO_REGISTERS->GPFSEL2,GPIO_PIN_27);
    SET_PIN_DIR_OUTPUT(BCM2837_GPIO_REGISTERS->GPFSEL2,GPIO_PIN_27);
    while(1)
    {
        SET_PIN(BCM2837_GPIO_REGISTERS->GPSET0,GPIO_PIN_4);
        SET_PIN(BCM2837_GPIO_REGISTERS->GPSET0,GPIO_PIN_17);
        SET_PIN(BCM2837_GPIO_REGISTERS->GPSET0,GPIO_PIN_27);

        delay_ms(1000);

        CLEAR_PIN(BCM2837_GPIO_REGISTERS->GPCLR0, GPIO_PIN_4);
        CLEAR_PIN(BCM2837_GPIO_REGISTERS->GPCLR0, GPIO_PIN_17);
        CLEAR_PIN(BCM2837_GPIO_REGISTERS->GPCLR0, GPIO_PIN_27);
        delay_ms(1000);
    }   
    return 0;
}