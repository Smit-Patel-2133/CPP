cmake_minimum_required(VERSION 3.28)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

# Define the first executable target
add_executable(cpp_main main.cpp)

# Define the second executable target with a different name
add_executable(cpp_DSA "DSA/Binary Tree/CountNode.cpp")
add_executable(cpp_DSA1 "DSA/Binary Tree/create.cpp")
add_executable(cpp_BC_TNQ "DSA/Backtracking/TotalNQueen.cpp")
add_executable(CPP_BC_NQ DSA/Backtracking/NQueend.cpp)
add_executable(CPP_Contest_402_3 "leet Code/Maximum_Total_Damage_With_Spell_Casting.cpp")
