// vl53l1_platform.h
#include <stdio.h>
#include "driver/i2c.h"

#ifndef VL53L1_PLATFORM_H
#define VL53L1_PLATFORM_H


#define VL53L1_I2C_SLAVE__DEVICE_ADDRESS 
#define VL53L1_MAX_STRING_LENGTH // idk what it means bruh

typedef struct {
    uint8_t I2cHandle;
    uint8_t I2cDevAddr;
    // Add other members as needed for your application
} VL53L1_Dev_t;

// Define a typedef for a pointer to VL53L1_Dev_t
typedef VL53L1_Dev_t* VL53L1_DEV;

typedef enum {
    VL53L1_ERROR_NONE,
    VL53L1_ERROR_INVALID_PARAMS,
    VL53L1_ERROR_CONTROL_INTERFACE,
} VL53L1_Error;

VL53L1_Error VL53L1_RdByte(VL53L1_DEV Dev, uint16_t index, uint8_t *data);
VL53L1_Error VL53L1_RdWord(VL53L1_DEV Dev, uint16_t index, uint16_t *data);
VL53L1_Error VL53L1_WrByte(VL53L1_DEV Dev, uint16_t index, uint8_t data);
VL53L1_Error VL53L1_WrDWord(VL53L1_DEV Dev, uint16_t index, uint32_t data);
VL53L1_Error VL53L1_WrWord(VL53L1_DEV Dev, uint16_t index, uint16_t data);
VL53L1_Error VL53L1_RdDWord(VL53L1_DEV Dev, uint16_t index, uint32_t *data);

#endif