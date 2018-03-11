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

void renderParticipiant(std::stringstream& ss, const ParticipantInfo pInfo)
{
	//TODO Display additional data from v8
}

void renderParticipiants(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"participiants\":{";
	ss << "\"mNumParticipiants\":" << sharedMemory->mNumParticipants;

	if (sharedMemory->mNumParticipants > -1)
	{
		ss << ",";
		ss << "\"mParticipiantInfo\":[";

		for (int i = 0; i < sharedMemory->mNumParticipants; i++)
		{
			renderParticipiant(ss, sharedMemory->mParticipantInfo[i]);
			if (i < (sharedMemory->mNumParticipants - 1)) {
				ss << ",";
			}
		}

		ss << "]";
	}

	ss << "}";
}


std::string JSONRenderer::renderJSON(const SharedMemory* sharedData, std::string query)
{
	std::stringstream ss;

	ss << "{";
	renderInput(ss, sharedData);
	ss << "}";

	return ss.str();
}