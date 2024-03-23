
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")


add_library(r_rules SHARED r_rules.c r_rules.h)
add_library(rulesStatic STATIC r_rules.c r_rules.h)


set_target_properties (
	rulesStatic
	PROPERTIES
	OUTPUT_NAME r_rules
	)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/r_rules.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/r_rules.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/r_rules.pc
	DESTINATION share/pkgconfig
	COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/r_rulesConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/r_rulesConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/r_rulesConfig.cmake
	DESTINATION cmake
)

install(
	TARGETS r_rules rulesStatic r_rules
	LIBRARY DESTINATION lib COMPONENT "Library"
	ARCHIVE DESTINATION lib COMPONENT "Library"
	RUNTIME DESTINATION bin COMPONENT "Runtime"
)

install(
	FILES r_rules.h
	DESTINATION include
	COMPONENT "Header"
)


