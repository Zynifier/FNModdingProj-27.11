// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_HUDElementVisibility.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_HUDElementVisibility::MulticastAddVisibilityModData_Implementation(const EFortHUDElementVisibiltyPriority Priority, const FHUDElementVisibilityRepData VisibilityData)
{
}

void AFortAthenaMutator_HUDElementVisibility::MulticastClearVisibilityModData_Implementation()
{
}

void AFortAthenaMutator_HUDElementVisibility::MulticastRemoveVisibilityModData_Implementation(const EFortHUDElementVisibiltyPriority Priority, const FHUDElementVisibilityRepData VisibilityData)
{
}

void AFortAthenaMutator_HUDElementVisibility::MulticastUpdateVisibilityModData_Implementation(const FHUDElementVisibilityRepData UpdatedVisibilityData)
{
}

void AFortAthenaMutator_HUDElementVisibility::OnClientEnteredVolume(APlayerState* Client, AFortVolume* Volume)
{
}

void AFortAthenaMutator_HUDElementVisibility::OnClientPlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode)
{
}

void AFortAthenaMutator_HUDElementVisibility::OnCreativeLinkedVolumeChangedForPC(AFortVolume* Volume)
{
}

void AFortAthenaMutator_HUDElementVisibility::OnMinigameSetUp(AFortMinigame* Minigame)
{
}

void AFortAthenaMutator_HUDElementVisibility::OnRep_PriorityStacksRepData()
{
}

void AFortAthenaMutator_HUDElementVisibility::OnVolumePlaysetChanged(const UFortPlaysetItemDefinition* PlaysetItemDef)
{
}

int32 AFortAthenaMutator_HUDElementVisibility::RequestVisibilityModSourceID() const
{
	return int32();
}

void AFortAthenaMutator_HUDElementVisibility::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_HUDElementVisibility, PriorityStacksRepData);
}
