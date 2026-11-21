// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/SpecialEventHelpers.h"

void USpecialEventHelpers::GetActorsInBox(TArray<AActor*>& OutActors, const UObject* WorldContextObject, const TArray<TSubclassOf<AActor>>& ActorClasses, const FBox& SearchBox, const bool bTestActorBoundingBox, const bool bIncludeNonCollidingComponents, const bool bIncludeChildActorComponents, const bool bLog, const float DebugDrawLifeTime)
{
}

AFortAthenaMutator_SpecialRelevancy* USpecialEventHelpers::GetSpecialRelevancyMutator(const UObject* WorldContextObject)
{
	return nullptr;
}

bool USpecialEventHelpers::HasSeenEditIntro(AController* Player)
{
	return false;
}

bool USpecialEventHelpers::HasSeenForcedIntro(AController* Player)
{
	return false;
}

void USpecialEventHelpers::MarkAccountAsHavingSeenEditIntro_LocalOnly(AFortPlayerController* Controller)
{
}

void USpecialEventHelpers::MarkAccountAsHavingSeenForcedIntro(AFortPlayerController* Controller, bool bLocalOnly)
{
}
