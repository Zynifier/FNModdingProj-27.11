// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "CosmeticsGatingRule.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UCosmeticsGatingRule : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Cosmetics")
	FGameplayTagQuery GatingRequirementQuery;

};

