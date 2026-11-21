// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/FortFootstepBank.h"

USoundAttenuation* UFortFootstepAudioBank::GetAttenuationAsset(bool bIsLocal, EFortFootstepAudioType::Type StepType, EFortFootstepPosition::Type StepPosition)
{
	return nullptr;
}

float UFortFootstepAudioBank::GetFootstepVolumeMultiplier(bool bIsLocal, bool bApplyTeammateVolume, EFortFootstepAudioType::Type StepType)
{
	return float();
}

USoundBase* UFortFootstepAudioBank::GetSoundAsset(bool bIsLocal, EFortFootstepAudioType::Type StepType, EFortFootstepSurfaceType::Type SurfaceType, EFortFootstepPosition::Type StepPosition)
{
	return nullptr;
}

void UFortFootstepAudioBank::GetSurfaceInfo(FFortFootstepSurfaceInfo& OutInfo, EFortFootstepSurfaceType::Type InSurfaceType, bool bUse1PFootsteps) const
{
}

void UFortFootstepSurfaceData::GetSurfaceInfo(FFortFootstepSurfaceInfo& OutInfo, bool bUse1PFootsteps) const
{
}
