// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Markers/AthenaMarkerComponent.h"
#include "Net/UnrealNetwork.h"

void UAthenaMarkerComponent::CancelAllMarkers()
{
}

void UAthenaMarkerComponent::EnableCommandWheel_Implementation(bool bInEnableCommandWheel)
{
}

UFortWorldMarker* UAthenaMarkerComponent::FindMarkerByID(FMarkerID MarkerID) const
{
	return nullptr;
}

UFortWorldMarker* UAthenaMarkerComponent::FindMarkerByMarkedActor(AActor* MarkedActor)
{
	return nullptr;
}

FLinearColor UAthenaMarkerComponent::GetMarkerColor(FMarkerID MarkerID)
{
	return FLinearColor();
}

FVector UAthenaMarkerComponent::GetMarkerCurrentPosition(FMarkerID MarkerID)
{
	return FVector();
}

TArray<FMarkerID> UAthenaMarkerComponent::GetMarkerIDsByType(EFortWorldMarkerType MarkerType)
{
	return TArray<FMarkerID>();
}

void UAthenaMarkerComponent::HandleServerSquadChange(AFortPlayerStateAthena* InPlayerstate, const uint8 PreviousSquadId)
{
}

FMarkerID UAthenaMarkerComponent::MarkActorOnClient(AActor* ActorToBeMarked, const bool bIncludeSquad, const bool bUseHoveredMarkerDetail)
{
	return FMarkerID();
}

FMarkerID UAthenaMarkerComponent::MarkActorOnServer(AActor* ActorToBeMarked, const bool bIncludeSquad, const bool bUseHoveredMarkerDetail)
{
	return FMarkerID();
}

void UAthenaMarkerComponent::OnPingCommandDeclined_Implementation(FMarkerID MarkerID, bool bPlayUnableToPerformAction)
{
}

void UAthenaMarkerComponent::OnRep_MarkerStream()
{
}

void UAthenaMarkerComponent::OnTimelineScrubbed()
{
}

void UAthenaMarkerComponent::PlayMarkerConfirmationSound_Implementation(int32 InPlayerId, FMarkerID InMarkerID)
{
}

void UAthenaMarkerComponent::ServerAddMapMarker_Implementation(FFortClientMarkerRequest MarkerRequest)
{
}

void UAthenaMarkerComponent::ServerRemoveMapMarker_Implementation(FMarkerID MarkerID, ECancelMarkerReason CancelReason)
{
}

void UAthenaMarkerComponent::ServerSetMapMarkerConfirmation_Implementation(const FMarkerID& MarkerID, const int32 InPlayerId, const FLinearColor InPinColor, const bool bWasConfirmed)
{
}

void UAthenaMarkerComponent::SetMarkerActorClass(TSubclassOf<AFortPlayerMarkerBase> InMarkerActorClass)
{
}

void UAthenaMarkerComponent::SetMarkerWidgetClass(TSubclassOf<UUserWidget> InMarkerClass)
{
}

void UAthenaMarkerComponent::UnmarkActorOnClient(FMarkerID MarkerID)
{
}

void UAthenaMarkerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAthenaMarkerComponent, MarkerStream);
}

void UAthenaMarkerComponentLibrary::ActivateAllMarkerComponents(UObject* WorldContextObject)
{
}

void UAthenaMarkerComponentLibrary::DeactivateAllMarkerComponents(UObject* WorldContextObject)
{
}

void UAthenaMarkerComponentLibrary::DeactivateMarkersOnActor(AActor* ActorToRemoveMarkersFrom)
{
}
