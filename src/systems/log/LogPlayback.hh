/*
 * Copyright (C) 2019 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_GAZEBO_SYSTEMS_LOGPLAYBACK_HH_
#define IGNITION_GAZEBO_SYSTEMS_LOGPLAYBACK_HH_

#include <ignition/gazebo/config.hh>
#include <ignition/gazebo/Export.hh>
#include <ignition/gazebo/System.hh>

// Use ign-transport directly
//#include <ignition/transport/log/Playback.hh>
#include <ignition/transport/log/Log.hh>

namespace ignition
{
namespace gazebo
{
namespace systems
{
  // Inline bracket to help doxygen filtering.
  inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
  /// \class LogPlayback LogPlayback.hh ignition/gazebo/systems/log/LogPlayback.hh
  /// \brief Log state playback
  class IGNITION_GAZEBO_VISIBLE LogPlayback:
    public System,
    public ISystemConfigure,
    public ISystemUpdate
  {
    /// \brief Constructor
    public: explicit LogPlayback();

    /// \brief Destructor
    public: ~LogPlayback() override;

    /// Documentation inherited
    public: void Configure(const Entity &_id,
                           const std::shared_ptr<const sdf::Element> &_sdf,
                           EntityComponentManager &_ecm,
                           EventManager &_eventMgr) final;

    /// Documentation inherited
    public: void Update(const UpdateInfo &_info,
                        EntityComponentManager &_ecm) final;

    /// \brief Name of log file to play back
    public: std::string logPath = "file.tlog";

    //private: std::unique_ptr <ignition::transport::log::Playback> player;
    private: std::unique_ptr <ignition::transport::log::Log> log;
  };
  }
}
}
}
#endif
