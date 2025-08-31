#include <stdint.h> // Include standard integer types
#include "portConfig.h" // Include the port configuration header
#include "toggleLed.h" // Include the toggle LED header


void Toggle_LED(void)
{
    // Toggle the state of the LED pin
    // This could be done by reading the current state and writing the opposite state
    volatile uint32_t * GPIO_D_ODR = (volatile uint32_t *)(GPIO_D_BASE_ADDRESS + 0x14); // Output Data Register address
    *GPIO_D_ODR ^= (1 << LED_PIN_12); // Toggle pin 12
    *GPIO_D_ODR ^= (1 << LED_PIN_13); // Toggle pin 13
    *GPIO_D_ODR ^= (1 << LED_PIN_14); // Toggle pin 14
    *GPIO_D_ODR ^= (1 << LED_PIN_15); // Toggle pin 15
    
    // This function toggles the state of the LEDs connected to pins 12-15
    // It uses the Output Data Register (ODR) to read and write the pin states
    // Ensure that the GPIO D is properly initialized before calling this function
}