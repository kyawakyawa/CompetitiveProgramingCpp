set(AOJ_CLANG_WARNING_FLAGS
  -Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-unused-macros -Wno-missing-prototypes -Wno-missing-variable-declarations -Wno-global-constructors -Wno-exit-time-destructors -Wno-sign-conversion -Wno-gnu-zero-variadic-macro-arguments)
set(AOJ_GCC_WARNING_FLAGS
  -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused)
set(AOJ_MSVC_WARNING_FLAGS /W4)

set(AOJ_CLANG_DEFINITIONS _LIBCPP_DEBUG _GLIBCXX_DEBUG)
set(AOJ_GCC_DEFINITIONS _GLIBCXX_DEBUG)
set(AOJ_MSVC_DEFINITIONS )

set(AOJ_BIN_DIR ${PROJECT_BINARY_DIR})

if (USE_STACK_TRACE_LOGGER)
  set(AOJ_CLANG_DEFINITIONS ${AOJ_CLANG_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(AOJ_GCC_DEFINITIONS ${AOJ_GCC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(AOJ_MSVC_DEFINITIONS ${AOJ_MSVC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(AOJ_LINK_LIBRARIES ${AOJ_LINK_LIBRARIES} "glog::glog")
endif()


set(AOJ_COMPILE_FEATURES "cxx_std_17")

set(SITE_NAME aoj)

set(PROBLEM_NOS "")

list(APPEND PROBLEM_NOS DSL_4_A)

list(APPEND PROBLEM_NOS ITP1_7_B)


foreach(PROBLEM_NO IN LISTS PROBLEM_NOS)
  add_executable(${SITE_NAME}${PROBLEM_NO} ${PROBLEM_NO}.cc)
  list(APPEND EXECUTABLE_TARGETS ${SITE_NAME}${PROBLEM_NO})
endforeach()

foreach(EXECUTABLE_TARGET IN LISTS EXECUTABLE_TARGETS)
  target_link_libraries(${EXECUTABLE_TARGET} PRIVATE ${AOJ_LINK_LIBRARIES})
  target_compile_options(${EXECUTABLE_TARGET} PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:${AOJ_CLANG_WARNING_FLAGS}>
    $<$<CXX_COMPILER_ID:GCC>:  ${AOJ_GCC_WARNING_FLAGS}>
    $<$<CXX_COMPILER_ID:MSVC>: ${AOJ_MSVC_WARNING_FLAGS}>)
  target_compile_features(${EXECUTABLE_TARGET} PRIVATE ${AOJ_COMPILE_FEATURES})
  target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:${AOJ_CLANG_DEFINITIONS}>
    $<$<CXX_COMPILER_ID:GCC>:  ${AOJ_GCC_DEFINITIONS}>
    $<$<CXX_COMPILER_ID:MSVC>: ${AOJ_MSVC_DEFINITIONS}>)
set_target_properties(${EXECUTABLE_TARGET} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${AOJ_BIN_DIR})
endforeach()
