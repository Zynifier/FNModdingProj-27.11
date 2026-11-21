// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDTargetUnderReticleInterface.generated.h"

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UFortHUDTargetUnderReticleInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortHUDTargetUnderReticleInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="HUDTarget")
	virtual float GetHUDTargetDifficultyRating() const;

	UFUNCTION(BlueprintCallable, Category="HUDTarget")
	virtual TArray<FText> GetHUDTargetDisplayModifiers() const;

	UFUNCTION(BlueprintCallable, Category="HUDTarget")
	virtual FText GetHUDTargetDisplayName() const;

	UFUNCTION(BlueprintCallable, Category="HUDTarget")
	virtual float GetHUDTargetHealthPercentage() const;

	UFUNCTION(BlueprintCallable, Category="HUDTarget")
	virtual FText GetHUDTargetUpgradeDisplayName() const;

};

