cmake_minimum_required(VERSION 3.10)
project(CPlusPlusBestPractices)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directory for all executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binaries)

# Helper function to add executables for each folder
function(add_example folder_name)
    file(GLOB_RECURSE SOURCES "${folder_name}/*.cpp")
    foreach(source_file ${SOURCES})
        get_filename_component(example_name ${source_file} NAME_WE)
        string(REPLACE "/" "_" folder_prefix ${folder_name}) # Ensure folder name is valid
        set(unique_name "${folder_prefix}_${example_name}")
        add_executable(${unique_name} ${source_file})
    endforeach()
endfunction()

# Add executables for each folder
add_example("01_Basic")
add_example("02_Pointers")
add_example("03_Vectors")
add_example("04_Enums")
add_example("05_Functions")
add_example("06_STL")
add_example("07_Resources")
add_example("08_Lambdas")
add_example("09_Templates")
add_example("10_Object_Oriented")
add_example("11_EventsAndDelegates")
add_example("12_CPlusPlusUniqueness")