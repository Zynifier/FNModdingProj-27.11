// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/CreativeQuickbarComponent.h"

void UCreativeQuickbarComponent::ActivateQuickbarSlot_Implementation(int32 SlotIndex)
{
}

void UCreativeQuickbarComponent::ClientAddToQuickBarComplete_Implementation(const int32 SlotPutIn, FGuid ItemGuid, const UFortItemDefinition* Playset, bool UseDelayedAddToQuickbar, bool bUseVolumeToSpawn)
{
}

void UCreativeQuickbarComponent::ExecuteDelayedAddItemToMoveTool(const UFortItemDefinition* ItemDefinition, bool bUseVolume)
{
}

void UCreativeQuickbarComponent::ExecuteDelayedAddItemToQuickbar(const UFortItemDefinition* ItemDefinition, const int32 DesiredSlotIndex, bool bUseVolumeToSpawn)
{
}

void UCreativeQuickbarComponent::HandleCreativeQuickbarPressed_Implementation(int32 SlotIndex)
{
}

void UCreativeQuickbarComponent::HandleCreativeQuickbarReleased_Implementation(int32 SlotIndex)
{
}

void UCreativeQuickbarComponent::HandleInputMethodChanged(ECommonInputType CurrentInputType)
{
}

void UCreativeQuickbarComponent::HandleMoveToolInteractionEnded()
{
}

void UCreativeQuickbarComponent::HandleMoveToolInteractionStarted(UObjectInteractionBehavior* InteractionMode)
{
}

void UCreativeQuickbarComponent::HandleQuickbarClutchPressed_Implementation()
{
}

void UCreativeQuickbarComponent::HandleQuickbarClutchReleased_Implementation()
{
}

void UCreativeQuickbarComponent::HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

bool UCreativeQuickbarComponent::IsQuickbarActive() const
{
	return false;
}

void UCreativeQuickbarComponent::PopulateQuickbarSlotFromSelection_Implementation(int32 SlotIndex)
{
}

void UCreativeQuickbarComponent::ServerAddItemToQuickBar_Implementation(const UFortItemDefinition* ItemDefinition, const int32 DesiredSlotIndexconst, FGuid PreviousItemGuid, bool bUseVolumeToSpawn)
{
}
bool UCreativeQuickbarComponent::ServerAddItemToQuickBar_Validate(const UFortItemDefinition* ItemDefinition, const int32 DesiredSlotIndexconst, FGuid PreviousItemGuid, bool bUseVolumeToSpawn)
{
	return true;
}

void UCreativeQuickbarComponent::ServerAddToQuickBar_Implementation(const TArray<AActor*>& Actors, const int32 DesiredSlotIndex)
{
}
bool UCreativeQuickbarComponent::ServerAddToQuickBar_Validate(const TArray<AActor*>& Actors, const int32 DesiredSlotIndex)
{
	return true;
}

void UCreativeQuickbarComponent::SetIsQuickbarEquipped(bool bIsEquipped)
{
}
