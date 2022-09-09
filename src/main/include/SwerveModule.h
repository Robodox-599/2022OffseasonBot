
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <frc/MathUtil.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/sensors/WPI_CANCoder.h>

#include "Constants.h"
#include "HardwareConfig.h"
#include <units/angle.h>

class SwerveModule {
    public:
        SwerveModule(const double Module[]);
        void SetDesiredState(frc::SwerveModuleState& DesiredState, bool IsOpenLoop);
        frc::Rotation2d GetCANCoder();
        frc::SwerveModuleState Optimize(frc::SwerveModuleState DesiredState, frc::Rotation2d CurrentAngle);
        frc::SwerveModuleState GetState();
     
        units::degree_t FalconToDegrees(double Counts, double GearRatio);
        double DegreesToFalcon(units::degree_t Degrees, double GearRatio);
        double FalconToRPM(double VelocityCounts, double GearRatio);
        double RPMToFalcon(double RPM, double GearRatio);
        units::meters_per_second_t FalconToMPS(double Velocitycounts, units::meter_t Circumference, double GearRatio);
        double MPSToFalcon(units::meters_per_second_t Velocity, units::meter_t Circumference, double GearRatio);

    private:
        void resetToAbsolute();
        units::degree_t PlaceInAppropriate0To360Scope(units::degree_t ScopeReference, units::degree_t NewAngle);
        
        units::degree_t m_LastAngle;
        ctre::phoenix::motorcontrol::can::WPI_TalonFX m_DriveMotor;
        ctre::phoenix::motorcontrol::can::WPI_TalonFX m_AngleMotor;
        ctre::phoenix::sensors::WPI_CANCoder m_AngleEncoder;
        units::degree_t m_AngleOffset;

        frc::SimpleMotorFeedforward<units::feet> m_Feedforward;
        HardwareConfig m_Settings;




};