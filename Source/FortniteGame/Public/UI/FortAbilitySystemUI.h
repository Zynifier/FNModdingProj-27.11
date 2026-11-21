// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "UObject/NoExportTypes.h"
#include "Items/FortAttributeLookupTable.h"
#include "FortAbilitySystemUI.generated.h"

class UGameplayEffect;

UENUM(BlueprintType)
enum class EFortStatDisplayType : uint8
{
	Category = 0,
	Buff = 1,
	Debuff = 2,
	Neutral = 3,
	DoNotDisplay = 4,
};

USTRUCT(BlueprintType)
struct FFortGameplayEffectModifierDescription
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayAttribute ModAttribute;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayEffectModifierDescription")
	FText ModDescription;

	UPROPERTY()
	bool bIsBuff;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayEffectModifierDescription")
	TEnumAsByte<EFortAttributeDisplay::Type> MagnitudeFormat;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayEffectModifierDescription")
	EFortStatDisplayType DisplayType;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayEffectModifierDescription")
	float Magnitude;

};

USTRUCT(BlueprintType)
struct FFortGameplayEffectDescription
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortGameplayEffectDescription")
	FText EffectDisplayName;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayEffectDescription")
	FText EffectWrittenDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayEffectDescription")
	TArray<FFortGameplayEffectModifierDescription> ModDescriptions;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayEffectDescription")
	TArray<FText> GrantedTagDescriptions;

};

UCLASS(MinimalAPI)
class UFortAbilitySystemUI : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Effects")
	static UGameplayEffect* GetDefaultObjectOfGameplayEffectType(TSubclassOf<UGameplayEffect> EffectType);

	UFUNCTION(BlueprintCallable, Category="Effects")
	static FFortGameplayEffectDescription GetStaticGameplayEffectDescription(const UGameplayEffect* Effect, float Level);

};

