// arguments to tasks

#include <Arduino_FreeRTOS.h>

void TaskBlink(void *);
unsigned ledPin1 = 52;
unsigned ledPin2 = 53;

void setup() {
  Serial.begin(9600);
  xTaskCreate(TaskBlink,"task1",128, &ledPin1, 1, NULL);
  xTaskCreate(TaskBlink,"task2",128, &ledPin2, 1, NULL);
  vTaskStartScheduler();
}

void loop(){
}

void TaskBlink(void *pvParameters)  {
  unsigned pin = *(unsigned*)pvParameters;
  pinMode(pin, OUTPUT);
  while(1){
    digitalWrite(pin, HIGH);   
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
    digitalWrite(pin, LOW);    
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
  }
}


