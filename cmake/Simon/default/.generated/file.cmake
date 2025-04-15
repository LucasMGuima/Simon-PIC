# The following variables contains the files used by the different stages of the build process.
set(Simon_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${Simon_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(Simon_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${Simon_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)
set(Simon_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/conversor.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/gerardor.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/simon.c")
set_source_files_properties(${Simon_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(Simon_default_default_XC8_FILE_TYPE_link)

# The (internal) path to the resulting build image.
set(Simon_default_internal_image_name "${CMAKE_CURRENT_SOURCE_DIR}/../../../_build/Simon/default/default.elf")

# The name of the resulting image, including namespace for configuration.
set(Simon_default_image_name "Simon_default_default.elf")

# The name of the image, excluding the namespace for configuration.
set(Simon_default_original_image_name "default.elf")

# The output directory of the final image.
set(Simon_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/Simon")
