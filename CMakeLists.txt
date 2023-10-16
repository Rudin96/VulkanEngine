cmake_minimum_required(VERSION 3.10)
project(VulkanEngine)

set(CMAKE_CXX_STANDARD 17)

set(STB_INCLUDE_PATH "/home/tobias/Documents/Libraries/stb/stb-master")
set(TINYOBJ_INCLUDE_PATH "/home/tobias/Documents/Libraries/tinyobjloader-release")
set(VULKAN_SDK_PATH "/home/user/VulkanSDK/1.3.261.0/x86_64")

# Find Vulkan package
find_package(Vulkan REQUIRED)

# Define your source files
file(GLOB_RECURSE SOURCES "*.cpp")

# Add your source files to the executable
add_executable(VulkanEngine ${SOURCES})

# Add any other libraries your project depends on
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
    
# Specify include directories, including Vulkan headers
target_include_directories(VulkanEngine PRIVATE
    ${VULKAN_SDK_PATH}/include
    ${STB_INCLUDE_PATH}
    ${TINYOBJ_INCLUDE_PATH}
)
    
# Optionally, set additional compilation flags
target_compile_options(VulkanEngine PRIVATE -Wall -Wextra)
    
# Optionally, specify the output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
    
# Specify the output directory for CMake-generated files (e.g., Makefiles)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
    
# Optional: Use C++17 features, e.g., for filesystem support
# target_compile_features(VulkanEngine PRIVATE cxx_std_17)
    