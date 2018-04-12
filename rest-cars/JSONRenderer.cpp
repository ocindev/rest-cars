#include "JSONRenderer.h"



/**
	JSONRenderer for creating a JSON Object containing the shared memory data.
*/

JSONRenderer::JSONRenderer() {};

/**
	Adding the user input information.
*/
void renderInput(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"input\":{";
	ss << "\"mUnfilteredThrottle\":" << sharedMemory->mUnfilteredThrottle << ",";
	ss << "\"mUnfilteredBrake\":" << sharedMemory->mUnfilteredBrake << ",";
	ss << "\"mUnfilteredSteering\":" << sharedMemory->mUnfilteredSteering << ",";
	ss << "\"mUnfilteredClutch\":" << sharedMemory->mUnfilteredClutch << "}";
}

/**
	Adding information about the session event.
*/
void renderEvent(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"event\":{";
	ss << "\"mLapsInEvent\":" << sharedMemory->mLapsInEvent << ",";
	ss << "\"mTrackLocation\":" << sharedMemory->mTrackLocation << ",";
	ss << "\"mTrackVariation\":" << sharedMemory->mTrackVariation << ",";
	ss << "\"mTranslatedTrackLocation\":" << sharedMemory->mTranslatedTrackLocation << ",";
	ss << "\"mTranslatedTrackVariation\":" << sharedMemory->mTranslatedTrackVariation << ",";
	ss << "\"mTrackLength\":" << sharedMemory->mTrackLength << "}";
}

/**
	Adding information about timings.
*/
void renderTimings(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"timings\":{";
	ss << "\"mNumSectors\":" << sharedMemory->mNumSectors << ",";
	ss << "\"mLapInvalidated\":" << (sharedMemory->mLapInvalidated ? "true" : "false") << ",";
	ss << "\"mBestLapTime\":" << sharedMemory->mBestLapTime << ",";
	ss << "\"mLastLapTime\":" << sharedMemory->mLastLapTime << ",";
	ss << "\"mCurrentTime\":" << sharedMemory->mCurrentTime << ",";
	ss << "\"mSplitTimeAhead\":" << sharedMemory->mSplitTimeAhead << ",";
	ss << "\"mSplitTimeBehind\":" << sharedMemory->mSplitTimeBehind << ",";
	ss << "\"mSplitTime\":" << sharedMemory->mSplitTime << ",";
	ss << "\"mEventTimeRemaining\":" << sharedMemory->mEventTimeRemaining << ",";
	ss << "\"mPersonalFastestLapTime\":" << sharedMemory->mPersonalFastestLapTime << ",";
	ss << "\"mWorldFastestLapTime\":" << sharedMemory->mWorldFastestLapTime << ",";
	ss << "\"mCurrentSector1Time\":" << sharedMemory->mCurrentSector1Time << ",";
	ss << "\"mCurrentSector2Time\":" << sharedMemory->mCurrentSector2Time << ",";
	ss << "\"mCurrentSector3Time\":" << sharedMemory->mCurrentSector3Time << ",";
	ss << "\"mPersonalFastestSector1Time\":" << sharedMemory->mPersonalFastestSector1Time << ",";
	ss << "\"mPersonalFastestSector2Time\":" << sharedMemory->mPersonalFastestSector2Time << ",";
	ss << "\"mPersonalFastestSector3Time\":" << sharedMemory->mPersonalFastestSector3Time << ",";
	ss << "\"mWorldsFastestSector1Time\":" << sharedMemory->mWorldFastestSector1Time << ",";
	ss << "\"mWorldsFastestSector2Time\":" << sharedMemory->mWorldFastestSector2Time << ",";
	ss << "\"mWorldsFastestSector3Time\":" << sharedMemory->mWorldFastestSector3Time << "}";
} 

/**
	Adding information about the  game states.
*/
void renderGameStates(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"gameStates\":{";
	ss << "\"mGameState\":" << sharedMemory->mGameState << ",";
	ss << "\"mSessionState\":" << sharedMemory->mSessionState << ",";
	ss << "\"mRaceState\":" << sharedMemory->mSessionState << "}";
}


/**
	Adding information about the session weather.
*/
void renderWeather(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"weather\":{";
	ss << "\"mAmbientTemperature\":" << sharedMemory->mAmbientTemperature << ",";
	ss << "\"mTrackTemperature\":" << sharedMemory->mTrackTemperature << ",";
	ss << "\"mRainDensity\":" << sharedMemory->mRainDensity << ",";
	ss << "\"mWindSpeed\":" << sharedMemory->mWindSpeed << ",";
	ss << "\"mWindDirectionX\":" << sharedMemory->mWindDirectionX << ",";
	ss << "\"mWindDirectionY\":" << sharedMemory->mWindDirectionY << ",";
	ss << "\"mSnowDensity\":" << sharedMemory->mSnowDensity << ",";
	ss << "\"mCloudBrightness\":" << sharedMemory->mCloudBrightness << "}";
}

