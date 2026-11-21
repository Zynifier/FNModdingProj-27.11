// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricMetasoundManagerComponent.h"
#include "Net/UnrealNetwork.h"

void UFabricMetaSoundManagerComponent::AddInputNodeForNodeByNameBP(FFabricMetaSoundNodeInfo& InOutNode, EFabricUserOptionType UserOptionType, const FName& InputName)
{
}

void UFabricMetaSoundManagerComponent::AddOutputNodeForOutputVertex(const FMetaSoundBuilderNodeOutputHandle& OutputVertex, const FName& NodeName, FName& OutOutputName, EMetaSoundBuilderResult& Result)
{
}

bool UFabricMetaSoundManagerComponent::AreAllPatchesReady() const
{
	return false;
}

void UFabricMetaSoundManagerComponent::FreeMetaSoundNode(const FFabricMetaSoundNodeInfo& Node)
{
}

UMetaSoundSourceBuilder* UFabricMetaSoundManagerComponent::GetBuilder() const
{
	return nullptr;
}

EFabricMetasoundPlayState UFabricMetaSoundManagerComponent::GetCurrentPlaystate() const
{
	return EFabricMetasoundPlayState();
}

UMetasoundGeneratorHandle* UFabricMetaSoundManagerComponent::GetMetasoundGeneratorHandle() const
{
	return nullptr;
}

FName UFabricMetaSoundManagerComponent::GetMetasoundInputNodeName(FName NodeName, FName InputName)
{
	return FName();
}

FFabricMetaSoundNodeInfo UFabricMetaSoundManagerComponent::GetMetaSoundNodeForWrapper(UFabricMetaSoundPatchWrapper* PatchWrapper)
{
	return FFabricMetaSoundNodeInfo();
}

UMusicClockComponent* UFabricMetaSoundManagerComponent::GetMusicClock() const
{
	return nullptr;
}

void UFabricMetaSoundManagerComponent::InvalidateMetasoundGeneratorHandle()
{
}

void UFabricMetaSoundManagerComponent::NotifyGraphChanged()
{
}

void UFabricMetaSoundManagerComponent::OnGeneratorJustStarted(int32 ComponentIndex)
{
}

void UFabricMetaSoundManagerComponent::OnMetasoundAuditionGeneratorHandleCreated(UMetasoundGeneratorHandle* GeneratorHandle)
{
}

void UFabricMetaSoundManagerComponent::PauseMetasound()
{
}

void UFabricMetaSoundManagerComponent::PlayMetasound(ABuildingActor* InStartMetasoundLockDevice)
{
}

void UFabricMetaSoundManagerComponent::RegisterAsAudible(AActor* Device)
{
}

void UFabricMetaSoundManagerComponent::SeekToMs(float Ms)
{
}

void UFabricMetaSoundManagerComponent::SeekToTimestamp(const FMusicTimestamp& Timestamp)
{
}

void UFabricMetaSoundManagerComponent::SetAudioComponents(TArray<UAudioComponent*> AudioComponents)
{
}

void UFabricMetaSoundManagerComponent::SetMetasoundGeneratorHandle(UAudioComponent* AudioComponent, UMetasoundGeneratorHandle* GeneratorHandle)
{
}

void UFabricMetaSoundManagerComponent::SetMusicClock(UMusicClockComponent* MusicClockComponent)
{
}

void UFabricMetaSoundManagerComponent::SetMusicKey(EMusicKey Key, EMusicKeyMode Mode)
{
}

void UFabricMetaSoundManagerComponent::SetSpeed(float Speed)
{
}

void UFabricMetaSoundManagerComponent::SetTempo(float Tempo)
{
}

void UFabricMetaSoundManagerComponent::SetTimeSignature(int32 Numerator, int32 Denominator)
{
}

void UFabricMetaSoundManagerComponent::StopMetasound(ABuildingActor* InStartMetasoundLockDevice)
{
}

void UFabricMetaSoundManagerComponent::UnregisterAsAudible(AActor* Device)
{
}

void UFabricMetaSoundManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFabricMetaSoundManagerComponent, ReplicatedReceivedSignalBufferDuration);
}
