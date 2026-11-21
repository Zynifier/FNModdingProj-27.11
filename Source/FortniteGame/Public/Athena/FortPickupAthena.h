// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "FortCapturableItemInterface.h"
#include "FortSpawnableItemInterface.h"
#include "Items/FortPickup.h"
#include "FortPickupAthena.generated.h"

class UFortGameplayTagContainer;

UCLASS(MinimalAPI)
class AFortPickupAthena : public AFortPickup, public IGameplayTagAssetInterface, public IFortSpawnableItemInterface, public IFortCapturableItemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortPickupAthena")
	bool IsValidPickup(const UFortGameplayTagContainer* InvalidGameplayTagContainer) const;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OwnedTags")
	FGameplayTagContainer StaticGameplayTags;

};

