add_executable(vector_tests vector_test.cpp templates_test.cpp)

target_link_libraries(vector_tests 
	gtest_main 
	scl_lib
)

add_test(vector_tests vector_tests)