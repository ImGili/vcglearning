macro(AddCGALExecutable exeName src)
    add_executable(${exeName}
                                    ${src}
    )

    target_link_libraries(${exeName}
                            
    )

    target_include_directories(${exeName} PUBLIC
            ${VCGLIB_INCLUDE_DIRS}
    )
    message("Add exe :${exeName}")
endmacro()