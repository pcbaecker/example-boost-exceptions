#ifndef EXAMPLE_BOOST_EXCEPTIONS_FILE_H
#define EXAMPLE_BOOST_EXCEPTIONS_FILE_H

// On mac we need to define this macro to use stacktrace
#define BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED

#include <boost/stacktrace.hpp>
#include <boost/exception/all.hpp>

/**
 * @brief The error info for the stacktrace.
 */
typedef boost::error_info<struct Stacktrace, boost::stacktrace::stacktrace> FileErrorInfoStacktrace;

/**
 * @brief The error info object containing the filename.
 */
typedef boost::error_info<struct Filename,std::string> FileErrorInfoFilename;

/**
 * @brief The error info object containing the return code.
 */
typedef boost::error_info<struct ReturnCode,int> FileErrorInfoReturnCode;

/**
 * @brief The basic exception object for this class.
 */
struct FileException : virtual boost::exception, virtual std::exception { };

/**
 * @brief A special exception object for special parts of this class.
 */
struct FileReadException : virtual FileException { };

/**
 * @brief Simulates some action.
 */
class File {
public:
    /**
     * @brief Tries to get the content of a file.
     *
     * @throws FileError
     * @param filename The filename.
     * @return Pointer to a string with the content.
     */
    std::shared_ptr<std::string> getContent(const std::string &filename);

private:
    /**
     * @brief Tries to read the file content into the given string reference.
     *
     * @throws FileReadError
     * @param pFileptr The file pointer to read from.
     * @param content The string reference where the content goes to.
     */
    void read(FILE* pFileptr, std::string& content);
};

#endif
