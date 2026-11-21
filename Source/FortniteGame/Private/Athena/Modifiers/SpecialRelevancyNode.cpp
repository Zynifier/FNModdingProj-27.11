// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/SpecialRelevancyNode.h"
#include "Net/UnrealNetwork.h"

bool AFortAthenaMutator_SpecialRelevancy::AreActorsInSameRelvancyGroup(const AActor* Actor0, const AActor* Actor1) const
{
	return false;
}

int32 AFortAthenaMutator_SpecialRelevancy::FindRelevancyGroupIndex(const AActor* Actor) const
{
	return int32();
}

void AFortAthenaMutator_SpecialRelevancy::GetActors(TArray<AActor*>& OutActors, const int32 RelevancyGroupIndex, TSubclassOf<AActor> ActorClass) const
{
}

int32 AFortAthenaMutator_SpecialRelevancy::GetMaxSquadSize() const
{
	return int32();
}

int32 AFortAthenaMutator_SpecialRelevancy::GetNumRelevancyGroups() const
{
	return int32();
}

void AFortAthenaMutator_SpecialRelevancy::GetPlayerPawns(TArray<AFortPlayerPawn*>& OutPawns, const int32 RelevancyGroupIndex) const
{
}

void AFortAthenaMutator_SpecialRelevancy::GetRelevantPawnGroups(TArray<FRelevantPawnArray>& RelevantPawns) const
{
}

void AFortAthenaMutator_SpecialRelevancy::OnRep_CurrentRelevancyMode(FSpecialRelevancyModeData PrevMode)
{
}

void AFortAthenaMutator_SpecialRelevancy::PlacePawnOnPlayerStart(AFortPlayerController* PlayerController)
{
}

void AFortAthenaMutator_SpecialRelevancy::SetClientAuthoritativePhysics(bool bEnabled)
{
}

void AFortAthenaMutator_SpecialRelevancy::SpawnActorPerRelevancyGroup(const FSpecialActorSpawnData& NewSpawnData, TArray<AActor*>& SpawnedActors)
{
}

void AFortAthenaMutator_SpecialRelevancy::StartMultiSquadRelevancy(int32 NumOfSquadsInRelevancyGroup)
{
}

void AFortAthenaMutator_SpecialRelevancy::StartNormalRelevancy()
{
}

void AFortAthenaMutator_SpecialRelevancy::StartSoloRelevancy()
{
}

void AFortAthenaMutator_SpecialRelevancy::StartSquadRelevancy()
{
}

void AFortAthenaMutator_SpecialRelevancy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_SpecialRelevancy, CurrentRelevancyModeData);
	DOREPLIFETIME(AFortAthenaMutator_SpecialRelevancy, ClientRelevancyGroups);
}

void UFortCheatManager_SpecialRelevancy::StartMultiSquadRelevancy(int32 NumOfSquadsInRelevancyGroup)
{
}

void UFortCheatManager_SpecialRelevancy::StartNormalRelevancy()
{
}

void UFortCheatManager_SpecialRelevancy::StartSoloRelevancy()
{
}

void UFortCheatManager_SpecialRelevancy::StartSquadRelevancy()
{
}

void UFortReplicationGraphNode_SpecialRelevancy::OnSquadIdChanged(AFortPlayerStateAthena* PlayerState, const uint8 OldSquadIndex)
{
}
