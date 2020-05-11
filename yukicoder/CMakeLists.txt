set(YUKICODER_CLANG_WARNING_FLAGS
  -Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-unused-macros -Wno-missing-prototypes -Wno-missing-variable-declarations -Wno-global-constructors -Wno-exit-time-destructors -Wno-sign-conversion -Wno-gnu-zero-variadic-macro-arguments)
set(YUKICODER_GCC_WARNING_FLAGS
  -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused)
set(YUKICODER_MSVC_WARNING_FLAGS /W4)

set(YUKICODER_CLANG_DEFINITIONS _LIBCPP_DEBUG _GLIBCXX_DEBUG)
set(YUKICODER_GCC_DEFINITIONS _GLIBCXX_DEBUG)
set(YUKICODER_MSVC_DEFINITIONS )

set(YUKICODER_BIN_DIR ${PROJECT_BINARY_DIR})

if (USE_STACK_TRACE_LOGGER)
  set(YUKICODER_CLANG_DEFINITIONS ${YUKICODER_CLANG_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(YUKICODER_GCC_DEFINITIONS ${YUKICODER_GCC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(YUKICODER_MSVC_DEFINITIONS ${YUKICODER_MSVC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(YUKICODER_LINK_LIBRARIES ${YUKICODER_LINK_LIBRARIES} "glog::glog")
endif()


set(YUKICODER_COMPILE_FEATURES "cxx_std_17")

set(SITE_NAME yukicoder)

set(PROBLEM_NOS "")

list(APPEND PROBLEM_NOS 1046)

foreach(PROBLEM_NO IN LISTS PROBLEM_NOS)
  add_executable(${SITE_NAME}${PROBLEM_NO} ${PROBLEM_NO}.cc)
  list(APPEND EXECUTABLE_TARGETS ${SITE_NAME}${PROBLEM_NO})
endforeach()

foreach(EXECUTABLE_TARGET IN LISTS EXECUTABLE_TARGETS)
  target_link_libraries(${EXECUTABLE_TARGET} PRIVATE ${YUKICODER_LINK_LIBRARIES})
  target_compile_options(${EXECUTABLE_TARGET} PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:${YUKICODER_CLANG_WARNING_FLAGS}>
    $<$<CXX_COMPILER_ID:GCC>:  ${YUKICODER_GCC_WARNING_FLAGS}>
    $<$<CXX_COMPILER_ID:MSVC>: ${YUKICODER_MSVC_WARNING_FLAGS}>)
  target_compile_features(${EXECUTABLE_TARGET} PRIVATE ${YUKICODER_COMPILE_FEATURES})
  target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:${YUKICODER_CLANG_DEFINITIONS}>
    $<$<CXX_COMPILER_ID:GCC>:  ${YUKICODER_GCC_DEFINITIONS}>
    $<$<CXX_COMPILER_ID:MSVC>: ${YUKICODER_MSVC_DEFINITIONS}>)
set_target_properties(${EXECUTABLE_TARGET} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${YUKICODER_BIN_DIR})
endforeach()
