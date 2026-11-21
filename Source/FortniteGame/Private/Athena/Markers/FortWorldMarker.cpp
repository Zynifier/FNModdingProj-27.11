// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Markers/FortWorldMarker.h"
#include "UObject/Class.h"

bool FMarkerID::operator==(const FMarkerID& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FMarkerID& Value)
{
	return 0;
}

void UFortWorldMarker::ActorDestroyed(AActor* DestroyedActor)
{
}

void UFortWorldMarker::CancelMarker()
{
}

UUserWidget* UFortWorldMarker::GetMarkerWidget() const
{
	return nullptr;
}

void UFortWorldMarker::PickedUp(AFortPickup* SelfActor, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* WorldItemDefinition, FVector PickupLocation)
{
}

void UFortWorldMarker::PlayerStateDestroyed(AActor* DestroyedActor)
{
}

bool UFortWorldMarker::ToggleMarkerConfirmation(int32 InPlayerId, FLinearColor InPinColor)
{
	return false;
}
