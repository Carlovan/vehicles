add_library(VehiclesLib world.cpp)
target_include_directories(VehiclesLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(VehiclesLib PUBLIC sfml::sfml)
