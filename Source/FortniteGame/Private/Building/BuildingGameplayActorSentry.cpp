// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorSentry.h"
#include "Net/UnrealNetwork.h"

void ABuildingGameplayActorSentry::OnRep_CurrentSentryState(const EBuildingGameplayActorSentry_State PreviousSentryState)
{
}

void ABuildingGameplayActorSentry::OnRep_ExactIdleRotationForInitialization()
{
}

void ABuildingGameplayActorSentry::OnRep_FixedRotationGoalReplicated()
{
}

void ABuildingGameplayActorSentry::OnRep_ForceReplicateTargetRotation()
{
}

void ABuildingGameplayActorSentry::SetActorToTrack(AActor* InActorToTrack)
{
}

void ABuildingGameplayActorSentry::SetFixedRotationGoalForReplication(const FRotator& InFixedRotationGoal)
{
}

void ABuildingGameplayActorSentry::SetSentryState(EBuildingGameplayActorSentry_State InSentryState)
{
}

void ABuildingGameplayActorSentry::SetStartingIdleRotation(const FRotator& InStartingIdleRotation)
{
}

void ABuildingGameplayActorSentry::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorSentry, CurrentSentryState);
	DOREPLIFETIME(ABuildingGameplayActorSentry, ActorBeingTracked);
	DOREPLIFETIME(ABuildingGameplayActorSentry, ExactIdleRotationForInitialization);
	DOREPLIFETIME(ABuildingGameplayActorSentry, ForceReplicateTargetRotation);
	DOREPLIFETIME(ABuildingGameplayActorSentry, StartingIdleRotation);
	DOREPLIFETIME(ABuildingGameplayActorSentry, FixedRotationGoalReplicated);
	DOREPLIFETIME(ABuildingGameplayActorSentry, LocatingDamage_OvershootRotationDestination);
	DOREPLIFETIME(ABuildingGameplayActorSentry, LocatingDamage_RotationSpeedScalar);
}
