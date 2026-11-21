// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/PrimaryAssetId.h"
#include "FortItemToBuildingGameplayActorPickupMapping.generated.h"

class ABuildingGameplayActor;

UCLASS()
class UFortItemToBuildingGameplayActorPickupMapping : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortItemToBuildingGameplayActorPickupMapping")
	TMap<FPrimaryAssetId, TSoftClassPtr<ABuildingGameplayActor>> ItemToBGAMap;

};

