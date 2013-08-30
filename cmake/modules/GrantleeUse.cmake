
# Set up the include directories and link directories
include_directories(${Grantlee_INCLUDE_DIRS})

# Add the Grantlee modules directory to the CMake module path
set(CMAKE_MODULE_PATH ${Grantlee_MODULE_DIR} ${CMAKE_MODULE_PATH})

include(CMakeParseArguments)

macro(GRANTLEE_ADD_PLUGIN pluginname)
  set(options)
  set(oneValueArgs)
  set(multiValueArgs TAGS FILTERS)
  cmake_parse_arguments(_PLUGIN "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  set(_plugin_metadata ${pluginname}.json)

  foreach(_filename ${_PLUGIN_UNPARSED_ARGUMENTS})
    get_source_file_property(_skip ${_filename}.h SKIP_AUTOMOC)
    if (NOT _skip)
      set(_headers ${_headers} ${_filename}.h)
    endif()
    set(_sources ${_sources} ${_filename}.cpp)
  endforeach()
  foreach(_filename ${_PLUGIN_TAGS})
    set(_headers ${_headers} ${_filename}.h)
    set(_sources ${_sources} ${_filename}.cpp)
  endforeach()
  foreach(_filename ${_PLUGIN_FILTERS})
    set(_sources ${_sources} ${_filename}.cpp)
  endforeach()

  set(_sources ${_sources} ${_plugin_metadata})

  if (NOT CMAKE_AUTOMOC)
    qt5_wrap_cpp(_plugin_moc_srcs ${_headers})
  endif()

  add_library(${pluginname} MODULE ${_sources} ${_plugin_moc_srcs})

  foreach(file ${_sources})
    set(_sources_FULLPATHS ${_sources_FULLPATHS} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
  endforeach()
  set_property(GLOBAL APPEND PROPERTY SOURCE_LIST
    ${_sources_FULLPATHS}
  )

  set_target_properties(${pluginname}
    PROPERTIES PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/grantlee/${Grantlee_VERSION_MAJOR}.${Grantlee_VERSION_MINOR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/grantlee/${Grantlee_VERSION_MAJOR}.${Grantlee_VERSION_MINOR}"
  )
  target_link_libraries(${pluginname}
    grantlee_core
  )
endmacro(GRANTLEE_ADD_PLUGIN)
