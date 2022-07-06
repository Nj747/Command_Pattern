#include <iostream>
#include "Invoker.hpp"
#include "StereoCommands.hpp"
#include "LightCommands.hpp"
#define ENABLE_PROFILING 0

#if ENABLE_PROFILING != 0 

#pragma region Dirty Profiling
////////////////////////////////////////////////////////////////////////
// Only use this for dirty profiling
////////////////////////////////////////////////////////////////////////
struct AllocationMetrics {
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new (size_t size) {
    std::cout << "Allocating " << size << " bytes\n";
    s_AllocationMetrics.TotalAllocated += size;

    return malloc(size);
}

void operator delete(void* memory, size_t size) {
    std::cout << "Freeing " << size << " bytes\n";
    s_AllocationMetrics.TotalFreed += size;

    free(memory);
}

void PrintMemoryUsage()
{
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}
////////////////////////////////////////////////////////////////////////
#pragma endregion
#endif

int main() {
    // Create some test for our API
    RemoteControl* remoteControl = new RemoteControl();

    // Instantiate the receivers
    Receivers::Light* livingRoomLight = new Receivers::Light();
    Receivers::Stereo* stereo = new Receivers::Stereo();

    Commands::LightOnCommand* livingRoomLightOn = new Commands::LightOnCommand(livingRoomLight);
    Commands::LightOffCommand* livingRoomLightOff = new Commands::LightOffCommand(livingRoomLight);

    Commands::StereoOnWithCDCommand* stereoOnWithCD = new Commands::StereoOnWithCDCommand(stereo);
    Commands::StereoOffCommand* stereoOff = new Commands::StereoOffCommand(stereo);

    // setting the commands to execute
    remoteControl->setCommand(livingRoomLightOn, livingRoomLightOff);
    remoteControl->setCommand(stereoOnWithCD, stereoOff);

    // Push the buttons
    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    remoteControl->onUndoButtonWasPushed();

    remoteControl->onButtonWasPushed(1);
    remoteControl->offButtonWasPushed(1);
    remoteControl->onUndoButtonWasPushed();

    delete remoteControl;

    return 0;
}