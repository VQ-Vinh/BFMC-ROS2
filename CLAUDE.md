# BFMC-27 ROS 2

Dự án ROS 2 cho cuộc thi Bosch Future Mobility Challenge 2027.

## Môi trường

- ROS 2 **Jazzy** trên WSL2 `Ubuntu-24.04` (repo nằm ở Windows: `D:\BFMC\ROS2` = `/mnt/d/BFMC/ROS2`)
- Node viết bằng cả C++ (`rclcpp`) và Python (`rclpy`)
- Có dùng simulator Gazebo của BFMC

## Quy tắc bắt buộc

- **Firmware STM32:** cấu hình nào làm được trong CubeMX thì yêu cầu người dùng cấu hình và chờ xác nhận đã Generate Code rồi mới viết code. Chi tiết: skill `stm32-firmware`.
- **Git:** chia nhiều commit rõ ràng; PR description ngắn; không ghi Claude là contributor (`Co-Authored-By`), không có dòng "Generated with Claude Code". Chi tiết: skill `git-workflow`.

## Firmware STM32 (`STM32F407/`)

Project CubeMX + CMake cho STM32F407G-DISC1. `arm-none-eabi-gcc` không có sẵn trong PATH, cần thêm trước khi build (Git Bash):

```bash
export PATH="/c/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/14.2 rel1/bin:$PATH"
cd STM32F407
cmake --preset Debug && cmake --build --preset Debug
openocd -f board/stm32f4discovery.cfg -c "program build/Debug/STM32F407.elf verify reset exit"
```
