// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortMappingContextOverlapFilter.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortMappingContextOverlapFilter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMappingContextOverlapFilter", meta=(Categories="Input.Context"))
	FGameplayTag MappingContextTag;

	UPROPERTY(EditAnywhere, Category="FortMappingContextOverlapFilter", meta=(Categories="Input.Context"))
	FGameplayTagContainer OverlappingMappingContexts;

};

