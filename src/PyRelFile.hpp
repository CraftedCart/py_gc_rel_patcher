#ifndef PY_GC_REL_PATCHER_PYRELFILE_HPP
#define PY_GC_REL_PATCHER_PYRELFILE_HPP

#include <cstdint>
#include <vector>
#include <relFile.h>

//TODO: Get lists working

//#include <boost/python/stl_iterator.hpp>
//
//namespace py = boost::python;
//
//template< typename T >
//inline
//std::vector< T > toStdVector( const py::object& iterable )
//{
//    return std::vector< T >( py::stl_input_iterator< T >( iterable ),
//                             py::stl_input_iterator< T >( ) );
//}

class PyRELFile : public RELPatch::RELFile {
public:
    PyRELFile(const std::string &filename) : RELFile(filename) {}

//    void writeToSectionU32Vec(uint32_t sectionID, uint32_t offset, boost::python::list &list) {
//        std::vector<uint32_t> values = toStdVector<uint32_t>(list);
//        uint32_t *cValues = &values[0];
//        writeToSection(sectionID, offset, cValues, (uint32_t) values.size());
//    }
//
//    void writeToSectionU16Vec(uint32_t sectionID, uint32_t offset, boost::python::list &list) {
//        std::vector<uint32_t> values = toStdVector<uint32_t>(list);
//        uint32_t *cValues = &values[0];
//        writeToSection(sectionID, offset, cValues, (uint32_t) values.size());
//    }
//
//    void writeToSectionU8Vec(uint32_t sectionID, uint32_t offset, boost::python::list &list) {
//        std::vector<uint32_t> values = toStdVector<uint32_t>(list);
//        uint32_t *cValues = &values[0];
//        writeToSection(sectionID, offset, cValues, (uint32_t) values.size());
//    }
//
//    void writeToRelocationsU32Vec(uint32_t offset, boost::python::list &list) {
//        std::vector<uint32_t> values = toStdVector<uint32_t>(list);
//        uint32_t *cValues = &values[0];
//        writeToRelocations(offset, cValues, (uint32_t) values.size());
//    }
//
//    void writeToRelocationsU16Vec(uint32_t offset, boost::python::list &list) {
//        std::vector<uint32_t> values = toStdVector<uint32_t>(list);
//        uint32_t *cValues = &values[0];
//        writeToRelocations(offset, cValues, (uint32_t) values.size());
//    }
//
//    void writeToRelocationsU8Vec(uint32_t offset, boost::python::list &list) {
//        std::vector<uint32_t> values = toStdVector<uint32_t>(list);
//        uint32_t *cValues = &values[0];
//        writeToRelocations(offset, cValues, (uint32_t) values.size());
//    }
};

#endif //PY_GC_REL_PATCHER_PYRELFILE_HPP
