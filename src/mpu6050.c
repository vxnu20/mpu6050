#include "mpu6050.h"

void mpu6050_init()
{ 
    mpu6050_ui8_t result;
    mpu6050_ui8_t buffer[20];
    /* this step will reset the chip*/

#ifdef MPU6050_EXTERN
    mpu6050_write_byte(MPU6050_I2C_ADDR, MPU6050_PWR_MGMT_1,0x00U);
    mpu6050_read_byte(MPU6050_I2C_ADDR, MPU6050_WHO_AM_I, &result);
#endif
    if((result) == MPU6050_I2C_ADDR)
    {
        LOG("MPU6050 is online...\n");
    }
}

/* global variable for storing values */
mpu6050_ui8_t readed_values[17]= {0};
void mpu6050_read_all_raw_values()
{
    mpu6050_ui8_t high, low;
    mpu6050_ui8_t buffer[20];
    // i2c_master_read_byte(I2C1, MPU6050_I2C_ADDR, MPU6050_ACCEL_XOUT_H, &result);
    for(uint8_t i =0; i<7; i++)
    {
#ifdef MPU6050_EXTERN
        mpu6050_read_byte(MPU6050_I2C_ADDR, mpu6050_data_registers[i*2], &high);
        mpu6050_read_byte(MPU6050_I2C_ADDR, mpu6050_data_registers[(i*2)+1], &low);
#endif
        readed_values[i] = (uint16_t)((high<<8) | low);
    }
}

mpu6050_f32_t mpu6050_get_temperature_celsius()
{
    mpu6050_ui8_t temp_h = 0, temp_l = 0;
    mpu6050_ui16_t temp_raw = 0;
    mpu6050_f32_t temp_c = 0.0f;
#ifdef MPU6050_EXTERN
    mpu6050_read_byte(MPU6050_I2C_ADDR, MPU6050_TEMP_OUT_H, &temp_h);
    mpu6050_read_byte(MPU6050_I2C_ADDR, MPU6050_TEMP_OUT_L, &temp_l);
#endif
    temp_raw = (int16_t)((temp_h << 8) | temp_l);
    temp_c = (temp_raw / 340.0f) + 36.53f;

    return temp_c;
}