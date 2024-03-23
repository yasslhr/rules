#find_program(DOXYGEN_EXECUTABLE doxygen)
#mark_as_advanced(DOXYGEN_EXECUTABLE)

#find_package(Sphinx)
#if(SPHINX_EXECUTABLE AND DOXYGEN_EXECUTABLE)
#	add_custom_target(docs
#		COMMAND
#			${SPHINX_EXECUTABLE}
#				-q
#				-b html
#				"${CMAKE_CURRENT_SOURCE_DIR}"
#				"${CMAKE_CURRENT_BINARY_DIR}/html"
#		WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
#		COMMENT "Building HTML documentation with Sphinx."
#	)
#
#	add_custom_command(TARGET docs POST_BUILD
#		COMMENT "HTML documentation is in ${CMAKE_CURRENT_BINARY_DIR}/html"
#	)
#
#	install(
#		DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
#		DESTINATION build/docs
#		COMPONENT "Docs"
#	)
#endif()

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../docs/docConfig)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/../docs/docs)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( docs ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
