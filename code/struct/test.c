#include <stdio.h>

struct SensorData {
	float temperature;
	float humidity;
	int sensorID;
};

int main() {
	struct SensorData mySensor = {.temperature = 4.25, .humidity = 2.34, .sensorID = 12};
  printf("%.2f, %.2f, %d", mySensor.temperature, mySensor.humidity, mySensor.sensorID);
}
