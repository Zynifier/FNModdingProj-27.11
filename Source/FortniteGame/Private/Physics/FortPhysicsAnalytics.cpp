// Copyright Epic Games, Inc. All Rights Reserved.

#include "Physics/FortPhysicsAnalytics.h"

EDamageCauserType UFortPhysicsAnalytics::CategorizeByDamageCauser(AActor* DamageCauser, const FGameplayTagContainer& DamageTags)
{
	return EDamageCauserType();
}

void UFortPhysicsAnalytics::FireTelemetryEvent_OnPhysicsFellableDestroyed(AFortPlayerController* FortPC, AActor* FellableActor, AActor* DamageCauser, const FGameplayTagContainer& DamageTags, const bool bFallTowardsEnemy)
{
}

void UFortPhysicsAnalytics::FireTelemetryEvent_OnPhysicsRidingActorLifeEnd(ABuildingActor* PhysicsActor, const int32 NumberOfCachedPlayers, TArray<FVector> OnBoardLocations, TArray<FVector> OffBoardLocations, TArray<float> SessionLengths)
{
}

void UFortPhysicsAnalytics::FireTelemetryEvent_OnPhysicsSnowballDestroyed(ABuildingActor* SnowballActor, AController* Killer, const EDamageCauserType DamageCauserType)
{
}
