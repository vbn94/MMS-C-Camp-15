#include <Arduino_FreeRTOS.h>

struct LedInfo {
  unsigned pin;
  unsigned delay_time;
};

LedInfo led1 = { .pin = 52, .delay_time=500 };
LedInfo led2 = { .pin = 53, .delay_time=200 };

void TaskBlink(void *);

void setup() {
  Serial.begin(9600);
  xTaskCreate(TaskBlink,"task1",128, &led1, 1, NULL);
  xTaskCreate(TaskBlink,"task2",128, &led2, 1, NULL);
  vTaskStartScheduler();
}

void loop(){
}

void TaskBlink(void *pvParameters)  {
  LedInfo li = *(LedInfo*)pvParameters;
  pinMode(li.pin, OUTPUT);
  while(1){
    digitalWrite(li.pin, HIGH);   
    vTaskDelay(li.delay_time / portTICK_PERIOD_MS ); 
    digitalWrite(li.pin, LOW);    
    vTaskDelay(li.delay_time / portTICK_PERIOD_MS ); 
  }
}


