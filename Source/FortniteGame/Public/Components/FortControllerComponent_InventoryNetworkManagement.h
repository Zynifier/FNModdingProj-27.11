// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Components/FortControllerComponent.h"
#include "FortItemAndCount.h"
#include "FortControllerComponent_InventoryNetworkManagement.generated.h"

class UObject;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_InventoryNetworkManagement : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerSwapItem(UObject* SourceOwner, UObject* TargetOwner, FGuid ItemGuid, int32 Count);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerSwapItems(UObject* SourceOwner, UObject* TargetOwner, const TArray<FItemGuidAndCount>& ItemGuids);

};

