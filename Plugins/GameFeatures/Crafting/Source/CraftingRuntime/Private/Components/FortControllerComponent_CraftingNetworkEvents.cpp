// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_CraftingNetworkEvents.h"

void UFortControllerComponent_CraftingNetworkEvents::ClientNotifyCraftingFailed_Implementation(AActor* CraftingObject, const FGameplayTagContainer& FailedReason, FCraftingMultiKey Key)
{
}

void UFortControllerComponent_CraftingNetworkEvents::ClientNotifyCraftingSuccess_Implementation(AActor* CraftingObject, const FName& FormulaRowName, FCraftingMultiKey Key)
{
}

void UFortControllerComponent_CraftingNetworkEvents::NotifyCraftingSuccess(AActor* CraftingObject, const FName& FormulaRowName, FCraftingMultiKey Key)
{
}

void UFortControllerComponent_CraftingNetworkEvents::ServerCancelCrafting_Implementation(AActor* CraftingObject, FCraftingMultiKey Key)
{
}
bool UFortControllerComponent_CraftingNetworkEvents::ServerCancelCrafting_Validate(AActor* CraftingObject, FCraftingMultiKey Key)
{
	return true;
}

void UFortControllerComponent_CraftingNetworkEvents::ServerClaimCraftingResults_Implementation(AActor* CraftingObject, FCraftingMultiKey Key)
{
}
bool UFortControllerComponent_CraftingNetworkEvents::ServerClaimCraftingResults_Validate(AActor* CraftingObject, FCraftingMultiKey Key)
{
	return true;
}

void UFortControllerComponent_CraftingNetworkEvents::ServerEjectItems_Implementation(AActor* CraftingObject)
{
}
bool UFortControllerComponent_CraftingNetworkEvents::ServerEjectItems_Validate(AActor* CraftingObject)
{
	return true;
}

void UFortControllerComponent_CraftingNetworkEvents::ServerPauseCrafting_Implementation(AActor* CraftingObject, bool bDecayPausedTime, FCraftingMultiKey Key)
{
}
bool UFortControllerComponent_CraftingNetworkEvents::ServerPauseCrafting_Validate(AActor* CraftingObject, bool bDecayPausedTime, FCraftingMultiKey Key)
{
	return true;
}

void UFortControllerComponent_CraftingNetworkEvents::ServerPickupItemAndStartCrafting_Implementation(AActor* CraftingObject, AFortPickup* Pickup, const FName& CraftingFormulaName, FCraftingMultiKey Key)
{
}
bool UFortControllerComponent_CraftingNetworkEvents::ServerPickupItemAndStartCrafting_Validate(AActor* CraftingObject, AFortPickup* Pickup, const FName& CraftingFormulaName, FCraftingMultiKey Key)
{
	return true;
}

void UFortControllerComponent_CraftingNetworkEvents::ServerReportCraftingSuccess_Implementation(AActor* CraftingObject, FCraftingMultiKey Key)
{
}
bool UFortControllerComponent_CraftingNetworkEvents::ServerReportCraftingSuccess_Validate(AActor* CraftingObject, FCraftingMultiKey Key)
{
	return true;
}

void UFortControllerComponent_CraftingNetworkEvents::ServerResumeCrafting_Implementation(AActor* CraftingObject, FCraftingMultiKey Key)
{
}
bool UFortControllerComponent_CraftingNetworkEvents::ServerResumeCrafting_Validate(AActor* CraftingObject, FCraftingMultiKey Key)
{
	return true;
}

void UFortControllerComponent_CraftingNetworkEvents::ServerStartCrafting_Implementation(AActor* CraftingObject, const FName& CraftingFormulaName, const int32 NumberToCraft, FCraftingMultiKey Key)
{
}
bool UFortControllerComponent_CraftingNetworkEvents::ServerStartCrafting_Validate(AActor* CraftingObject, const FName& CraftingFormulaName, const int32 NumberToCraft, FCraftingMultiKey Key)
{
	return true;
}
