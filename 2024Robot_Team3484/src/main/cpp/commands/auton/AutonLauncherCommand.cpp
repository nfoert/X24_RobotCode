// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/auton/AutonLauncherCommand.h"


using namespace LauncherConstants;
using namespace IntakeConstants;
using namespace VisionConstants;

AutonLauncherCommand::AutonLauncherCommand(LauncherSubsystem* launcher_subsystem, IntakeSubsystem* intake_subsystem, Vision* vision)
: _launcher{launcher_subsystem},_intake{intake_subsystem}, _limelight{vision}{ 
    AddRequirements(_launcher), AddRequirements(_intake);
}


void AutonLauncherCommand::Initialize(){

    if(_intake !=NULL){
        _intake->SetIntakeAngle(STOW_POSITION);
        _intake->SetRollerPower(ROLLER_STOP);
        
    }

    _launching = false;
    if (_launcher !=NULL){
    _launcher->setLauncherRPM(TARGET_RPM);
    }


}
void AutonLauncherCommand::Execute(){
    if (_launcher !=NULL && _intake != NULL){
        if(_launcher->atTargetRPM() && _intake->AtSetPosition() && ( _limelight == NULL || (_limelight->HasTarget() && units::math::abs(_limelight->GetHorizontalDistance()) < AIM_TOLERANCE_SMALL) )){
            _launching = true;
        }
        if(_launching){
            _intake->SetRollerPower(-ROLLER_POWER);
        }
    }

}
void  AutonLauncherCommand::End(bool interrupted){
    if (_launcher !=NULL && _intake != NULL){
        _launcher->setLauncherRPM(0_rpm);
        _intake->SetRollerPower(ROLLER_STOP);
    }
}
bool  AutonLauncherCommand::IsFinished(){
 return false;
}