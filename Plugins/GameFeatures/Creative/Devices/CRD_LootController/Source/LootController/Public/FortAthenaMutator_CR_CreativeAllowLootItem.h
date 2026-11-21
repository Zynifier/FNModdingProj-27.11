// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_CR_CreativeAllowLootItem.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CR_CreativeAllowLootItem : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetItemGameplayTagsNotAllowed(const FGameplayTagContainer& InItemGameplayTagsNotAllowed);

protected:
	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_CR_CreativeAllowLootItem")
	FGameplayTagContainer ItemGameplayTagsNotAllowed;

};

