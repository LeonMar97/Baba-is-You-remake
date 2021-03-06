cmake_minimum_required (VERSION 3.15)

project (Baba-Is-You-Remake)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

add_executable (Baba-Is-You-Remake WIN32 "")

add_subdirectory (include)
add_subdirectory (include/AnimationAndTexturesHead)
add_subdirectory(include/BaseClassesHead)
add_subdirectory(include/OperationsHead)
add_subdirectory(include/PropertyHead)
add_subdirectory(include/DataStructuresHead)
add_subdirectory(include/HandlersHead)
add_subdirectory(include/RepresntationsHead)
add_subdirectory(include/WordsHead)
add_subdirectory(include/MenusAndCommandsHead)
add_subdirectory(include/MenusAndCommandsHead/CommandsHead)
add_subdirectory(include/MenusAndCommandsHead/MenusHead)


add_subdirectory (src)
add_subdirectory (src/AnimationAndTexturesCpp)
add_subdirectory (src/OperationsCpp)
add_subdirectory(src/PropertyCpp)
add_subdirectory(src/BaseClassesCpp)
add_subdirectory(src/DataStructuresCpp)
add_subdirectory(src/HandlersCpp)
add_subdirectory(src/RepresntationsCpp)
add_subdirectory(src/WordsCpp)
add_subdirectory (resources)
add_subdirectory(src/MenusAndCommandsCpp)
add_subdirectory(src/MenusAndCommandsCpp/CommandsCpp)
add_subdirectory(src/MenusAndCommandsCpp/MenusCpp)
configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)
set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")

find_package (SFML 2.5 COMPONENTS audio graphics REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (Baba-Is-You-Remake sfml-graphics sfml-main sfml-audio)

