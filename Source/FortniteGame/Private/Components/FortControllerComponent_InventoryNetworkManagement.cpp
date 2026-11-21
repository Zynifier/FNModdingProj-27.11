// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_InventoryNetworkManagement.h"

void UFortControllerComponent_InventoryNetworkManagement::ServerSwapItem_Implementation(UObject* SourceOwner, UObject* TargetOwner, FGuid ItemGuid, int32 Count)
{
}
bool UFortControllerComponent_InventoryNetworkManagement::ServerSwapItem_Validate(UObject* SourceOwner, UObject* TargetOwner, FGuid ItemGuid, int32 Count)
{
	return true;
}

void UFortControllerComponent_InventoryNetworkManagement::ServerSwapItems_Implementation(UObject* SourceOwner, UObject* TargetOwner, const TArray<FItemGuidAndCount>& ItemGuids)
{
}
bool UFortControllerComponent_InventoryNetworkManagement::ServerSwapItems_Validate(UObject* SourceOwner, UObject* TargetOwner, const TArray<FItemGuidAndCount>& ItemGuids)
{
	return true;
}
