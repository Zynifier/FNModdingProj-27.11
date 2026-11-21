// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMDeviceCableAnimator.h"

void UFMDeviceCableAnimatorBase::AddMaterialInstance(UMaterialInstanceDynamic* InMaterialInstance)
{
}

void UFMDeviceCableAnimatorBase::OnConnectionEnded(UFMDeviceCableConnectionBase* EndedConnection)
{
}

void UFMDeviceCableAnimatorBase::OnConnectionStarted(UFMDeviceCableConnectionBase* NewConnection)
{
}

void UFMDeviceCableAnimatorBase::OnPortArtifactUpdated()
{
}

void UFMDeviceCableAnimatorBase::RemoveMaterialInstance(UMaterialInstanceDynamic* InMaterialInstance)
{
}

void UFMDeviceCableAnimatorBase::SetOwnerPort(UFMDeviceCablePortComponent* OwnerPort)
{
}

float UFMDeviceCableAnimatorAudioAnalyzer::GetLastAnalyzerValue() const
{
	return float();
}

void UFMDeviceCableAnimatorAudioAnalyzer::OnMetaSoundOutputFloatChangedBatch(const FName& OutputName, TArray<float>& Output, FFabricMetaSoundPatchWrapperPeakTamer& PeakTamer, float DeltaSeconds)
{
}

void UFMDeviceCableAnimatorAudioAnalyzer::SetAnalyzerName(FName AnalyzerName)
{
}

void UFMDeviceCableAnimatorFloatProvider::SetFloatProvider(UFabricFloatProviderBase* InFloatProvider)
{
}

void UFMDeviceCableAnimatorMeshProvider::SetMeshProvider(UFabricMeshProviderBase* InMeshProvider)
{
}

void UFMDeviceCableAnimatorMidiEvent::OnMetaSoundOutputIntChangedBatch(const FName& OutputName, const TArray<int32>& Output)
{
}

void UFMDeviceCableAnimatorTextureProvider::SetTextureProvider(UFabricTextureProviderBase* InTextureProvider)
{
}
