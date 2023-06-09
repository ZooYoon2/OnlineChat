# CMake generated Testfile for 
# Source directory: C:/git/library/abseil/abseil-cpp/absl/synchronization
# Build directory: C:/git/library/abseil/abseil-cpp/absl/synchronization
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_kernel_timeout_internal_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_kernel_timeout_internal_test.exe")
  set_tests_properties(absl_kernel_timeout_internal_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;54;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_kernel_timeout_internal_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_kernel_timeout_internal_test.exe")
  set_tests_properties(absl_kernel_timeout_internal_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;54;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_kernel_timeout_internal_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_kernel_timeout_internal_test.exe")
  set_tests_properties(absl_kernel_timeout_internal_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;54;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_kernel_timeout_internal_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_kernel_timeout_internal_test.exe")
  set_tests_properties(absl_kernel_timeout_internal_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;54;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_kernel_timeout_internal_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_barrier_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_barrier_test.exe")
  set_tests_properties(absl_barrier_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;120;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_barrier_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_barrier_test.exe")
  set_tests_properties(absl_barrier_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;120;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_barrier_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_barrier_test.exe")
  set_tests_properties(absl_barrier_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;120;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_barrier_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_barrier_test.exe")
  set_tests_properties(absl_barrier_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;120;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_barrier_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_blocking_counter_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_blocking_counter_test.exe")
  set_tests_properties(absl_blocking_counter_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;133;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_blocking_counter_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_blocking_counter_test.exe")
  set_tests_properties(absl_blocking_counter_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;133;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_blocking_counter_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_blocking_counter_test.exe")
  set_tests_properties(absl_blocking_counter_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;133;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_blocking_counter_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_blocking_counter_test.exe")
  set_tests_properties(absl_blocking_counter_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;133;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_blocking_counter_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_graphcycles_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_graphcycles_test.exe")
  set_tests_properties(absl_graphcycles_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;146;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_graphcycles_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_graphcycles_test.exe")
  set_tests_properties(absl_graphcycles_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;146;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_graphcycles_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_graphcycles_test.exe")
  set_tests_properties(absl_graphcycles_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;146;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_graphcycles_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_graphcycles_test.exe")
  set_tests_properties(absl_graphcycles_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;146;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_graphcycles_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_mutex_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_mutex_test.exe")
  set_tests_properties(absl_mutex_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;175;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_mutex_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_mutex_test.exe")
  set_tests_properties(absl_mutex_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;175;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_mutex_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_mutex_test.exe")
  set_tests_properties(absl_mutex_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;175;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_mutex_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_mutex_test.exe")
  set_tests_properties(absl_mutex_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;175;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_mutex_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_mutex_method_pointer_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_mutex_method_pointer_test.exe")
  set_tests_properties(absl_mutex_method_pointer_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;194;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_mutex_method_pointer_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_mutex_method_pointer_test.exe")
  set_tests_properties(absl_mutex_method_pointer_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;194;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_mutex_method_pointer_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_mutex_method_pointer_test.exe")
  set_tests_properties(absl_mutex_method_pointer_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;194;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_mutex_method_pointer_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_mutex_method_pointer_test.exe")
  set_tests_properties(absl_mutex_method_pointer_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;194;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_mutex_method_pointer_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_notification_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_notification_test.exe")
  set_tests_properties(absl_notification_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;208;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_notification_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_notification_test.exe")
  set_tests_properties(absl_notification_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;208;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_notification_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_notification_test.exe")
  set_tests_properties(absl_notification_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;208;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_notification_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_notification_test.exe")
  set_tests_properties(absl_notification_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;208;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_notification_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_per_thread_sem_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_per_thread_sem_test.exe")
  set_tests_properties(absl_per_thread_sem_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;239;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_per_thread_sem_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_per_thread_sem_test.exe")
  set_tests_properties(absl_per_thread_sem_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;239;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_per_thread_sem_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_per_thread_sem_test.exe")
  set_tests_properties(absl_per_thread_sem_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;239;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_per_thread_sem_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_per_thread_sem_test.exe")
  set_tests_properties(absl_per_thread_sem_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;239;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_per_thread_sem_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_waiter_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_waiter_test.exe")
  set_tests_properties(absl_waiter_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;254;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_waiter_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_waiter_test.exe")
  set_tests_properties(absl_waiter_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;254;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_waiter_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_waiter_test.exe")
  set_tests_properties(absl_waiter_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;254;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_waiter_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_waiter_test.exe")
  set_tests_properties(absl_waiter_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;254;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_waiter_test NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(absl_lifetime_test "C:/git/library/abseil/abseil-cpp/bin/Debug/absl_lifetime_test.exe")
  set_tests_properties(absl_lifetime_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;271;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(absl_lifetime_test "C:/git/library/abseil/abseil-cpp/bin/Release/absl_lifetime_test.exe")
  set_tests_properties(absl_lifetime_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;271;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(absl_lifetime_test "C:/git/library/abseil/abseil-cpp/bin/MinSizeRel/absl_lifetime_test.exe")
  set_tests_properties(absl_lifetime_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;271;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(absl_lifetime_test "C:/git/library/abseil/abseil-cpp/bin/RelWithDebInfo/absl_lifetime_test.exe")
  set_tests_properties(absl_lifetime_test PROPERTIES  _BACKTRACE_TRIPLES "C:/git/library/abseil/abseil-cpp/CMake/AbseilHelpers.cmake;440;add_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;271;absl_cc_test;C:/git/library/abseil/abseil-cpp/absl/synchronization/CMakeLists.txt;0;")
else()
  add_test(absl_lifetime_test NOT_AVAILABLE)
endif()
