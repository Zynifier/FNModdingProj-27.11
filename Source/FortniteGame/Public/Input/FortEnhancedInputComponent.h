// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "FortEnhancedInputComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Activation", "Components|Activation", "Activation", "Components|Activation"), meta=(BlueprintSpawnableComponent))
class UFortEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearInputActionDisplayText(const FName& MappingName, const FText& DisplayText);

	UFUNCTION(BlueprintCallable)
	void SetInputActionDisplayText(const FName& MappingName, const FText& DisplayText);

};

