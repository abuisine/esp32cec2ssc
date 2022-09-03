/* enable Ethernet power supply with correct clock */
#define ETH_CLK_MODE ETH_CLOCK_GPIO17_OUT
#define ETH_PHY_POWER 12

#include <Arduino.h>
#include <ETH.h>
#include <CEClient.h>

#include "version.h"

#define CEC_PHYSICAL_ADDRESS    0x1000
#define CEC_INPUT_PIN           2
#define CEC_OUTPUT_PIN          3

CEClient ceclient(CEC_PHYSICAL_ADDRESS, CEC_INPUT_PIN, CEC_OUTPUT_PIN);


void setup() {
  Serial.begin(115200);
  Serial.println((String)"Esp32osc v" + VERSION + " starting ...");

  // initialize the client with the default device type (PLAYBACK)
  ceclient.begin();

  // enable promiscuous mode (print all the incoming messages)
  ceclient.setPromiscuous(true);

  // enable monitor mode (do not transmit)
  ceclient.setMonitorMode(true);
}

void loop() {

    // run the client
    ceclient.run();
}