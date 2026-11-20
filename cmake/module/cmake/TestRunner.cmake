ADD_CUSTOM_TARGET(test)


ADD_CUSTOM_COMMAND(
        TARGET test
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND}
        -D TARGET_NAME=test
        -D CMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}
        -P ${PROJECT_SOURCE_DIR}/cmake/Tests.cmake
        COMMENT "Running tests.."
)
