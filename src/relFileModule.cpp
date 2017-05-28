#include <boost/python.hpp>
#include "PyRelFile.hpp"

using namespace boost::python;

class DummyRELPatch {};

BOOST_PYTHON_MODULE(py_gc_rel_patcher) {
    scope RELPatch = class_<DummyRELPatch>("RELPatch");

    // wts: writeToSection
    void (PyRELFile::*wtsU32)(uint32_t, uint32_t, uint32_t) = &PyRELFile::writeToSection;
    void (PyRELFile::*wtsU16)(uint32_t, uint32_t, uint16_t) = &PyRELFile::writeToSection;
    void (PyRELFile::*wtsU8)(uint32_t, uint32_t, uint8_t) = &PyRELFile::writeToSection;

    // cd: copyData - cds: copyData to section
    void (PyRELFile::*cd)(uint32_t, uint32_t, uint32_t, uint32_t) = &PyRELFile::copyData;
    void (PyRELFile::*cds)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) = &PyRELFile::copyData;

    // wtr: writeToRelocations
    void (PyRELFile::*wtrU32)(uint32_t, uint32_t) = &PyRELFile::writeToRelocations;
    void (PyRELFile::*wtrU16)(uint32_t, uint16_t) = &PyRELFile::writeToRelocations;
    void (PyRELFile::*wtrU8)(uint32_t, uint8_t) = &PyRELFile::writeToRelocations;

    class_<PyRELFile, boost::noncopyable>("RELFile", init<std::string>())
            .def("filesize", &PyRELFile::filesize)
            .def("sectionSize", &PyRELFile::sectionSize)
            .def("sectionOffset", &PyRELFile::sectionOffset)
            .def("isSectionExecutable", &PyRELFile::isSectionExecutable)
            .def("writeToSectionU32", wtsU32)
            .def("writeToSectionU16", wtsU16)
            .def("writeToSectionU8", wtsU8)
//            .def("writeToSectionListU32", &PyRELFile::writeToSectionU32Vec)
//            .def("writeToSectionListU16", &PyRELFile::writeToSectionU16Vec)
//            .def("writeToSectionListU8", &PyRELFile::writeToSectionU8Vec)
            .def("moveSectionToEnd", &PyRELFile::moveSectionToEnd)
            .def("resizeSectionUnsafe", &PyRELFile::resizeSectionUnsafe)
            .def("expandSectionUnsafe", &PyRELFile::expandSectionUnsafe)
            .def("copyData", cd)
            .def("copyDataSection", cds)
            .def("relocationsOffset", &PyRELFile::relocationsOffset)
            .def("writeToRelocationsU32", wtrU32)
            .def("writeToRelocationsU16", wtrU16)
            .def("writeToRelocationsU8", wtrU8)
//            .def("writeToRelocationsListU32", &PyRELFile::writeToRelocationsU32Vec)
//            .def("writeToRelocationsListU16", &PyRELFile::writeToRelocationsU16Vec)
//            .def("writeToRelocationsListU8", &PyRELFile::writeToRelocationsU8Vec)
            ;
}
