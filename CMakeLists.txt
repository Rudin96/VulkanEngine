cmake_minimum_required(VERSION 3.10)
project(VulkanEngine)

set(CMAKE_CXX_STANDARD 17)

# Define environment variables
set(STB_INCLUDE_PATH "/home/tobias/Documents/Libraries/stb/stb-master")
set(TINYOBJ_INCLUDE_PATH "/home/tobias/Documents/Libraries/tinyobjloader-release")

# Find all .cpp source files in the project folder and add them to the source list.
file(GLOB SOURCES "Main.cpp" "Engine/*.cpp" "Player/*.cpp" "Utils/*.cpp" "DataTypes/*.cpp" "Engine/Input/*.cpp" "ModelLoader.cpp" "ImageLoader.cpp")

# Add your source files to the executable.
add_executable(VulkanEngine ${SOURCES})

# Add any libraries or dependencies your project requires.
# For example, if you need to link against a library named "YourLibrary":
# target_link_libraries(VulkanEngine YourLibrary)

# Add the specified linker flags.
target_link_libraries(VulkanEngine PRIVATE
    glfw
    vulkan
    dl
    pthread
    X11
    Xxf86vm
    Xrandr
    Xi
)

# Set include directories for external libraries
target_include_directories(VulkanEngine PRIVATE
    ${STB_INCLUDE_PATH}
    ${TINYOBJ_INCLUDE_PATH}
)

# Optionally, you can set additional compilation flags.
# For example, to enable compiler warnings, you can use:
# target_compile_options(VulkanEngine PRIVATE -Wall -Wextra)

# Optionally, you can specify the output directory for the executable.
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)  # Customize this as needed.
