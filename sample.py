#!/usr/bin/env python3

##########################################################################################################
# Run the sample.py in your build directory after building, not the one in the root of py_gc_rel_patcher #
##########################################################################################################

import py_gc_rel_patcher as gcrp

relFile = gcrp.RELPatch.RELFile("mkb2.main_loop.rel")

# Write single value to section
relFile.writeToSectionU32(1, 32, 0xDEADBEEF)
relFile.writeToSectionU16(1, 36, 0xDEAD)
relFile.writeToSectionU8(1, 38, 0xBE)

# Section ID checks
relFile.writeToSectionU32(0, 32, 0xDEADBEEF)
# relFile.writeToSectionU32(-1, 32, 0xDEADBEEF)
relFile.writeToSectionU32(0xFFFFFFFF, 32, 0xDEADBEEF)
relFile.writeToSectionU32(99999, 32, 0xDEADBEEF)

# uint32Arr = [0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF]
# uint16Arr = [0xDEAD, 0xDEAD, 0xDEAD, 0xDEAD, 0xDEAD]
# uint8Arr = [0xDE, 0xDE, 0xDE, 0xDE, 0xDE]

# Write multiple values to section
# TODO: Get lists working
# relFile.writeToSectionListU32(1, 44, uint32Arr)
# relFile.writeToSectionListU16(1, 72, uint16Arr)
# relFile.writeToSectionListU8(1, 86, uint8Arr)

# Write single value to relocations
relFile.writeToRelocationsU32(32, 0xDEADBEEF)
relFile.writeToRelocationsU16(36, 0xDEAD)
relFile.writeToRelocationsU8(38, 0xDE)

# Write multiple values to relocations
# relFile.writeToRelocationsListU32(32, uint32Arr)
# relFile.writeToRelocationsListU16(36, uint16Arr)
# relFile.writeToRelocationsListU8(38, uint8Arr)

# Move a section to the back
relFile.moveSectionToEnd(1)

# Resize a section
relFile.expandSectionUnsafe(1, 1024)
