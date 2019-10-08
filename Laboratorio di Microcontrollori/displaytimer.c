
int timer_value=0;
int timer_on=0;

int main()
{
    GPIO_init(GPIOB);
    DISPLAY_init():

    //push button X (pb10)
    GPIO_config_input(GPIOB,10);
    GPIO_config_EXTI(GPIOB, EXTI10);
    EXTI_enable(EXTI10, FALLING_EDGE);

    //push button Y (pb4)
    GPIO_config_input(GPIOB,4);
    GPIO_config_EXTI(GPIOB, EXTI4);
    EXTI_enable(EXTI4, FALLING_EDGE);
    for(;;)
    {
        char str[5];
        delay_ms(1000);
        if(timer_on)
            ++timer_value;
        sprintf(str,"%04d", timer_value);
        DISPLAY_puts(0,str);
    }

}

void EXTI15_10_IRQHandler(void)
{
    if(EXTI_isset(EXTI10))
    {
        timer_on = !timer_on;
        EXTI_clear(EXTI10);
    }
}

void EXTI4_IRQHandler(void)
{
    if(EXTI_isset(EXTI4))
    {
        if(!timer_on)
            timer_value=0;
        EXTI_clear(EXTI4);
    }
}