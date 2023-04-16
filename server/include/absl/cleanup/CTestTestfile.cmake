# CMake generated Testfile for 
# Source directory: C:/git/library/abseil/abseil-cpp/absl/cleanup
# Build directory: C:/git/library/abseil/abseil-cpp/absl/cleanup
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_cleanup_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_cleanup_test.exe")
  set_tests_properties(absl_cleanup_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/cleanup/CMakeLists.txt;44;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/cleanup/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_cleanup_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_cleanup_test.exe")
  set_tests_properties(absl_cleanup_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/cleanup/CMakeLists.txt;44;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/cleanup/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_cleanup_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_cleanup_test.exe")
  set_tests_properties(absl_cleanup_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/cleanup/CMakeLists.txt;44;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/cleanup/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_cleanup_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_cleanup_test.exe")
  set_tests_properties(absl_cleanup_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/cleanup/CMakeLists.txt;44;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/cleanup/CMakeLists.txt;0;")
else()
  add_test(absl_cleanup_test NOT_AVAILABLE)
endif()
