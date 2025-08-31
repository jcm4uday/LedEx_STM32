#define LED_PIN_12 12 // LED 4
#define LED_PIN_13 13 // LED 3
#define LED_PIN_14 14 // LED 5
#define LED_PIN_15 15 // LED 6
#define LED_PORT GPIO_D // Assuming GPIO_D is defined for the LED port

#define RCC_BASE_ADDRESS 0x40023800 // Base address for RCC
#define GPIO_D_BASE_ADDRESS 0x40020C00 // Base address for GPIO D
#define TIMx_BASE_ADDRESS 0x40000000 // Base address for Timer peripheral (replace with actual address)
#define TIM2_OFFSET 0x0000 // Offset for Timer 2 registers

#define GPIO_DENR_OFFSET 0x30 // Offset for GPIO D clock enable register

// Define the GPIO D clock enable register address
#define GPIO_D_CLOCK_ENABLE (RCC_BASE_ADDRESS + GPIO_DENR_OFFSET)
// Define the TIM2 clock enable register address
#define TIM2_CLOCK_ENABLE (RCC_BASE_ADDRESS + 0x40) 

// Define the LED port base address
#define GPIO_D ((volatile uint32_t *)GPIO_D_BASE_ADDRESS)

#define TIM2_BASE_ADDRESS (TIMx_BASE_ADDRESS + TIM2_OFFSET) // Replace TIM2_OFFSET with actual offset for TIM2

// Define the LED pin states
#define LED_ON 1
#define LED_OFF 0