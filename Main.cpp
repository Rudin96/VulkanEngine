#include "Engine/Engine.h"
#include "Utils/Logger.h"

int main() {
    Engine engine;

    try {
        engine.run();
    }
    catch (const std::exception& e) {
        Logger::LogError(e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}