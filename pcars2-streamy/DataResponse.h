#include <string>
#include "sharedmemory.h"

class DataResponse {
public:
	DataResponse();
	std::string render(const SharedMemory* sharedMemory, std::string query);
};