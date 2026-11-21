// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventGameplayLibrary.h"

UFortAsyncAction_GameplayCinematicComponentReady* UFortAsyncAction_GameplayCinematicComponentReady::FindGameplayCinematicComponentAsync(AController* Conroller)
{
	return nullptr;
}

void USpecialEventGameplayLibrary::AddSpecialEventKillFeedEntry(const UObject* WorldContextObject, const AFortPlayerStateAthena* VictimPlayerState, const AFortPlayerStateAthena* KillerPlayerState, const FText NonPlayerVictimName, const FText NonPlayerKillerName, const FGameplayTag& DeathCauseTag, const EDeathCauseReason DeathCauseReason, const float Distance)
{
}

void USpecialEventGameplayLibrary::AddSpecialEventRecentElimination(const FVector& Location, const AFortPlayerStateAthena* PlayerState)
{
}

bool USpecialEventGameplayLibrary::AttachPawnToComponent(AFortPawn* Pawn, USceneComponent* Component, const FName SocketName, const EAttachmentRule LocationRule, const EAttachmentRule RotationRule, const EAttachmentRule ScaleRule, const bool bWeldSimulatedBodies)
{
	return false;
}

void USpecialEventGameplayLibrary::CreateSpecialEventPlayerEliminationWorldMarker(const AFortPlayerControllerAthena* LocalController, const AFortPlayerStateAthena* VictimPlayerState, const FVector& DeathLocation)
{
}

bool USpecialEventGameplayLibrary::DetachPawn(AFortPawn* Pawn, const EDetachmentRule LocationRule, const EDetachmentRule RotationRule, const EDetachmentRule ScaleRule)
{
	return false;
}

bool USpecialEventGameplayLibrary::DetachPawnFromComponent(AFortPawn* Pawn, const USceneComponent* Component, const EDetachmentRule LocationRule, const EDetachmentRule RotationRule, const EDetachmentRule ScaleRule)
{
	return false;
}

UFortControllerComponent_GameplayCinematic* USpecialEventGameplayLibrary::FindGameplayCinematicComponent(AController* Controller)
{
	return nullptr;
}

UFortControllerComponent_SpecialEvent* USpecialEventGameplayLibrary::FindSpecialEventComponent(AController* Controller)
{
	return nullptr;
}

void USpecialEventGameplayLibrary::ForceDestroyComponents(const TArray<UActorComponent*>& Components, const bool bPromoteChildren, const FString& LogContext)
{
}

void USpecialEventGameplayLibrary::ForceUpdateGrass(UObject* WorldContextObject, const FVector Location)
{
}

bool USpecialEventGameplayLibrary::GetHasInfiniteSafeZonePhase(UObject* WorldContextObject)
{
	return false;
}

FFortAthenaLoadout USpecialEventGameplayLibrary::GetLocalPlayerLoadout(UObject* WorldContextObject)
{
	return FFortAthenaLoadout();
}

AFortAthenaMutator_SpecialEvent* USpecialEventGameplayLibrary::GetSpecialEventMutator(UObject* WorldContextObject)
{
	return nullptr;
}

FString USpecialEventGameplayLibrary::GetSpecialEventPlayerDisplayName(const AFortPlayerControllerAthena* LocalController, const AFortPlayerStateAthena* PlayerState)
{
	return FString();
}

ASpecialEventScript* USpecialEventGameplayLibrary::GetSpecialEventScript(const UObject* WorldContextObject)
{
	return nullptr;
}

void USpecialEventGameplayLibrary::HideSkydivingShadowProxy(const UObject* WorldContextObject)
{
}

void USpecialEventGameplayLibrary::SetLODOnLandscapProxies(UObject* WorldContextObject, bool bForced, int32 InLODValue)
{
}

void USpecialEventGameplayLibrary::SetNextLoadingScreen(UObject* WorldContextObject, const UAthenaLoadingScreenItemDefinition* LoadingScreenDefinition, const bool bCanShowLoadingBar)
{
}

void USpecialEventGameplayLibrary::StreamOutAllBuildingFoundations(const UObject* WorldContextObject)
{
}
