// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "InfiltrationSelectedPerksWidget.generated.h"

class AFortAthenaMutator_Infiltration;
class UFortSpyTechItemDefinition;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UInfiltrationSelectedPerksWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePerks();

	UPROPERTY()
	TWeakObjectPtr<AFortAthenaMutator_Infiltration> CachedMutator;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationSelectedPerksWidget")
	TArray<TObjectPtr<UFortSpyTechItemDefinition>> CurrentDisplayedPerks;

	UPROPERTY(EditAnywhere, Category="InfiltrationSelectedPerksWidget")
	FGameplayTag FilterTag;

};

