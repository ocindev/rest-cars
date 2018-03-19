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

void renderParticipiant(std::stringstream& ss,int index, const SharedMemory* sharedMemory)
{
	const ParticipantInfo pInfo = sharedMemory->mParticipantInfo[index];
	ss << "{\"mIsActive\":" << (pInfo.mIsActive ? "true" : "false") << ",";
	ss << "\"mName\":\"" << pInfo.mName << "\",";
	ss << "\"mRacePosition\":" << pInfo.mRacePosition << ",";
	ss << "\"mCurrentLap\":" << pInfo.mCurrentLap << ",";
	ss << "\"mFastesLapTime\":" << sharedMemory->mFastestLapTimes[index] << ",";
	ss << "\"mPitmode\":" << sharedMemory->mPitModes[index] << ",";
	ss << "\"mRaceState\":" << sharedMemory->mRaceStates[index] << ",";
	ss << "\"mNationality\":" << sharedMemory->mNationalities[index] << ",";
	ss << "\"mCarClass\":\"" << sharedMemory->mCarClassNames[index] << "\",";
	ss << "\"mCarName\":\"" << sharedMemory->mCarNames[index] << "\",";
	ss << "\"position\": {";
	ss << "\"x\":" << pInfo.mWorldPosition[0] << ",";
	ss << "\"y\":" << pInfo.mWorldPosition[1] << ",";
	ss << "\"z\":" << pInfo.mWorldPosition[2] << "}}";

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
			renderParticipiant(ss, i, sharedMemory);
			if (i < (sharedMemory->mNumParticipants - 1)) {
				ss << ",";
			}
		}

		ss << "]";
	}

	ss << "}";
}

bool contains(std::string value, std::string key)
{
	if (value.compare("") > 0)
	{
		return ((int)value.find(key) > (int)std::string::npos);
	}
	else {
		return false;
	}
}

bool sectionEnabled(std::string queryString, std::string sectioName)
{
	std::stringstream ss;
	ss << sectioName << "=true";
	return queryString.empty() || contains(queryString, ss.str());
}


std::string JSONRenderer::renderJSON(const SharedMemory* sharedData, std::string query)
{
	std::stringstream ss;

		ss << "{";
		renderInput(ss, sharedData);
		ss << ",";
		renderParticipiants(ss, sharedData);
		ss << "}";

	return ss.str();
}