#include "src/HeptaSat.h"

HeptaCdh cdh;

void setup() {
  cdh.begin();
  cdh.wait_for_serial();

  cdh.wait_for_sd();
  cdh.println("Saving letters to the SD card...");

  File file = cdh.create_file("test.txt");
  if (file) {
    for(uint8_t i = 0; i < 10; i++) {
      cdh.write_file(file, "Hello, HEPTA-Sat\n");
    }
    file.close();
  } else {
    cdh.println("Failed to create file on SD card.");
    return;
  }

  cdh.println("Done saving letters to the SD card.");
  cdh.println("Reading letters from the SD card...");

  file = cdh.open_file("test.txt");
  while (file && file.available()) {
    cdh.write(cdh.read_file(file));
  }
  file.close();

  cdh.println("Done reading letters from the SD card.");
}

void loop() {

}
