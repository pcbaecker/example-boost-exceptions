#include "File.h"

std::shared_ptr<std::string> File::getContent(const std::string &filename) {
    try {
        // Create the result string
        std::shared_ptr<std::string> content(new std::string());

        // Open the file
        FILE* pFile = std::fopen(filename.c_str(), "r");

        // Try to read the content (error happens here)
        this->read(pFile, *content);

        return content;
    } catch (boost::exception& e) {
        // We extent the thrown exception by the filename and pass it to the caller
        e << FileErrorInfoFilename(filename);
        throw;
    }
}

void File::read(FILE *pFileptr, std::string &) {
    // Imaging an error occured during the read and we got an error code
    int returnCodeFromRead = -1;

    // Throw the exception with our special return code
    BOOST_THROW_EXCEPTION(FileReadException() << FileErrorInfoReturnCode(returnCodeFromRead));
}
