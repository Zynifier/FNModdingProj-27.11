// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingProp_CaptureArea.h"

void ABuildingProp_CaptureArea::BindOrUnbindOnPlayerTeamReplicated(AFortPlayerState* PlayerState, bool bBind)
{
}

void ABuildingProp_CaptureArea::BindToControllerInventoryChangedEvent(AFortPlayerController* PlayerController)
{
}

int32 ABuildingProp_CaptureArea::CaptureItemsFromPickup(const TArray<FItemVariantHandle>& ItemsToCapture, AFortPickup* Pickup, int32& AddedScore)
{
	return int32();
}

int32 ABuildingProp_CaptureArea::CaptureItemsFromPlayer(bool bRemoveOnFound, const TArray<FItemVariantHandle>& ItemsToCapture, AFortPlayerController* PlayerController, int32 AmountToRemove, int32& AddedScore)
{
	return int32();
}

void ABuildingProp_CaptureArea::GetCaptureIconData_Implementation(FCaptureIconData& OutCaptureIconData) const
{
}

void ABuildingProp_CaptureArea::OnFortPawnRegisteredInsideAreaDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void ABuildingProp_CaptureArea::OnPlayerChangedTeam(AFortPlayerState* PlayerState, uint8 NewTeam, uint8 OldTeam, bool bTeamChangedWithoutRespawn)
{
}

void ABuildingProp_CaptureArea::RegisterPlayerInsideArea(AFortPlayerController* PlayerInside)
{
}

void ABuildingProp_CaptureArea::RemoveItemsFromPlayer(const TArray<FItemVariantHandle>& ItemsToCapture, AFortPlayerController* PlayerController)
{
}

void ABuildingProp_CaptureArea::UnbindAllControllersToInventoryChangedEvent()
{
}

void ABuildingProp_CaptureArea::UnbindToControllerInventoryChangedEvent(AFortPlayerController* PlayerController)
{
}

void ABuildingProp_CaptureArea::UnregisterAllRegisteredPlayerInsideArea()
{
}

void ABuildingProp_CaptureArea::UnregisterPlayerInsideArea(AFortPlayerController* OldPlayerInside)
{
}
