#pragma once

#include <atomic>
#include <frc/util/Color.h>
#include <memory>
#include <units/time.h>

namespace pico {

class ColorSensor {
 public:
  ColorSensor();
  ~ColorSensor();
  struct RawColor {
    uint32_t red = 0;
    uint32_t green = 0;
    uint32_t blue = 0;
    uint32_t ir = 0;
  };

  bool IsSensor0Connected();
  bool IsSensor2Connected();

  RawColor GetRawColor0();

  uint32_t GetProximity0();

  RawColor GetRawColor2();

  uint32_t GetProximity2();

  units::second_t GetLastReadTimestamp();

  void SetDebugPrints(bool debug);

 private:
  struct Impl;
  std::unique_ptr<Impl> pImpl;
};

}  // namespace pico