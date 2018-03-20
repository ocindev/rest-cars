#include "mongoose.h"
#include "sharedmemory.h"
#include <string>
#include <sstream>
class JSONRenderer {
public:
	JSONRenderer();
	std::string renderJSON(const SharedMemory* sharedData);
};