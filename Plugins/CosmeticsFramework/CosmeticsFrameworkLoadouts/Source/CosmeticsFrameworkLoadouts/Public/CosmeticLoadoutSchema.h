// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CosmeticLoadoutSchema.generated.h"

class UCosmeticLoadoutSlotTemplate;

UCLASS(MinimalAPI, NotBlueprintable)
class UCosmeticLoadoutSchema : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="CosmeticLoadoutSchema")
	TArray<TObjectPtr<UCosmeticLoadoutSlotTemplate>> Slots;

};

