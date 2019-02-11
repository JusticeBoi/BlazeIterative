project(test)
set(CMAKE_CXX_STANDARD 14)

add_executable(blz_iter_test main.cpp)
add_executable(main_reader main_reader.cpp)

#target_compile_features(blz_iter_test PUBLIC cxx_std_14)
#target_compile_features(main_reader PUBLIC cxx_std_14)


target_link_libraries(blz_iter_test BlazeIterative)
target_link_libraries(main_reader BlazeIterative)
