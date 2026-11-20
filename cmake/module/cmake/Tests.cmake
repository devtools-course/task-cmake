###########################################################################
#                  ⇓ DO NOT CHANGE THE LINES BELOW ⇓                      #
###########################################################################
INCLUDE(Parity)

# Test 0
IS_EVEN(0)
IF (CALL_RESULT)
    MESSAGE(STATUS "PASSED >>= 0")
ELSE ()
    MESSAGE(FATAL_ERROR "FAILED")
ENDIF ()

# Test 1
IS_EVEN(80)
IF (CALL_RESULT)
    MESSAGE(STATUS "PASSED >>= 1")
ELSE ()
    MESSAGE(FATAL_ERROR "FAILED")
ENDIF ()

# Test 2
IS_EVEN(89)
IF (CALL_RESULT)
    MESSAGE(FATAL_ERROR "FAILED")
ELSE ()
    MESSAGE(STATUS "PASSED >>= 2")
ENDIF ()

# Test 3
IS_EVEN(3)
IF (CALL_RESULT)
    MESSAGE(FATAL_ERROR "FAILED")
ELSE ()
    MESSAGE(STATUS "PASSED >>= 3")
ENDIF ()
###########################################################################
#                  ⇑ DO NOT CHANGE THE LINES ABOVE ⇑                      #
###########################################################################
