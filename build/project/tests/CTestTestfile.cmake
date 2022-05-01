# CMake generated Testfile for 
# Source directory: /home/user/Документы/TechDir/MyHomework/Homework-1/project/tests
# Build directory: /home/user/Документы/TechDir/MyHomework/Homework-1/build/project/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(BaseTest "/home/user/Документы/TechDir/MyHomework/Homework-1/build/project/tests/tests" "/home/user/Документы/TechDir/MyHomework/Homework-1/project/tests/data" "--gtest_filter=-*Extra*")
set_tests_properties(BaseTest PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Документы/TechDir/MyHomework/Homework-1/project/tests/CMakeLists.txt;26;ADD_TEST;/home/user/Документы/TechDir/MyHomework/Homework-1/project/tests/CMakeLists.txt;0;")
add_test(ExtraTest "/home/user/Документы/TechDir/MyHomework/Homework-1/build/project/tests/tests" "/home/user/Документы/TechDir/MyHomework/Homework-1/project/tests/data" "--gtest_filter=*Extra*")
set_tests_properties(ExtraTest PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Документы/TechDir/MyHomework/Homework-1/project/tests/CMakeLists.txt;30;ADD_TEST;/home/user/Документы/TechDir/MyHomework/Homework-1/project/tests/CMakeLists.txt;0;")
