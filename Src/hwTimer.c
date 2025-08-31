#include <stdint.h> // Include standard integer types
#include "portConfig.h" // Include the port configuration header
#include "hwTimer.h" // Include the hardware timer header

// To program the STM32 microcontroller to toggle an LED using a hardware timer

void hwTimer_Init(uint32_t * var_TIMx_BASE_ADDRESS)
{
    // Initialize the hardware timer for toggling the LED
    // This function should configure the timer peripheral, set the prescaler, auto-reload value, and enable the timer
    // The specific implementation will depend on the STM32 family and the timer being used

    // // Example for a generic timer initialization (pseudo-code):
    // volatile uint32_t * TIMx_CR1 = (volatile uint32_t *)var_TIMx_BASE_ADDRESS; // Control Register 1 address
    // *TIMx_CR1 |= (1 << 0); // Enable the timer (set CEN bit)

    // Set prescaler and auto-reload value
    volatile uint32_t * TIMx_PSC = (volatile uint32_t *)(var_TIMx_BASE_ADDRESS + 0x28); // Prescaler address
    volatile uint32_t * TIMx_ARR = (volatile uint32_t *)(var_TIMx_BASE_ADDRESS + 0x2C); // Auto-reload address

    *TIMx_PSC = 16000 - 1; // Prescaler value for 1ms tick (assuming 16MHz clock)
    *TIMx_ARR = 1000 - 1; // Auto-reload value for 1 second period

    // // Enable the timer interrupt if needed
    // volatile uint32_t * TIMx_DIER = (volatile uint32_t *)(var_TIMx_BASE_ADDRESS + 0x0C); // DMA/Interrupt Enable Register address
    // *TIMx_DIER |= (1 << 0); // Enable update interrupt (UIE bit)

    // Start the timer
}

void hwTimer_Start(uint32_t * var_TIMx_BASE_ADDRESS)
{
    // Start the hardware timer to begin toggling the LED
    volatile uint32_t * TIMx_CR1 = (volatile uint32_t *)var_TIMx_BASE_ADDRESS; // Control Register 1 address
    *TIMx_CR1 |= (1 << 0); // Set CEN bit to start the timer
}   
void hwTimer_Stop(uint32_t * var_TIMx_BASE_ADDRESS)
{       
    // Stop the hardware timer to stop toggling the LED
    volatile uint32_t * TIMx_CR1 = (volatile uint32_t *)var_TIMx_BASE_ADDRESS; // Control Register 1 address
    *TIMx_CR1 &= ~(1 << 0); // Clear CEN bit to stop the timer
}
// void hwTimer_ToggleLED(void)
// {   
//     // This function should be called in the timer interrupt handler to toggle the LED
//     Toggle_LED(); // Call the function to toggle the LED state      
//     // This function assumes that the Toggle_LED function is defined elsewhere
//     // and is responsible for toggling the LED state on the specified GPIO pins.
// }

    // Ensure that the timer interrupt is properly configured to call this function
    // This could be done in the timer interrupt service routine (ISR) or in the main loop
    // depending on the design of the application.  

    // The Toggle_LED function should handle the actual toggling of the LED pins
    // by accessing the GPIO registers directly or through a GPIO library.
    // Ensure that the timer is properly configured before calling this function
    // This function should be called during the system initialization phase
    // and before the main loop where the LED toggling will occur.
    // The timer should be set up to generate an interrupt or a periodic event
    // that will call the Toggle_LED function at regular intervals.
    // The specific timer configuration will depend on the STM32 family and the timer being used.       
    // For example, you might need to include stm32f4xx.h or similar header files.