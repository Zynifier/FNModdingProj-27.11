// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectUIData.h"
#include "FortGameplayEffectUIData.generated.h"

UCLASS()
class UFortGameplayEffectUIData : public UGameplayEffectUIData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FString TooltipName;

};

