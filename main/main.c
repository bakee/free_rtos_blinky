#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define HIGH (1)
#define LOW (0)

#define LED_PIN_1 GPIO_NUM_4
#define LED_PIN_2 GPIO_NUM_5
#define LED_PIN_3 GPIO_NUM_27

void setupLed1()
{
    gpio_set_direction(LED_PIN_1, GPIO_MODE_DEF_OUTPUT);
    gpio_set_direction(LED_PIN_2, GPIO_MODE_DEF_OUTPUT);
}

void turnOnLed1()
{
    gpio_set_level(LED_PIN_1, HIGH);
}

void turnOffLed1()
{
    gpio_set_level(LED_PIN_1, LOW);
}

void led1BlinkTask()
{
    setupLed1();
    while (1)
    {
        turnOnLed1();
        vTaskDelay(pdMS_TO_TICKS(500));
        turnOffLed1();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void setupLed2()
{
    gpio_set_direction(LED_PIN_2, GPIO_MODE_DEF_OUTPUT);
}

void turnOnLed2()
{
    gpio_set_level(LED_PIN_2, HIGH);
}

void turnOffLed2()
{
    gpio_set_level(LED_PIN_2, LOW);
}

void led2BlinkTask()
{
    setupLed2();
    while (1)
    {
        turnOnLed2();
        vTaskDelay(pdMS_TO_TICKS(400));
        turnOffLed2();
        vTaskDelay(pdMS_TO_TICKS(400));
    }
}

void setupLed3()
{
    gpio_set_direction(LED_PIN_3, GPIO_MODE_DEF_OUTPUT);
}

void turnOnLed3()
{
    gpio_set_level(LED_PIN_3, HIGH);
}

void turnOffLed3()
{
    gpio_set_level(LED_PIN_3, LOW);
}

void led3BlinkTask()
{
    setupLed3();
    while (1)
    {
        turnOnLed3();
        vTaskDelay(pdMS_TO_TICKS(300));
        turnOffLed3();
        vTaskDelay(pdMS_TO_TICKS(300));
    }
}

void app_main()
{
    xTaskCreate(led1BlinkTask, "Blinky 1", 2000, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(led2BlinkTask, "Blinky 2", 2000, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(led3BlinkTask, "Blinky 3", 2000, NULL, tskIDLE_PRIORITY + 1, NULL);
}