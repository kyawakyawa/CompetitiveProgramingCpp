set(LIBRARY_CLANG_WARNING_FLAGS
  -Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-unused-macros -Wno-missing-prototypes -Wno-missing-variable-declarations -Wno-global-constructors -Wno-exit-time-destructors -Wno-sign-conversion -Wno-gnu-zero-variadic-macro-arguments)
set(LIBRARY_GCC_WARNING_FLAGS
  -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused)
set(LIBRARY_MSVC_WARNING_FLAGS /W4)

set(LIBRARY_CLANG_DEFINITIONS _LIBCPP_DEBUG _GLIBCXX_DEBUG)
set(LIBRARY_GCC_DEFINITIONS _GLIBCXX_DEBUG)
set(LIBRARY_MSVC_DEFINITIONS )

set(LIBRARY_BIN_DIR ${PROJECT_BINARY_DIR})

if (USE_STACK_TRACE_LOGGER)
  set(LIBRARY_CLANG_DEFINITIONS ${LIBRARY_CLANG_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(LIBRARY_GCC_DEFINITIONS ${LIBRARY_GCC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(LIBRARY_MSVC_DEFINITIONS ${LIBRARY_MSVC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(LIBRARY_LINK_LIBRARIES ${LIBRARY_LINK_LIBRARIES} "glog::glog")
endif()

set(LIBRARY_COMPILE_FEATURES "cxx_std_17")

add_executable(coordinate-compress coordinate-compress/coordinate-compress.cc)
list(APPEND EXECUTABLE_TARGETS coordinate-compress)
add_executable(lis dp/lis.cc)
list(APPEND EXECUTABLE_TARGETS lis)
add_executable(dijkstra graph/dijkstra.cc)
list(APPEND EXECUTABLE_TARGETS dijkstra)

foreach(EXECUTABLE_TARGET IN LISTS EXECUTABLE_TARGETS)
  target_link_libraries(${EXECUTABLE_TARGET} PRIVATE ${LIBRARY_LINK_LIBRARIES})
  target_compile_options(${EXECUTABLE_TARGET} PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:${LIBRARY_CLANG_WARNING_FLAGS}>
    $<$<CXX_COMPILER_ID:GCC>:  ${LIBRARY_GCC_WARNING_FLAGS}>
    $<$<CXX_COMPILER_ID:MSVC>: ${LIBRARY_MSVC_WARNING_FLAGS}>)
  target_compile_features(${EXECUTABLE_TARGET} PRIVATE ${LIBRARY_COMPILE_FEATURES})
  target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:${LIBRARY_CLANG_DEFINITIONS}>
    $<$<CXX_COMPILER_ID:GCC>:  ${LIBRARY_GCC_DEFINITIONS}>
    $<$<CXX_COMPILER_ID:MSVC>: ${LIBRARY_MSVC_DEFINITIONS}>)
  set_target_properties(${EXECUTABLE_TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${LIBRARY_BIN_DIR})
endforeach()
