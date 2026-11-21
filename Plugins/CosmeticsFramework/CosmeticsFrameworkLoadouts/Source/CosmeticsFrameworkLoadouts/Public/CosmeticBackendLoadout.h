// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CosmeticBackendLoadoutSlot.h"
#include "CosmeticBackendLoadout.generated.h"

USTRUCT(BlueprintType)
struct COSMETICSFRAMEWORKLOADOUTS_API FCosmeticBackendLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticBackendLoadout")
	TArray<FCosmeticBackendLoadoutSlot> Slots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticBackendLoadout")
	FGameplayTagContainer UserTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticBackendLoadout")
	FString DisplayName;

};

