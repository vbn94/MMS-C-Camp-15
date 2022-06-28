// led blink and print

#include <Arduino_FreeRTOS.h>
#define LED1 52
#define LED2 53

void TaskBlink1(void*);
void TaskBlink2(void*);
void TaskPrint(void*);

void setup() {
  Serial.begin(9600);
  xTaskCreate(TaskBlink1,"task1",128, NULL,1, NULL);
  xTaskCreate(TaskBlink2,"task2",128, NULL,1, NULL);
  xTaskCreate(TaskPrint,"taskprint",128, NULL,1, NULL);
  vTaskStartScheduler();
}

void loop(){
}

void TaskBlink1(void *pvParameters)  {
  pinMode(LED1, OUTPUT);
  while(1){
    digitalWrite(LED1, HIGH);   
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
    digitalWrite(LED1, LOW);    
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
  }
}

void TaskBlink2(void *pvParameters)  {
  pinMode(LED2, OUTPUT);
  while(1){
    digitalWrite(LED2, HIGH);   
    vTaskDelay(2000 / portTICK_PERIOD_MS ); 
    digitalWrite(LED2, LOW);   
    vTaskDelay(2000 / portTICK_PERIOD_MS ); 
  }
}

void TaskPrint(void *pvParameters)  {
  long counter = 0;
  while(1) {
   counter++;
   Serial.println(counter); 
   vTaskDelay(500 / portTICK_PERIOD_MS); 
  }
}

