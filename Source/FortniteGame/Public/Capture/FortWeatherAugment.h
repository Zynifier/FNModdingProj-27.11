// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Capture/FortCarriedObject.h"
#include "FortWeatherAugment.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AFortWeatherAugment : public AFortCarriedObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Tags")
	const FGameplayTagContainer& GetWeatherTags() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags")
	FGameplayTagContainer WeatherTags;

};

