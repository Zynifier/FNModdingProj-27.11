// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricMetasoundPatchWrapper.h"

bool UFabricMetaSoundPatchWrapper::AddToGraphOnFirstConnect_Implementation()
{
	return false;
}

void UFabricMetaSoundPatchWrapper::AddToManagerGraph(UFabricMetaSoundManagerComponent* Manager)
{
}

TSet<FName> UFabricMetaSoundPatchWrapper::GetMetaSoundInputNames() const
{
	return TSet<FName>();
}

UMusicClockComponent* UFabricMetaSoundPatchWrapper::GetMusicClock() const
{
	return nullptr;
}

bool UFabricMetaSoundPatchWrapper::GetRunsOnServer() const
{
	return false;
}

void UFabricMetaSoundPatchWrapper::OnAddedToManagerGraph_Implementation(UFabricMetaSoundManagerComponent* Manager)
{
}

void UFabricMetaSoundPatchWrapper::OnMetaSoundGeneratorHandleChanged_Implementation(UAudioComponent* AudioComponent, UMetasoundGeneratorHandle* GeneratorHandle)
{
}

void UFabricMetaSoundPatchWrapper::OnMetaSoundGeneratorHandleChangedDelegate(UAudioComponent* AudioComponent, UMetasoundGeneratorHandle* GeneratorHandle)
{
}

void UFabricMetaSoundPatchWrapper::OnMetasoundManagerEndPlay()
{
}

void UFabricMetaSoundPatchWrapper::OnMetaSoundOutputChanged(FName OutputName, const FMetaSoundOutput& Output)
{
}

void UFabricMetaSoundPatchWrapper::OnMetaSoundOutputValueChanged(FName OutputName, const FMetaSoundOutput& MetaSoundOutput)
{
}

void UFabricMetaSoundPatchWrapper::RemoveFromCurrentGraph()
{
}

void UFabricMetaSoundPatchWrapper::SetBoolInput(const FName& MetaSoundInputName, bool bValue)
{
}

void UFabricMetaSoundPatchWrapper::SetEnumInput(const FName& MetaSoundInputName, uint8 Value)
{
}

void UFabricMetaSoundPatchWrapper::SetFloatInput(const FName& MetaSoundInputName, float Value)
{
}

void UFabricMetaSoundPatchWrapper::SetIntInput(const FName& MetaSoundInputName, int32 Value)
{
}

void UFabricMetaSoundPatchWrapper::SetNodeEnabled(bool bEnabled)
{
}

void UFabricMetaSoundPatchWrapper::SetPositionalProxyActor(AActor* InLocationProxyActor)
{
}

void UFabricMetaSoundPatchWrapper::SetRunsOnServer(bool bAllowRunOnServer)
{
}

void UFabricMetaSoundPatchWrapper::SetStringInput(const FName& MetaSoundInputName, const FString& Value)
{
}

void UFabricMetaSoundSequencerPatchWrapper::SetMidiStepSequence(UMidiStepSequence* StepSequence)
{
}

void UFabricMetaSoundSpeakerPatchWrapper::SetAudioBusFromSourceBus(USoundSourceBus* Bus)
{
}

void UFabricMetaSoundTreeNode::ConnectToChildNodes()
{
}

TArray<UFabricMetaSoundTreeNode*> UFabricMetaSoundTreeNode::GetValidChildren()
{
	return TArray<UFabricMetaSoundTreeNode*>();
}

void UFabricMetaSoundTreeNode::Reset()
{
}
