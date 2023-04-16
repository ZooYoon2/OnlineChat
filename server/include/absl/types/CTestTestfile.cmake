# CMake generated Testfile for 
# Source directory: C:/git/library/abseil/abseil-cpp/absl/types
# Build directory: C:/git/library/abseil/abseil-cpp/absl/types
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_any_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_any_test.exe")
  set_tests_properties(absl_any_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;60;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_any_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_any_test.exe")
  set_tests_properties(absl_any_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;60;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_any_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_any_test.exe")
  set_tests_properties(absl_any_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;60;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_any_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_any_test.exe")
  set_tests_properties(absl_any_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;60;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_any_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_any_test_noexceptions "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_any_test_noexceptions.exe")
  set_tests_properties(absl_any_test_noexceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;76;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_any_test_noexceptions "C:/git/library/abseil/abseil-cpp/bin/Release/absl_any_test_noexceptions.exe")
  set_tests_properties(absl_any_test_noexceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;76;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_any_test_noexceptions "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_any_test_noexceptions.exe")
  set_tests_properties(absl_any_test_noexceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;76;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_any_test_noexceptions "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_any_test_noexceptions.exe")
  set_tests_properties(absl_any_test_noexceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;76;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_any_test_noexceptions NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_any_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_any_exception_safety_test.exe")
  set_tests_properties(absl_any_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;92;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_any_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_any_exception_safety_test.exe")
  set_tests_properties(absl_any_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;92;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_any_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_any_exception_safety_test.exe")
  set_tests_properties(absl_any_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;92;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_any_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_any_exception_safety_test.exe")
  set_tests_properties(absl_any_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;92;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_any_exception_safety_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_span_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_span_test.exe")
  set_tests_properties(absl_span_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;123;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_span_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_span_test.exe")
  set_tests_properties(absl_span_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;123;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_span_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_span_test.exe")
  set_tests_properties(absl_span_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;123;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_span_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_span_test.exe")
  set_tests_properties(absl_span_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;123;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_span_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_span_test_noexceptions "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_span_test_noexceptions.exe")
  set_tests_properties(absl_span_test_noexceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;143;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_span_test_noexceptions "C:/git/library/abseil/abseil-cpp/bin/Release/absl_span_test_noexceptions.exe")
  set_tests_properties(absl_span_test_noexceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;143;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_span_test_noexceptions "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_span_test_noexceptions.exe")
  set_tests_properties(absl_span_test_noexceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;143;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_span_test_noexceptions "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_span_test_noexceptions.exe")
  set_tests_properties(absl_span_test_noexceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;143;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_span_test_noexceptions NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_optional_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_optional_test.exe")
  set_tests_properties(absl_optional_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;213;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_optional_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_optional_test.exe")
  set_tests_properties(absl_optional_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;213;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_optional_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_optional_test.exe")
  set_tests_properties(absl_optional_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;213;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_optional_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_optional_test.exe")
  set_tests_properties(absl_optional_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;213;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_optional_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_optional_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_optional_exception_safety_test.exe")
  set_tests_properties(absl_optional_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;229;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_optional_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_optional_exception_safety_test.exe")
  set_tests_properties(absl_optional_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;229;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_optional_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_optional_exception_safety_test.exe")
  set_tests_properties(absl_optional_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;229;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_optional_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_optional_exception_safety_test.exe")
  set_tests_properties(absl_optional_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;229;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_optional_exception_safety_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_conformance_testing_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_conformance_testing_test.exe")
  set_tests_properties(absl_conformance_testing_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;267;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_conformance_testing_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_conformance_testing_test.exe")
  set_tests_properties(absl_conformance_testing_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;267;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_conformance_testing_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_conformance_testing_test.exe")
  set_tests_properties(absl_conformance_testing_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;267;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_conformance_testing_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_conformance_testing_test.exe")
  set_tests_properties(absl_conformance_testing_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;267;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_conformance_testing_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_conformance_testing_test_no_exceptions "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_conformance_testing_test_no_exceptions.exe")
  set_tests_properties(absl_conformance_testing_test_no_exceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;283;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_conformance_testing_test_no_exceptions "C:/git/library/abseil/abseil-cpp/bin/Release/absl_conformance_testing_test_no_exceptions.exe")
  set_tests_properties(absl_conformance_testing_test_no_exceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;283;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_conformance_testing_test_no_exceptions "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_conformance_testing_test_no_exceptions.exe")
  set_tests_properties(absl_conformance_testing_test_no_exceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;283;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_conformance_testing_test_no_exceptions "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_conformance_testing_test_no_exceptions.exe")
  set_tests_properties(absl_conformance_testing_test_no_exceptions PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;283;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_conformance_testing_test_no_exceptions NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_variant_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_variant_test.exe")
  set_tests_properties(absl_variant_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;315;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_variant_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_variant_test.exe")
  set_tests_properties(absl_variant_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;315;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_variant_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_variant_test.exe")
  set_tests_properties(absl_variant_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;315;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_variant_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_variant_test.exe")
  set_tests_properties(absl_variant_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;315;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_variant_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_compare_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_compare_test.exe")
  set_tests_properties(absl_compare_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;345;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_compare_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_compare_test.exe")
  set_tests_properties(absl_compare_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;345;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_compare_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_compare_test.exe")
  set_tests_properties(absl_compare_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;345;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_compare_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_compare_test.exe")
  set_tests_properties(absl_compare_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;345;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_compare_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_variant_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_variant_exception_safety_test.exe")
  set_tests_properties(absl_variant_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;358;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_variant_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_variant_exception_safety_test.exe")
  set_tests_properties(absl_variant_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;358;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_variant_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_variant_exception_safety_test.exe")
  set_tests_properties(absl_variant_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;358;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_variant_exception_safety_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_variant_exception_safety_test.exe")
  set_tests_properties(absl_variant_exception_safety_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;358;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/types/CMakeLists.txt;0;")
else()
  add_test(absl_variant_exception_safety_test NOT_AVAILABLE)
endif()
