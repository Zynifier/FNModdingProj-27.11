// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortActorOptionsComponent.h"
#include "Net/UnrealNetwork.h"

bool UFortActorOptionsComponent::BlueprintGetInteractionTime_Implementation(const AFortPawn* InteractingPawn, float& OutInteractionTime) const
{
	return false;
}

bool UFortActorOptionsComponent::CanEditOptionsComponent(AFortPawn* InteractingPawn)
{
	return false;
}

bool UFortActorOptionsComponent::GetPropertyOverrides(TMap<FString, FString>& CurrentOptions) const
{
	return false;
}

void UFortActorOptionsComponent::HandlePlaylistLoadedForLocalization(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

FCurveTableRowHandle UFortActorOptionsComponent::K2_GetInteractionSpeed() const
{
	return FCurveTableRowHandle();
}

FText UFortActorOptionsComponent::K2_GetInteractionText() const
{
	return FText();
}

FText UFortActorOptionsComponent::K2_GetOptionsDescription() const
{
	return FText();
}

FText UFortActorOptionsComponent::K2_GetOptionsDisplayName() const
{
	return FText();
}

const UPlaylistUserOptions* UFortActorOptionsComponent::K2_GetPlayerOptions() const
{
	return nullptr;
}

bool UFortActorOptionsComponent::OnLocalInteract(AFortPlayerPawn* InteractingPawn)
{
	return false;
}

void UFortActorOptionsComponent::OnRep_PlayerOptionData()
{
}

void UFortActorOptionsComponent::RefreshPropertyOverrides()
{
}

void UFortActorOptionsComponent::RemovePropertyOverrides(const TArray<FString>& Options)
{
}

void UFortActorOptionsComponent::ResolvePendingRepOverrides()
{
}

bool UFortActorOptionsComponent::SetPropertyOverrides(const TMap<FString, FString>& NewOptions)
{
	return false;
}

bool UFortActorOptionsComponent::SetPropertyOverrideValues(const TMap<FString, FString>& NewOptions)
{
	return false;
}

void UFortActorOptionsComponent::TryToLocalizeStrings()
{
}

void UFortActorOptionsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortActorOptionsComponent, PlayerOptionData);
}
