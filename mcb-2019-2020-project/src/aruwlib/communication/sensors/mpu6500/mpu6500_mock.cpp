#ifdef ENV_SIMULATOR
#include "mpu6500.hpp"

namespace aruwlib {

namespace sensors {
    bool Mpu6500::imuInitialized = false;

    // initialize the imu and SPIbx
    void Mpu6500::init() {
    }

    // parse imu data from data buffer
    void Mpu6500::read() {
    }

    // get temperature value in C
    float Mpu6500::mpuGetTemp() {
        return 0;
    }

    // get accleration reading on x-axis
    float Mpu6500::getAx() {
        return 0;
    }

    // get accleration reading on y-axis
    float Mpu6500::getAy() {
        return 0;
    }

    // get acceleration reading on z-axis
    float Mpu6500::getAz() {
        return 0;
    }

    // get gyro reading on x-axis
    float Mpu6500::getGx() {
        return 0;
    }

    // get gyro reading on y-axis
    float Mpu6500::getGy() {
        return 0;
    }

    // get gyro reading on z-axis (degrees per second)
    float Mpu6500::getGz() {
        return 0;
    }

    MahonyAhrs::attitude Mpu6500::getImuAttitude() {
        return MahonyAhrs::attitude();
    }

    float Mpu6500::getTiltAngle()
    {
        return 0;
    }
}  // namespace sensors

}  // namespace aruwlib
#endif