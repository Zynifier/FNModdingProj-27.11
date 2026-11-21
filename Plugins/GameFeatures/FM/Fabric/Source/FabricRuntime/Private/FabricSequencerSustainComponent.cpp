// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricSequencerSustainComponent.h"

void UFabricSequencerSustainComponent::AddSustainInstance(int32 StepIndex, int32 TrackIndex)
{
}

float UFabricSequencerSustainComponent::CalculateSustainLength(float NumStepsCoveredBySustain)
{
	return float();
}

void UFabricSequencerSustainComponent::ConstructSustains()
{
}

void UFabricSequencerSustainComponent::FindAndDeleteInstance(int32 StepIndex, int32 TrackIndex)
{
}

void UFabricSequencerSustainComponent::FindHeadNoteAndUpdateInstance(int32 StepIndex, int32 TrackIndex)
{
}

void UFabricSequencerSustainComponent::InitializeSustainComponent(UFabricStepSequencerComponent* InStepSequencer, UFabricStepSequencerGridComponent* InStepSequencerGrid)
{
}

void UFabricSequencerSustainComponent::OnFullTableChanged()
{
}

void UFabricSequencerSustainComponent::OnNumStepsChanged(int32 NumSteps)
{
}

void UFabricSequencerSustainComponent::OnNumTracksChanged(int32 NumTracks)
{
}

void UFabricSequencerSustainComponent::OnPageChanged(int32 CurrentPage)
{
}

void UFabricSequencerSustainComponent::OnStepChanged(const FFabricSequencerStepChangedInfo& StepInfo)
{
}

void UFabricSequencerSustainComponent::SetEndBeat(int32 InstanceIndex, float EndBeatValue)
{
}

void UFabricSequencerSustainComponent::SetLoopBeat(int32 InstanceIndex, float LoopBeatValue)
{
}

void UFabricSequencerSustainComponent::SetStartBeat(int32 InstanceIndex, float StartBeatValue)
{
}

void UFabricSequencerSustainComponent::UpdateDeviceEnabledOnSustain(bool bEnabled)
{
}

void UFabricSequencerSustainComponent::UpdatePipsOnGridChanged()
{
}

void UFabricSequencerSustainComponent::UpdateSustainInstance(int32 StepIndex, int32 TrackIndex, int32 PageIndex, bool bEnabled, bool bContinuous, bool bStepChanged)
{
}

void UFabricSequencerSustainComponent::UpdateSustainMaterial(int32 InstanceIndex, int32 HeadNoteStepIndex, int32 TrackIndex)
{
}

void UFabricSequencerSustainComponent::UpdateVisibilityOfInstances()
{
}
