// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Building/BuildingTypes.h"
#include "FortCreativeCostComponent.generated.h"

class AFortPawn;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCreativeCostComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Cost")
	void ClearCosts();

	UFUNCTION(BlueprintPure, Category="Cost")
	const TArray<int32>& GetItemCosts() const;

	UFUNCTION(BlueprintPure, Category="Cost")
	bool PassesCostCheck(const AFortPawn* Pawn) const;

	UFUNCTION(BlueprintCallable, Category="Cost")
	void SetItemResourceCost(const EFortResourceType::Type ResourceType, const int32 Cost);

	UFUNCTION(BlueprintPure, Category="Cost")
	bool TakeWorldResourcesFromPlayer(AFortPawn* Pawn) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Cost")
	bool bShowCostInInteractionIndicator;

protected:
	UPROPERTY(Replicated)
	TArray<int32> ItemCosts;

};

