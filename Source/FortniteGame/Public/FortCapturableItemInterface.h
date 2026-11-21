// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItemEntry.h"
#include "FortCapturableItemInterface.generated.h"

class ABuildingActor;
class AFortPawn;
class UFortGameplayTagContainer;

UINTERFACE(MinimalAPI, BlueprintType)
class UFortCapturableItemInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortCapturableItemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CapturableItemInterface")
	bool CanBeAddedToCaptureList(const UFortGameplayTagContainer* InvalidGameplayTagContainer) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CapturableItemInterface")
	bool CanBeCaptured(const UFortGameplayTagContainer* InvalidGameplayTagContainer, ABuildingActor* InBuildingActor) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CapturableItemInterface")
	TArray<FFortItemEntry> GetCaptureItemEntries() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CapturableItemInterface")
	AFortPawn* GetPawnTryingToCaptureItem() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CapturableItemInterface")
	void OnAddedToCaptureList();

};