/**
	Adding information about the players flag states.
*/
void renderFlags(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"flags\":{";
	ss << "\"mHighestFlagColour\":" << sharedMemory->mHighestFlagColour << ",";
	ss << "\"mHighestFlagReason\":" << sharedMemory->mHighestFlagReason << "}";
}


/**
	Adding information about the players pit strategy.
*/
void renderPitInfo(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"pitInfo\":{";
	ss << "\"mPitMode\":" << sharedMemory->mPitMode << ",";
	ss << "\"mPitSchedule\":" << sharedMemory->mPitSchedule << ",";
	ss << "\"mEnforcedPitStopLap\":" << sharedMemory->mEnforcedPitStopLap << "}";
}


/**
	Adding information about the players car.
*/
void renderCarState(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"carState\":{";
	ss << "\"mCarName\":" << sharedMemory->mCarName << ",";
	ss << "\"mCarClassName\":" << sharedMemory->mCarClassName << ",";
	ss << "\"mCarFlags\":" << sharedMemory->mCarFlags << ",";
	ss << "\"mOilTempCelsius\":" << sharedMemory->mOilTempCelsius << ",";
	ss << "\"mOilPressurekPa\":" << sharedMemory->mOilPressureKPa << ",";
	ss << "\"mWaterTempCelsius\":" << sharedMemory->mWaterTempCelsius << ",";
	ss << "\"mWaterPressurekPa\":" << sharedMemory->mWaterPressureKPa << ",";
	ss << "\"mFuelPressurekPa\":" << sharedMemory->mFuelPressureKPa << ",";
	ss << "\"mFuelLevel\":" << sharedMemory->mFuelLevel << ",";
	ss << "\"mFuelCapacity\":" << sharedMemory->mFuelCapacity << ",";
	ss << "\"mSpeed\":" << sharedMemory->mSpeed << ",";
	ss << "\"mRPM\":" << sharedMemory->mRpm << ",";
	ss << "\"mMaxRPM\":" << sharedMemory->mMaxRPM << ",";
	ss << "\"mBrake\":" << sharedMemory->mBrake << ",";
	ss << "\"mThrottle\":" << sharedMemory->mThrottle << ",";
	ss << "\"mClutch\":" << sharedMemory->mClutch << ",";
	ss << "\"mSteering\":" << sharedMemory->mSteering << ",";
	ss << "\"mGear\":" << sharedMemory->mGear << ",";
	ss << "\"mNumGears\":" << sharedMemory->mNumGears << ",";
	ss << "\"mOdometerKM\":" << sharedMemory->mOdometerKM << ",";
	ss << "\"mAntiLockActive\":" << sharedMemory->mAntiLockActive << ",";
	ss << "\"mLastOpponentCollisionIndex\":" << sharedMemory->mLastOpponentCollisionIndex << ",";
	ss << "\"mLastOpponentCollisionMagnitude\":" << sharedMemory->mLastOpponentCollisionMagnitude << ",";
	ss << "\"mBoostActive\":" << sharedMemory->mBoostActive << ",";
	ss << "\"mBoostAmount\":" << sharedMemory->mBoostAmount << ",";
	ss << "\"mTurboBoostPressure\":" << sharedMemory->mTurboBoostPressure << ",";
	ss << "\"mBrakeBias\":" << sharedMemory->mBrakeBias << ",";
	ss << "\"mCrashState\":" << sharedMemory->mCrashState << ",";
	ss << "\"mAeroDamage\":" << sharedMemory->mAeroDamage << ",";
	ss << "\"mEngineDamage\":" << sharedMemory->mEngineDamage << ",";
	ss << "\"mEngineSpeed\":" << sharedMemory->mEngineSpeed << ",";
	ss << "\"mEngineTorque\":" << sharedMemory->mEngineTorque << ",";
	ss << "\"mWings\":[" << sharedMemory->mWings[1] << "," << sharedMemory->mWings[2] << "],";
	ss << "\"mHandBrake\": " << sharedMemory->mHandBrake << ",";
}

