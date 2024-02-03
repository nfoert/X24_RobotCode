#ifndef CLAWSUBSYSTEM_H
#define CLAWSUBSYSTEM_H

#include <Constants.h>

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>

class ClawSubsystem : public frc2::SubsystemBase {
    public: 
        ClawSubsystem(
            int left_motor_can_id,
            int right_motor_can_id,
            int left_sensor_di_ch,
            int right_sensor_di_ch
        );
        void Periodic() override;
        void SetClawPower(double power);
        bool GetLeftSensor();
        bool GetRightSensor();

    private: 
        WPI_TalonSRX _left_climb_motor;
        WPI_TalonSRX _right_climb_motor;

        frc::DigitalInput _left_motor_sensor;
        frc::DigitalInput _right_motor_sensor;
    
};
#endif