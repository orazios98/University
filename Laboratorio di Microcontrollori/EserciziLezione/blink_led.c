
#include stm32_unict_lib.h

int main()
{
    //inizializza porta B
    GPIO_init(GPIOB);
    //configura pin PB0 come output
    GPIO_config_output(GPIOB,0);
    for(;;)
    {
        GPIO_write(GPIOB,0,1);
        delay_ms(250);
        GPIO_write(GPIOB,1,0);
        delay_ms(250);
    }
}