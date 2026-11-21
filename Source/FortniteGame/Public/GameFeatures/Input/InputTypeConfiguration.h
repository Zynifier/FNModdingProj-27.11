// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "InputTypeConfiguration.generated.h"

class APlayerController;
class UPlayerMappableInputConfig;

UCLASS(Config=Game, MinimalAPI)
class UInputTypeConfiguration : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="InputTypeConfiguration")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="InputTypeConfiguration")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, Category="InputTypeConfiguration")
	TSoftClassPtr<APlayerController> InputReceiver;

	UPROPERTY(EditDefaultsOnly, Category="InputTypeConfiguration")
	TSoftObjectPtr<UPlayerMappableInputConfig> Config;

	UPROPERTY(EditDefaultsOnly, Category="InputTypeConfiguration", meta=(Bitmask, BitmaskEnum="/Script/CommonInput.ECommonInputType"))
	uint8 InputTypes;

	UPROPERTY(EditDefaultsOnly, Category="InputTypeConfiguration")
	FGameplayTagContainer DependentPlatformTraits;

	UPROPERTY(EditDefaultsOnly, Category="InputTypeConfiguration")
	FGameplayTagContainer ExcludedPlatformTraits;

	UPROPERTY(EditDefaultsOnly, Category="InputTypeConfiguration")
	bool bShouldActivateAutomatically;

	UPROPERTY(Config)
	TArray<FName> DefaultAutomaticActivationEvents;

	UPROPERTY(EditDefaultsOnly, Category="InputTypeConfiguration", meta=(EditCondition="!bShouldActivateAutomatically", EditConditionHides))
	FGameplayTagContainer ActivationEvents;

};

