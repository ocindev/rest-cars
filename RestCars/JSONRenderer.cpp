#include "JSONRenderer.h"






JSONRenderer::JSONRenderer() {};


void renderInput(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"input\":{";
	ss << "\"mUnfilteredThrottle\":" << sharedMemory->mUnfilteredThrottle << ",";
	ss << "\"mUnfilteredBrake\":" << sharedMemory->mUnfilteredBrake << ",";
	ss << "\"mUnfilteredSteering\":" << sharedMemory->mUnfilteredSteering << ",";
	ss << "\"mUnfilteredClutch\":" << sharedMemory->mUnfilteredClutch << "}";
}



std::string JSONRenderer::renderJSON(const SharedMemory* sharedData, std::string query)
{
	std::stringstream ss;

	ss << "{";
	renderInput(ss, sharedData);
	ss << "}";

	return ss.str();
}