void renderWheelsTyres(std::stringstream& ss, const SharedMemory* sharedMemory)
{
	ss << "\"mWheelsTyres\":{";
	ss << "\"mTyreFlags\":[" << sharedMemory->mTyreFlags[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreFlags[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreFlags[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreFlags[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreTerrain\":[" << sharedMemory->mTerrain[TYRE_FRONT_LEFT] << "," << sharedMemory->mTerrain[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTerrain[TYRE_REAR_LEFT] << "," << sharedMemory->mTerrain[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreTemp\":[" << sharedMemory->mTyreTemp[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreTemp[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreTemp[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreTemp[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreRPS\":[" << sharedMemory->mTyreRPS[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreRPS[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreRPS[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreRPS[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreHeightAboveGround\":[" << sharedMemory->mTyreHeightAboveGround[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreHeightAboveGround[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreHeightAboveGround[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreHeightAboveGround[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreWear\":[" << sharedMemory->mTyreWear[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreWear[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreWear[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreWear[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mBrakeDamage\":[" << sharedMemory->mBrakeDamage[TYRE_FRONT_LEFT] << "," << sharedMemory->mBrakeDamage[TYRE_FRONT_RIGHT] << "," << sharedMemory->mBrakeDamage[TYRE_REAR_LEFT] << "," << sharedMemory->mBrakeDamage[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mSuspensionDamage\":[" << sharedMemory->mSuspensionDamage[TYRE_FRONT_LEFT] << "," << sharedMemory->mSuspensionDamage[TYRE_FRONT_RIGHT] << "," << sharedMemory->mSuspensionDamage[TYRE_REAR_LEFT] << "," << sharedMemory->mSuspensionDamage[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mBrakeTempCelsius\":[" << sharedMemory->mBrakeTempCelsius[TYRE_FRONT_LEFT] << "," << sharedMemory->mBrakeTempCelsius[TYRE_FRONT_RIGHT] << "," << sharedMemory->mBrakeTempCelsius[TYRE_REAR_LEFT] << "," << sharedMemory->mBrakeTempCelsius[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreTreadTemp\":[" << sharedMemory->mTyreTreadTemp[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreTreadTemp[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreTreadTemp[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreTreadTemp[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreLayerTemp\":[" << sharedMemory->mTyreLayerTemp[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreLayerTemp[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreLayerTemp[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreLayerTemp[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreCarcassTemp\":[" << sharedMemory->mTyreCarcassTemp[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreCarcassTemp[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreCarcassTemp[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreCarcassTemp[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreRimTemp\":[" << sharedMemory->mTyreRimTemp[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreRimTemp[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreRimTemp[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreRimTemp[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreInternalAirTemp\":[" << sharedMemory->mTyreInternalAirTemp[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreInternalAirTemp[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreInternalAirTemp[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreInternalAirTemp[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mWheelLocalPositionY\":[" << sharedMemory->mWheelLocalPositionY[TYRE_FRONT_LEFT] << "," << sharedMemory->mWheelLocalPositionY[TYRE_FRONT_RIGHT] << "," << sharedMemory->mWheelLocalPositionY[TYRE_REAR_LEFT] << "," << sharedMemory->mWheelLocalPositionY[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mSuspensionTravel\":[" << sharedMemory->mSuspensionTravel[TYRE_FRONT_LEFT] << "," << sharedMemory->mSuspensionTravel[TYRE_FRONT_RIGHT] << "," << sharedMemory->mSuspensionTravel[TYRE_REAR_LEFT] << "," << sharedMemory->mSuspensionTravel[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mSuspensionVelocity\":[" << sharedMemory->mSuspensionVelocity[TYRE_FRONT_LEFT] << "," << sharedMemory->mSuspensionVelocity[TYRE_FRONT_RIGHT] << "," << sharedMemory->mSuspensionVelocity[TYRE_REAR_LEFT] << "," << sharedMemory->mSuspensionVelocity[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mAirPressure\":[" << sharedMemory->mAirPressure[TYRE_FRONT_LEFT] << "," << sharedMemory->mAirPressure[TYRE_FRONT_RIGHT] << "," << sharedMemory->mAirPressure[TYRE_REAR_LEFT] << "," << sharedMemory->mAirPressure[TYRE_REAR_RIGHT] << "]";
	ss << ",";
	ss << "\"mTyreCompund\":[" << sharedMemory->mTyreCompound[TYRE_FRONT_LEFT] << "," << sharedMemory->mTyreCompound[TYRE_FRONT_RIGHT] << "," << sharedMemory->mTyreCompound[TYRE_REAR_LEFT] << "," << sharedMemory->mTyreCompound[TYRE_REAR_RIGHT] << "]";
	ss << "}";

}


/**
	Adding information about the session participiant.
*/
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
	ss << "\"mNationality\":" << sharedMemory->mNationalities[index] << ",";
	ss << "\"mPitSchedule\":" << sharedMemory->mPitSchedules[index] << ",";
	ss << "\"mHighestFlagColours\":" << sharedMemory->mHighestFlagColours[index] << ",";
	ss << "\"mHighestFlagReasons\":" << sharedMemory->mHighestFlagReasons[index] << ",";
	ss << "\"position\": {";
	ss << "\"x\":" << pInfo.mWorldPosition[0] << ",";
	ss << "\"y\":" << pInfo.mWorldPosition[1] << ",";
	ss << "\"z\":" << pInfo.mWorldPosition[2] << "}}";

}


/**
	Adding the session participiants.
*/
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


/**
	Returns an JSON string containing the shared memory data.
*/
std::string JSONRenderer::renderJSON(const SharedMemory* sharedData)
{
	std::stringstream ss;

		ss << "{";
		renderInput(ss, sharedData);
		ss << ",";
		renderParticipiants(ss, sharedData);
		ss << ",";
		renderWeather(ss, sharedData);
		ss << ",";
		renderCarState(ss, sharedData);
		ss << ",";
		renderEvent(ss, sharedData);
		ss << ",";
		renderFlags(ss, sharedData);
		ss << ",";
		renderGameStates(ss, sharedData);
		ss << ",";
		renderPitInfo(ss, sharedData);
		ss << ",";
		renderTimings(ss, sharedData);
		ss << ",";
		renderWheelsTyres(ss, sharedData);
		ss << "}";

	return ss.str();
}