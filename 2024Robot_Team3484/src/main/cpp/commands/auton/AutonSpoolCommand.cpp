#include "commands/auton/AutonSpoolCommand.h"
#include <Constants.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;

AutonSpoolCommand::AutonSpoolCommand(LauncherSubsystem* launcher_subsystem)
    : _launcher_subsystem{launcher_subsystem} {   
}

void AutonSpoolCommand::Initialize() {
    _launcher_subsystem->setLauncherSpeed(LauncherConstants::SPEAKER_SPEED);
}

void AutonSpoolCommand::Execute() {}

void AutonSpoolCommand::End(bool inturrupted) {}

bool AutonSpoolCommand::IsFinished() {return false;}