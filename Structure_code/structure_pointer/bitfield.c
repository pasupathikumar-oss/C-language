//A bit field in C allows structure members to use a specific number of bits instead of 
//the full size of their data type, helping to save memory.

#include <stdio.h>

struct DeviceStatus {
    unsigned int power : 1;
    unsigned int wifi : 1;   // width should not exceed the size of the data type (unsigned int in this case)
    unsigned int bluetooth : 1;
}; // Each member uses only 1 bit. Save memory compared to storing each member as a full integer.
   // Useful for storing flags and Boolean values

int main(){
    struct DeviceStatus device;

    device.power = 1;
    device.wifi = 0;
    device.bluetooth = 1;

    printf("Power: %u\n", device.power);
    printf("WiFi: %u\n", device.wifi);
    printf("Bluetooth: %u\n", device.bluetooth);

    return 0;
}