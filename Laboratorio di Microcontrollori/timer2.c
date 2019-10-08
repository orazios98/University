

enum {
    ST_OFF,
    ST_ON,
    ST_SETUP
};

int state=ST_OFF;
int timeout_value=10; //resolution 0.5s
int current_time=0;
int time_resolution=2;

int main()
{
    GPIO_init(GPIOB);
    GPIO_init(GPIOC);
    DISPLAY_init():


    GPIO_config_output(GPIOC,2);
    GPIO_config_output(GPIOC,3);

    //push button X (pb10)
    GPIO_config_input(GPIOB,10);
    GPIO_config_EXTI(GPIOB, EXTI10);
    EXTI_enable(EXTI10, FALLING_EDGE);

    //push button Y (pb4)
    GPIO_config_input(GPIOB,4);
    GPIO_config_EXTI(GPIOB, EXTI4);
    EXTI_enable(EXTI4, FALLING_EDGE);

    //led red
    GPIO_config_output(GPIOB,0);

    //push button z (pb5)
    GPIO_config_input(GPIOB,5);
    GPIO_config_EXTI(GPIOB, EXTI5);
    EXTI_enable(EXTI5, FALLING_EDGE);

    //push button t (pb6)
    GPIO_config_input(GPIOB,6);
    GPIO_config_EXTI(GPIOB, EXTI6);
    EXTI_enable(EXTI6, FALLING_EDGE);


    for(;;)
    {
        char str[5];
        switch (state)
        {
            case ST_ON:
                GPIO_write(GPIOB,0,1);
                GPIO_toggle(GPIOC,3);
                sprintf(str, "%04d", current_time/time_resolution);
                DISPLAY_puts(0,str);
                if(current_time==0)
                    state=ST_OFF;
                else
                {
                    delay_ms(500);
                    --current_time;
                }
                break;
            case ST_OFF:
                GPIO_write(GPIOC,2,0);
                GPIO_write(GPIOB,0,0);
                DISPLAY_puts(0, "----");
                break;
            case ST_SETUP:
                GPIO_write(GPIOC,2,1);
                sprintf(str, "%04d", timeout_value/time_resolution);
                DISPLAY_puts(0,str);
                break;
        }
    }

}


//PUSH BUTTON X
void EXTI15_10_IRQHandler(void)
{
    if(EXTI_isset(EXTI10))
    {
        switch (state)
        {
        case ST_OFF:
            current_time =timeout_value;
            state=ST_ON;
            break;
        case ST_ON:
            current_time=timeout_value;
            break;
        }
 
        EXTI_clear(EXTI10);
    }
}


//push button Y
void EXTI4_IRQHandler(void)
{
    if(EXTI_isset(EXTI4))
    {
        switch(state)
        {
            case ST_OFF:
                state=ST_SETUP;
                break;
            case ST_SETUP:
                ST_ON;
                break;
        }
        EXTI_clear(EXTI4);
    }
}

//push button T e Z
void EXTI9_5_IRQHandler(void)
{
    //pushbutton Z
    if(EXTI_isset(EXTI5))
    {
        if(state==ST_SETUP)
        {
            if(timeout_value>6)
                timeout_value -= time_resolution;
        }
        EXTI_clear(EXTI5);
    }


    //pushbutton T
    if(EXTI_isset(EXTI6))
    {
        if(state==ST_SETUP)
        {
            if(timeout_value<40)
                timeout_value+=time_resolution;
        }
        EXTI_clear(EXTI6);
    }
}