#include <iostream>
#include "../inc/MacroCommand.hpp"
#include "../inc/StereoCommands.hpp"
#include "../inc/LightCommands.hpp"
#include "../inc/Invoker.hpp"

#define ENABLE_PROFILING 0 // Change the Value to 1 if you want to profile

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
    //std::cout << "Allocating " << size << " bytes\n";
    s_AllocationMetrics.TotalAllocated += size;

    return malloc(size);
}

void operator delete(void* memory, size_t size) {
    //std::cout << "Freeing " << size << " bytes\n";
    s_AllocationMetrics.TotalFreed += size;

    free(memory);
}

void PrintMemoryUsage()
{
    std::cout << "====================================================\n";
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
    std::cout << "====================================================\n";
}
////////////////////////////////////////////////////////////////////////
#pragma endregion
#endif

int main() {

#if ENABLE_PROFILING != 0 
    PrintMemoryUsage();
#endif

    {
        // Create some test for our API
        std::unique_ptr<RemoteControl> remoteControl = std::make_unique<RemoteControl>();

        // Instantiate the receivers
        std::shared_ptr<Receivers::Light> light = std::make_shared<Receivers::Light>();
        std::shared_ptr<Receivers::Stereo> stereo = std::make_shared<Receivers::Stereo>();

        // Commands
        std::shared_ptr<Commands::LightOnCommand> LightOn = std::make_shared<Commands::LightOnCommand>(light);
        std::shared_ptr<Commands::LightOffCommand> LightOff = std::make_shared<Commands::LightOffCommand>(light);

        std::shared_ptr<Commands::StereoOnCommand> stereoOn = std::make_shared<Commands::StereoOnCommand>(stereo);
        std::shared_ptr<Commands::StereoOffCommand> stereoOff = std::make_shared<Commands::StereoOffCommand>(stereo);

        std::vector<std::shared_ptr<Commands::Command>> partyOn{ LightOn, stereoOn };

        std::vector<std::shared_ptr<Commands::Command>> partyOff{ LightOff, stereoOff };

        std::shared_ptr<Commands::MacroCommand> partyOnMacro = std::make_shared<Commands::MacroCommand>(partyOn);
        std::shared_ptr<Commands::MacroCommand> partyOffMacro = std::make_shared<Commands::MacroCommand>(partyOff);

        // setting the commands to execute
        remoteControl->setCommand(partyOnMacro, partyOffMacro);

        // Push the buttons
        remoteControl->onButtonWasPushed(0);
        remoteControl->offButtonWasPushed(0);
        
#if ENABLE_PROFILING != 0 
    PrintMemoryUsage(); // Let see how much memory we have consumed
#endif
    }

#if ENABLE_PROFILING != 0 
    PrintMemoryUsage(); // At this point we should see 0 bytes
#endif

    return 0;
}