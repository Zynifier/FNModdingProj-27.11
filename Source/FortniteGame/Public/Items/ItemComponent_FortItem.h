// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemComponentBase.h"
#include "ItemComponent_FortItem.generated.h"

UCLASS(HideDropdown)
class UItemComponent_FortItem : public UItemComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Fort Component")
	const FGameplayTagContainer& GetAutomationTags() const;

	UFUNCTION(BlueprintPure, Category="Fort Component")
	const FGameplayTagContainer& GetGameplayTags() const;

private:
	UPROPERTY(Transient)
	FGameplayTagContainer GameplayTags;

	UPROPERTY(Transient)
	FGameplayTagContainer AutomationTags;

};

