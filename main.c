#include "stm8l15x.h"

#define LED_GREEN_PORT  GPIOE
#define LED_GREEN_PIN   GPIO_Pin_7

#define LED_BLUE_PORT  GPIOC
#define LED_BLUE_PIN   GPIO_Pin_7

#define GPIO_HIGH(a,b)    a->ODR|=b
#define GPIO_LOW(a,b)     a->ODR&=~b
#define GPIO_TOGGLE(a,b)  a->ODR^=b


void sleep (uint16_t count);

void main(void) {
  GPIO_Init(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_Mode_Out_PP_High_Fast);
  GPIO_Init(LED_BLUE_PORT, LED_BLUE_PIN, GPIO_Mode_Out_PP_High_Fast);

  GPIO_LOW(LED_GREEN_PORT, LED_GREEN_PIN);
  GPIO_HIGH(LED_BLUE_PORT, LED_BLUE_PIN);

  while(1) {
    GPIO_TOGGLE(LED_GREEN_PORT, LED_GREEN_PIN);
    GPIO_TOGGLE(LED_BLUE_PORT, LED_BLUE_PIN);
    sleep(0xFFFF);
    GPIO_TOGGLE(LED_GREEN_PORT, LED_GREEN_PIN);
    sleep(0xFFFF);
  }
}

void sleep (uint16_t count) {
  while (count != 0) {
    count--;
  }
}
