set(ATCODER_CLANG_WARNING_FLAGS
  -Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-unused-macros -Wno-missing-prototypes -Wno-missing-variable-declarations -Wno-global-constructors -Wno-exit-time-destructors -Wno-sign-conversion -Wno-gnu-zero-variadic-macro-arguments)
set(ATCODER_GCC_WARNING_FLAGS
  -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused)
set(ATCODER_MSVC_WARNING_FLAGS /W4)

set(ATCODER_CLANG_DEFINITIONS _LIBCPP_DEBUG _GLIBCXX_DEBUG)
set(ATCODER_GCC_DEFINITIONS _GLIBCXX_DEBUG)
set(ATCODER_MSVC_DEFINITIONS )

set(ATCODER_BIN_DIR ${PROJECT_BINARY_DIR})

if (USE_STACK_TRACE_LOGGER)
  set(ATCODER_CLANG_DEFINITIONS ${ATCODER_CLANG_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(ATCODER_GCC_DEFINITIONS ${ATCODER_GCC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(ATCODER_MSVC_DEFINITIONS ${ATCODER_MSVC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(ATCODER_LINK_LIBRARIES ${ATCODER_LINK_LIBRARIES} "glog::glog")
endif()


set(ATCODER_COMPILE_FEATURES "cxx_std_17")

add_executable(atcoder-template atcoder-template.cc)
target_link_libraries(atcoder-template PRIVATE ${ATCODER_LINK_LIBRARIES})
target_compile_options(atcoder-template PRIVATE
  $<$<CXX_COMPILER_ID:Clang>:${ATCODER_CLANG_WARNING_FLAGS}>
  $<$<CXX_COMPILER_ID:GCC>:  ${ATCODER_GCC_WARNING_FLAGS}>
  $<$<CXX_COMPILER_ID:MSVC>: ${ATCODER_MSVC_WARNING_FLAGS}>)
target_compile_features(atcoder-template PRIVATE ${ATCODER_COMPILE_FEATURES})
target_compile_definitions(atcoder-template PRIVATE
  $<$<CXX_COMPILER_ID:Clang>:${ATCODER_CLANG_DEFINITIONS}>
  $<$<CXX_COMPILER_ID:GCC>:  ${ATCODER_GCC_DEFINITIONS}>
  $<$<CXX_COMPILER_ID:MSVC>: ${ATCODER_MSVC_DEFINITIONS}>)
set_target_properties(atcoder-template PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${ATCODER_BIN_DIR})

add_subdirectory(abc021)
add_subdirectory(abc027)
add_subdirectory(abc030)
add_subdirectory(abc036)
add_subdirectory(abc048)
add_subdirectory(abc059)
add_subdirectory(abc065)
add_subdirectory(abc066)
add_subdirectory(abc097)
add_subdirectory(abc098)
add_subdirectory(abc103)
add_subdirectory(abc104)
add_subdirectory(abc105)
add_subdirectory(abc106)
add_subdirectory(abc108)
add_subdirectory(abc109)
add_subdirectory(abc112)
add_subdirectory(abc113)
add_subdirectory(abc114)
add_subdirectory(abc115)
add_subdirectory(abc116)
add_subdirectory(abc117)
add_subdirectory(abc118)
add_subdirectory(abc119)
add_subdirectory(abc120)
add_subdirectory(abc121)
add_subdirectory(abc122)
add_subdirectory(abc127)
add_subdirectory(abc130)
add_subdirectory(abc131)
add_subdirectory(abc133)
add_subdirectory(abc134)
add_subdirectory(abc135)
add_subdirectory(abc136)
add_subdirectory(abc137)
add_subdirectory(abc138)
add_subdirectory(abc141)
add_subdirectory(abc142)
add_subdirectory(abc144)
add_subdirectory(abc145)
add_subdirectory(abc146)
add_subdirectory(abc147)
add_subdirectory(abc148)
add_subdirectory(abc150)
add_subdirectory(abc151)
add_subdirectory(abc152)
add_subdirectory(abc153)
add_subdirectory(abc154)
add_subdirectory(abc155)
add_subdirectory(abc156)
add_subdirectory(abc157)
add_subdirectory(abc158)
add_subdirectory(abc159)
add_subdirectory(abc160)
add_subdirectory(abc161)
add_subdirectory(abc162)
add_subdirectory(abc163)
add_subdirectory(abc164)
add_subdirectory(abc165)
add_subdirectory(abc166)
add_subdirectory(abc167)
add_subdirectory(abc168)
add_subdirectory(abc169)
add_subdirectory(abc170)

add_subdirectory(arc022)
add_subdirectory(arc057)
add_subdirectory(arc103)

add_subdirectory(agc029)
add_subdirectory(agc031)
add_subdirectory(agc038)
add_subdirectory(agc040)
add_subdirectory(agc041)
add_subdirectory(agc043)

add_subdirectory(code-festival-2014-easy)
add_subdirectory(code-formula-2014-qualifying)
add_subdirectory(cf_2015_morning_easy)
add_subdirectory(code-thanks-festival-2017)

add_subdirectory(ddcc2020-qual)

add_subdirectory(digital-arts2012)

add_subdirectory(donuts-2015)

add_subdirectory(edpc)

add_subdirectory(joi2007ho)

add_subdirectory(nomura2020)

add_subdirectory(pakencamp-2019-day3)

add_subdirectory(smtb2019)

add_subdirectory(soundhound2018-summer-qual)

add_subdirectory(tenka1-2013-qualb)

add_subdirectory(tokiomarine2020)

add_subdirectory(yahoo-procon2019-qual)
