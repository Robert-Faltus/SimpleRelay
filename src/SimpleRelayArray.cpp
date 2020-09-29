/**
 *  @file       SimpleRelayArray.cpp
 *  Project     SimpleRelay
 *  @brief      Relay library for Arduino
 *  @author     JSC electronics
 *  License     Apache-2.0 - Copyright (c) 2019 JSC electronics
 *
 *  @section License
 *
 *  Copyright (c) 2020 JSC electronics
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SimpleRelayArray.h"

SimpleRelayArray::SimpleRelayArray(uint8_t *pinArray, bool isInverted = false){
    this->pinArray = pinArray;
    arraySize = sizeof(pinArray)/sizeof(*pinArray);
    if(isInverted){
        relayActive = !relayActive;
        relayIdle = !relayIdle;
    }
}

void SimpleRelayArray::begin(bool basicState){
    for(uint8_t i = 0; i < arraySize; i++){
        pinMode(pinArray[i], OUTPUT);
        delay(1);
        on(pinArray[i]);
    }
}

void SimpleRelayArray::on(uint8_t pin){
    if(isPinInRelayArray(pin)){
        digitalWrite(pin, relayActive);
    }
}

void SimpleRelayArray::off(uint8_t pin){
    if(isPinInRelayArray(pin)){
        digitalWrite(pin, relayIdle);
    }
}

void SimpleRelayArray::arrayOn(){
    for(uint8_t i = 0; i < arraySize; i++){
        on(pinArray[i]);
    }
}

void SimpleRelayArray::arrayOff(){
    for(uint8_t i = 0; i < arraySize; i++){
        off(pinArray[i]);
    }
}

void SimpleRelayArray::toggle(uint8_t pin){
    if(isPinInRelayArray(pin)){
        (isRelayOn(pin)) ? off(pin) : on(pin);
    }
}

bool SimpleRelayArray::isRelayOn(uint8_t pin){
    if(isPinInRelayArray(pin)){
        return digitalRead(pin) == relayActive;
    }
    return false;
}

bool SimpleRelayArray::isPinInRelayArray(uint8_t pin){
    for(uint8_t i = 0; i < arraySize; i++){
        if(pinArray[i] == pin){
            return true;
        }
    }
    return false;
}