PROJECT(wolfcrypt_key_cert_insert)
FILE(
    GLOB
    files
    *.c
)

ADD_EXECUTABLE(
    ${PROJECT_NAME}
    ${KSDK_STARTUP_FILE} ${files}
)

TARGET_COMPILE_DEFINITIONS(
    ${PROJECT_NAME}
    PRIVATE SIMW_DEMO_ENABLE__DEMO_WOLFCRYPT_KEY_CERT_INSERT USE_CERT_BUFFERS_2048 USE_CERT_BUFFERS_256
)

TARGET_INCLUDE_DIRECTORIES(
    ${PROJECT_NAME}
    PRIVATE ${SIMW_TOP_DIR}/sss/ex/inc
)

TARGET_LINK_LIBRARIES(
    ${PROJECT_NAME}
    SSS_APIs
    ex_common
    wolfssl
)

CREATE_BINARY(${PROJECT_NAME})

IF(SSS_HAVE_HOST_LINUX_LIKE)
    INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)
ENDIF()
