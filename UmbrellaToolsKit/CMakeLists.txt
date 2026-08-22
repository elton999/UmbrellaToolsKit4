add_executable (UmbrellaToolsKit "main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET UmbrellaToolsKit PROPERTY CXX_STANDARD 20)
endif()
