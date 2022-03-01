// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

#include "Robot.h"

Robot::Robot()
  :TimedRobot(0.5_s)  // decrease loop period to 2Hz for ease of debugging
{}

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  using namespace std;

  nt::NetworkTableInstance networkTableInstance = nt::NetworkTableInstance::GetDefault();
  std::shared_ptr<nt::NetworkTable> visionTab = networkTableInstance.GetTable("Shuffleboard")->GetSubTable("vision");

  int test = visionTab->GetNumber("test", 0);
  cout << "test = " << test << endl;

  visionTab->PutNumber("test-robot", test);
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
