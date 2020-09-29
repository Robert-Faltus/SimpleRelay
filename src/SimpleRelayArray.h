/**
 *  @file       SimpleRelayArray.h
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

#pragma once

#include <Arduino.h>

class SimpleRelayArray {
private:
    uint8_t arraySize = 0;
    uint8_t *pinArray = nullptr;

    bool relayActive = HIGH;
    bool relayIdle = LOW;

public:
    SimpleRelayArray(uint8_t *pinArray, bool isInverted = false);
    void begin(bool basicState);
    void on(uint8_t pin);
    void off(uint8_t pin);
    void arrayOn();
    void arrayOff();
    void toggle(uint8_t pin);
    bool isRelayOn(uint8_t pin);

private:
    bool isPinInRelayArray(uint8_t pin);
};