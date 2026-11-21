// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Environment/FortWindManager.h"
#include "FortTimeOfDayCollection.h"
#include "FortTimeOfDayData.generated.h"

USTRUCT()
struct FWorldAmbientPropertiesMatchingGameContext
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WorldAmbientPropertiesMatchingGameContext", meta=(ShowOnlyInnerProperties))
	FGameplayTagQuery QueryToMatch;

	UPROPERTY(EditDefaultsOnly, Category="WorldAmbientPropertiesMatchingGameContext", meta=(ShowOnlyInnerProperties))
	FFortTimeOfDayTheme TimeOfDayTheme;

	UPROPERTY(EditDefaultsOnly, Category="WorldAmbientPropertiesMatchingGameContext", meta=(ShowOnlyInnerProperties))
	FFortGlobalWindInfo GlobalWindInfo;

};

UCLASS(BlueprintType)
class UFortTimeOfDayData : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="World Ambient Properties")
	TArray<FWorldAmbientPropertiesMatchingGameContext> WorldAmbientPropertiesList;

};

