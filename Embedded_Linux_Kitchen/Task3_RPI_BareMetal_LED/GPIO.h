#include <stdint.h>

#define GPIO_BASE 0x3F200000

typedef enum {
    GPIO_PIN_0 = 0,
    GPIO_PIN_1 = 1,
    GPIO_PIN_2 = 2,
    GPIO_PIN_3 = 3,
    GPIO_PIN_4 = 4,
    GPIO_PIN_5 = 5,
    GPIO_PIN_6 = 6,
    GPIO_PIN_7 = 7,
    GPIO_PIN_8 = 8,
    GPIO_PIN_9 = 9,
    GPIO_PIN_10 = 10,
    GPIO_PIN_11 = 11,
    GPIO_PIN_12 = 12,
    GPIO_PIN_13 = 13,
    GPIO_PIN_14 = 14,
    GPIO_PIN_15 = 15,
    GPIO_PIN_16 = 16,
    GPIO_PIN_17 = 17,
    GPIO_PIN_18 = 18,
    GPIO_PIN_19 = 19,
    GPIO_PIN_20 = 20,
    GPIO_PIN_21 = 21,
    GPIO_PIN_22 = 22,
    GPIO_PIN_23 = 23,
    GPIO_PIN_24 = 24,
    GPIO_PIN_25 = 25,
    GPIO_PIN_26 = 26,
    GPIO_PIN_27 = 27
}BCM2837_enuGPIO_t;

typedef struct {
    volatile uint32_t GPFSEL0;
    volatile uint32_t GPFSEL1;
    volatile uint32_t GPFSEL2;
    volatile uint32_t GPFSEL3;
    volatile uint32_t GPFSEL4;
    volatile uint32_t GPFSEL5;
    volatile uint32_t RESERVED0;
    volatile uint32_t GPSET0;
    volatile uint32_t GPSET1;
    volatile uint32_t RESERVED1;
    volatile uint32_t GPCLR0;
    volatile uint32_t GPCLR1;

}BCM2837_strGPIO_REGISTERS_t;

#define OUTPUT_LOW      (~(0b111))
#define OUTPUT_HIGH     (0b001)

#define SET_PIN_DIR_OUTPUT(REG,PIN) (REG |= (OUTPUT_HIGH << ((PIN % 10) * 3)))
#define CLEAR_PIN_DIR(REG,PIN) (REG &= (OUTPUT_LOW << ((PIN % 10) * 3)))

#define SET_PIN(REG,PIN) (REG = (1 << PIN))
#define CLEAR_PIN(REG,PIN) (REG = (1 << PIN))

#define SYSTIMER_BASE 0x3F003000

#define SYSTIMERCLO (*(volatile uint32_t *)(SYSTIMER_BASE + 0x04)) // Lower 32 bits
#define SYSTIMERCHI (*(volatile uint32_t *)(SYSTIMER_BASE + 0x08)) // Upper 32 bits