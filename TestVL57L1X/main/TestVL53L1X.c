#include <stdio.h>

#include "esp_log.h"
#include "driver/i2c.h" // type:ignore
#include "i2c_master.h"


#include "vl53l1x/vl53l1_platform.h"
#include "vl53l1x/VL53L1X_api.h"

static const char *TAG = "TestVL53L1X";

#define I2C_MASTER_SCL_IO           32
#define I2C_MASTER_SDA_IO           33
#define I2C_MASTER_NUM              0 

void app_main(void)
{
    ESP_LOGI(TAG, "I2C MASTER INIT");
    ESP_ERROR_CHECK(i2c_master_init(I2C_MASTER_NUM, I2C_MASTER_SDA_IO, I2C_MASTER_SCL_IO));

    VL53L1_Dev_t dev = {
        .I2cHandle = I2C_MASTER_NUM,
        .I2cDevAddr = 0x29 // Set your default value here
    };

    // Create a pointer to the VL53L1_Dev_t instance
    VL53L1_DEV Dev = &dev;

    uint8_t byteData;
    uint16_t wordData;

    VL53L1_RdByte(Dev, 0x010F, &byteData);
    printf("VL53L1X Model_ID: %02X\n\r", byteData);
    VL53L1_RdByte(Dev, 0x0110, &byteData);
    printf("VL53L1X Module_Type: %02X\n\r", byteData);
    VL53L1_RdWord(Dev, 0x010F, &wordData);
    printf("VL53L1X: %02X\n\r", wordData);
    int status = VL53L1X_SensorInit(dev);
    printf("INIT status: %i\n\r", status);
}
