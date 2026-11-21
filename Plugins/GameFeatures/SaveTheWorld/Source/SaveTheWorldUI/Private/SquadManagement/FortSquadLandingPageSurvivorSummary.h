// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CommonUserWidget.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "FortSquadLandingPageSurvivorSummary.generated.h"

class UFortSquadStatValueWithIcon;

USTRUCT(BlueprintType)
struct FFortAttributeModifierAccumulation
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Accumulation")
	FGameplayTag GameplayTag;

	UPROPERTY(BlueprintReadOnly, Category="Accumulation")
	FGameplayAttribute Attribute;

	UPROPERTY(BlueprintReadOnly, Category="Accumulation")
	TEnumAsByte<EGameplayModOp::Type> ModifierOp;

	UPROPERTY(BlueprintReadOnly, Category="Accumulation")
	float Magnitude;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadLandingPageSurvivorSummary : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="SetBonusLineItems")
	void HandleAddSetBonusSummaryLineItemBP(FFortAttributeModifierAccumulation AttributeModifierAccumulation);

	UFUNCTION(BlueprintImplementableEvent, Category="SetBonusLineItems")
	void HandleClearSetBonusSummaryLineItemsBP();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStats", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadStatValueWithIcon> FortitudeStatValue;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStats", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadStatValueWithIcon> OffenseStatValue;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStats", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadStatValueWithIcon> ResistanceStatValue;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStats", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadStatValueWithIcon> TechStatValue;

};

