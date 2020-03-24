#include <chrono>
#include <iostream>
#include <thread>

int main() {
  while(true) {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); 
    std::cout << ctime(&now);
    std::this_thread::sleep_for(std::chrono::seconds(15));
  }
  return 0;
}