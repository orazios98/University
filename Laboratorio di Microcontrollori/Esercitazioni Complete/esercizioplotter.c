#include "stm32_unict_lib.h"
#include "stdio.h"

enum STATE
{
	S_SET_TARGET,
	S_RUN,
	S_RESET
};

int statoAttuale = S_SET_TARGET;
int Xdesiderata=0;
int Ydesiderata=0;
int Xeffettiva,Yeffettiva;
int secondo=0;

int main()
{
	//init
	GPIO_init(GPIOC);
	GPIO_init(GPIOB);
	DISPLAY_init();

	//config led
	GPIO_config_output(GPIOB,0);
	GPIO_config_output(GPIOC,2);
	GPIO_config_output(GPIOC,3);
	GPIO_config_output(GPIOB,8);
	GPIO_write(GPIOB,8,1);

	//tasto x
	GPIO_config_input(GPIOB,10);
	GPIO_config_EXTI(GPIOB,EXTI10);
	EXTI_enable(EXTI10,FALLING_EDGE);

	//tasto y
	GPIO_config_input(GPIOB,4);
	GPIO_config_EXTI(GPIOB,EXTI4);
	EXTI_enable(EXTI4,FALLING_EDGE);

	//tasto z
	GPIO_config_input(GPIOB,5);
	GPIO_config_EXTI(GPIOB,EXTI5);
	EXTI_enable(EXTI5,FALLING_EDGE);

	//ADC
	ADC_init(ADC1, ADC_RES_8, ADC_ALIGN_RIGHT);
	ADC_channel_config(ADC1, GPIOC, 1, 11);
	ADC_channel_config(ADC1, GPIOC, 0, 10);
	ADC_on(ADC1);

	//timer
	TIM_init(TIM2);
	TIM_config_timebase(TIM2, 42000, 400);
	TIM_enable_irq(TIM2, IRQ_UPDATE);
	TIM_on(TIM2);

	Xeffettiva = Yeffettiva = 0;
	for(;;)
	{
		switch(statoAttuale)
		{
			char StringaDisplay[5];
			case S_SET_TARGET:
				GPIO_write(GPIOC,2,1);
				GPIO_write(GPIOB,0,0);
				ADC_sample_channel(ADC1,11);
				ADC_start(ADC1);
				while(!ADC_completed(ADC1)){}
				Xdesiderata = ADC_read(ADC1)*((float)99/255);
				ADC_sample_channel(ADC1,10);
				ADC_start(ADC1);
				while(!ADC_completed(ADC1)){}
				Ydesiderata = ADC_read(ADC1)*((float)99/255);
				sprintf(StringaDisplay,"%.2d%.2d", Xdesiderata, Ydesiderata);
				DISPLAY_puts(0,StringaDisplay);
				break;
			case S_RUN:
				GPIO_write(GPIOC,2,0);
				GPIO_write(GPIOB,0,1);
				sprintf(StringaDisplay,"%.2d%.2d", Xeffettiva, Yeffettiva);
				DISPLAY_puts(0,StringaDisplay);
				break;
			case S_RESET:
				break;
			default:
				break;
		}
	}
}

//bottone x
void EXTI15_10_IRQHandler()
{
	if(EXTI_isset(EXTI10))
	{
		if(statoAttuale == S_RUN)
			statoAttuale = S_SET_TARGET;
		EXTI_clear(EXTI10);
	}
}


//bottone y
void EXTI4_IRQHandler()
{
	if(EXTI_isset(EXTI4))
	{
		if(statoAttuale == S_SET_TARGET)
			statoAttuale = S_RUN;
		EXTI_clear(EXTI4);
	}
}

//bottone z
void EXTI9_5_IRQHandler()
{
	if(EXTI_isset(EXTI5))
	{
		Xdesiderata=0;
		Ydesiderata=0;
		EXTI_clear(EXTI5);
	}
}

//timer
void TIM2_IRQHandler() {
	if(TIM_update_check(TIM2)) {
		if(statoAttuale == S_RUN)
		{
			if(Xeffettiva != Xdesiderata)
			{
				if(Xeffettiva<Xdesiderata)
					Xeffettiva++;
				else
					Xeffettiva --;
			}
			else if(Yeffettiva != Ydesiderata)
			{
				if(Yeffettiva<Ydesiderata)
					Yeffettiva++;
				else
					Yeffettiva--;
			}
		}
		TIM_update_clear(TIM2);
	}
}