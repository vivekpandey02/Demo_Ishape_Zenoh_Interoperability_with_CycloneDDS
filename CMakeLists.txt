project(demo_ishape LANGUAGES C CXX)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5 REQUIRED Core Widgets Gui)
#find_package(zenohpico REQUIRED PATHS "/usr/local/")
find_package(zenohc REQUIRED PATHS "/usr/local/")
find_package(zenohcxx REQUIRED PATHS "/usr/local/")

####################################################################
if(NOT TARGET CycloneDDS-CXX::ddscxx)
  find_package(CycloneDDS-CXX REQUIRED)
endif()


set(HEADERS *.h *.hpp)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )
####################################################################

idlcxx_generate(TARGET IdlGenerated_lib FILES ishape.idl WARNINGS no-implicit-extensibility)

include_directories(${CMAKE_BINARY_DIR})


	add_executable(zenoh_demo_ishapes ${all_SRCS} ishape.qrc)

	target_link_libraries(zenoh_demo_ishapes CycloneDDS-CXX::ddscxx IdlGenerated_lib Qt5::Widgets Qt5::Core Qt5::Gui zenohcxx::zenohc::lib)  

	set_property(TARGET zenoh_demo_ishapes PROPERTY LANGUAGE CXX)
    set_property(TARGET zenoh_demo_ishapes PROPERTY CXX_STANDARD 17)

	install(TARGETS zenoh_demo_ishapes RUNTIME DESTINATION "${PROJECT_SOURCE_DIR}/bin")
	#install(TARGETS zenoh_demo_ishapes RUNTIME DESTINATION "${PROJECT_SOURCE_DIR}/bin")

	
