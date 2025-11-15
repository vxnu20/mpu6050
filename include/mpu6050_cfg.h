#ifndef MPU6050_CFG_H
#define MPU6050_CFG_H

#include <stdint.h>

#define MPU6050_EXTERN  1

/* platform types */
typedef uint8_t mpu6050_ui8_t;
typedef uint16_t mpu6050_ui16_t;
typedef uint32_t mpu6050_ui32_t;
typedef float mpu6050_f32_t;

void mpu6050_read_byte(mpu6050_ui8_t, mpu6050_ui8_t, mpu6050_ui8_t*);
void mpu6050_write_byte(mpu6050_ui8_t, mpu6050_ui8_t, mpu6050_ui8_t*);

#endif