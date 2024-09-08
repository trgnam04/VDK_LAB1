/*
 * exercise9_lab1.c
 *
 *  Created on: Sep 8, 2024
 *      Author: ASUS
 */

#include "exercise10_lab1.h"

volatile uint8_t min = 0;
volatile uint8_t sec = 0;
volatile uint8_t hour = 0;

uint8_t posMin = 0;
uint8_t posSec = 0;
uint8_t posHour = 0;

uint8_t pre_posMin = 0;
uint8_t pre_posSec = 0;
uint8_t pre_posHour = 0;



void init_clock(uint8_t minVal, uint8_t hourVal){
	if(minVal < 0 || minVal > 60 || hourVal < 0 || hourVal > 12) return;
	min = minVal;
	hour = hourVal;
	posMin = min / 5;
	posHour = hour;
	setNumberOnClock(posMin);
	setNumberOnClock(posHour);
}

void init_exercise10(void){
	for(int i = 0; i < 2; i++){
		HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
		HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
		HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
		HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
		HAL_GPIO_TogglePin(LED6_GPIO_Port, LED6_Pin);
		HAL_GPIO_TogglePin(LED7_GPIO_Port, LED7_Pin);
		HAL_GPIO_TogglePin(LED8_GPIO_Port, LED8_Pin);
		HAL_GPIO_TogglePin(LED9_GPIO_Port, LED9_Pin);
		HAL_GPIO_TogglePin(LED10_GPIO_Port, LED10_Pin);
		HAL_GPIO_TogglePin(LED11_GPIO_Port, LED11_Pin);
		HAL_Delay(1000);
	}

}

void clearAllClock(void){
	unsigned char status = RESET;
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, status);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, status);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, status);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, status);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, status);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, status);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, status);
	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, status);
	HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, status);
	HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, status);
	HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, status);
	HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, status);

}

void setNumberOnClock(int num){
	unsigned char status = SET;
	switch(num){
	case 0:
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, status);
		break;
	case 1:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, status);
		break;
	case 2:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, status);
		break;
	case 3:
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, status);
		break;
	case 4:
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, status);
		break;
	case 5:
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, status);
		break;
	case 6:
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, status);
		break;
	case 7:
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, status);
		break;
	case 8:
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, status);
		break;
	case 9:
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, status);
		break;
	case 10:
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, status);
		break;
	case 11:
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, status);
		break;
	}

}

extern void clearNumberOnClock(int num){
	unsigned char status = RESET;
	switch(num){
	case 0:
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, status);
		break;
	case 1:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, status);
		break;
	case 2:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, status);
		break;
	case 3:
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, status);
		break;
	case 4:
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, status);
		break;
	case 5:
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, status);
		break;
	case 6:
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, status);
		break;
	case 7:
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, status);
		break;
	case 8:
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, status);
		break;
	case 9:
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, status);
		break;
	case 10:
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, status);
		break;
	case 11:
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, status);
		break;
	}
}

void run_exercise10(void){
	pre_posHour = posHour;
	pre_posMin = posMin;
	pre_posSec = posSec;

	sec++;

	if(!(sec % 5)){
		posSec = (posSec + 1) % 12;
		clearNumberOnClock(pre_posSec);
	}

	if(sec > 59){
		sec = 0;
		min++;
		if(!(min % 5) && min)
			posMin = (posMin + 1) % 12;
		clearNumberOnClock(pre_posMin);
	}

	if(min > 59){
		min = 0;
		hour = (hour + 1) % 12;
		posHour = (posHour + 1) % 12;
		clearNumberOnClock(posHour);
	}

	setNumberOnClock(posMin);
	setNumberOnClock(posSec);
	setNumberOnClock(posHour);
}


