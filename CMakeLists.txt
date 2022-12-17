cmake_minimum_required(VERSION 2.8)

project(FormalLanguages)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

add_executable(main
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/src/grammar.cpp
  ${PROJECT_SOURCE_DIR}/src/earley.cpp
)

add_executable(test
  ${PROJECT_SOURCE_DIR}/src/test.cpp
  ${PROJECT_SOURCE_DIR}/src/grammar.cpp
  ${PROJECT_SOURCE_DIR}/src/earley.cpp
  ${PROJECT_SOURCE_DIR}/src/chomsky_to_greybuh.cpp

  ${PROJECT_SOURCE_DIR}/src/CYK.cpp
  ${PROJECT_SOURCE_DIR}/src/HomskiNormalForm.cpp
  ${PROJECT_SOURCE_DIR}/src/Globals.cpp
  ${PROJECT_SOURCE_DIR}/src/Printfuncs.cpp
  
)

add_executable(main_cyk
  ${PROJECT_SOURCE_DIR}/src/CYK.cpp
  ${PROJECT_SOURCE_DIR}/src/HomskiNormalForm.cpp
  ${PROJECT_SOURCE_DIR}/src/Globals.cpp
  ${PROJECT_SOURCE_DIR}/src/GetWords.cpp
  ${PROJECT_SOURCE_DIR}/src/GetGrammar.cpp
  ${PROJECT_SOURCE_DIR}/src/Printfuncs.cpp
  ${PROJECT_SOURCE_DIR}/src/own_CYK.cpp
)

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(main_cyk PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/include)