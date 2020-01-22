#include stm32_unict_lib.h

int main()
{
    int led_state=0;
    int prev_state=1;
    //inizializza porta B
    GPIO_init(GPIOB);
    //configura pin PB0 come output
    GPIO_config_output(GPIOB,0);
    //configura pin B10 come input
    GPIO_config_input(GPIOB,10);
    //loop infinito
    for(;;)
    {
        int val = GPIO_read(GPIOB,10);
        //indentifica il fronte di discesa quindi il cambiamento di stato più che la pressione
        if(prev_state == 1 && val == 0)
            led_state = !led_state;
        GPIO_write(GPIOB,0,led_state);
        prev_state=val;
    }
    
    //Osservando l'esempio del led collegato al valore del bottone può capitare che il bottone 
    //funzioni a logica negata in base a come è stato realizzato il collegamento elettrico.
}