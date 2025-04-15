include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Simon_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Simon_default_default_XC8_FILE_TYPE_assemble)
add_library(Simon_default_default_XC8_assemble OBJECT ${Simon_default_default_XC8_FILE_TYPE_assemble})
    Simon_default_default_XC8_assemble_rule(Simon_default_default_XC8_assemble)
    list(APPEND Simon_default_library_list "$<TARGET_OBJECTS:Simon_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(Simon_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Simon_default_default_XC8_assemblePreprocess OBJECT ${Simon_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Simon_default_default_XC8_assemblePreprocess_rule(Simon_default_default_XC8_assemblePreprocess)
    list(APPEND Simon_default_library_list "$<TARGET_OBJECTS:Simon_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(Simon_default_default_XC8_FILE_TYPE_compile)
add_library(Simon_default_default_XC8_compile OBJECT ${Simon_default_default_XC8_FILE_TYPE_compile})
    Simon_default_default_XC8_compile_rule(Simon_default_default_XC8_compile)
    list(APPEND Simon_default_library_list "$<TARGET_OBJECTS:Simon_default_default_XC8_compile>")
endif()

add_executable(${Simon_default_image_name} ${Simon_default_library_list})

target_link_libraries(${Simon_default_image_name} PRIVATE ${Simon_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
Simon_default_link_rule(${Simon_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${Simon_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${Simon_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${Simon_default_image_name} ${Simon_default_output_dir}/${Simon_default_original_image_name}
                    BYPRODUCTS ${Simon_default_output_dir}/${Simon_default_original_image_name})
