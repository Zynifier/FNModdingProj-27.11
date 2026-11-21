// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputMappingContext.h"
#include "Input/FortMappingContextOverlapFilter.h"
#include "FortInputMappingContext.generated.h"

UCLASS(Config=Game, MinimalAPI)
class UFortInputMappingContext : public UInputMappingContext
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortInputMappingContext")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="FortInputMappingContext")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, Category="FortInputMappingContext", meta=(Categories="Settings.Input.Category"))
	FGameplayTag CategoryTag;

	UPROPERTY(EditDefaultsOnly, Category="FortInputMappingContext")
	FFortMappingContextOverlapFilter MappingContextOverlapFilter;

	UPROPERTY(Config)
	TArray<FName> DefaultAutomaticActivationEvents;

	UPROPERTY(VisibleAnywhere, Category="FortInputMappingContext")
	FGameplayTagContainer ActivationEvents;

};

