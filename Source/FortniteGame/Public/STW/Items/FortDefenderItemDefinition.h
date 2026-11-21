// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/GameplayEffectApplicationInfo.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "STW/Heroes/FortCharacterType.h"
#include "FortDefenderItemDefinition.generated.h"

class AFortAIPawn;
enum class EFortDefenderSubtype : uint8;

UENUM()
enum class EFortDefenderSubtype : uint8
{
	AssaultRifle = 0,
	Pistol = 1,
	Melee = 2,
	Sniper = 3,
	Shotgun = 4,
	Invalid = 5,
};

UCLASS(MinimalAPI, BlueprintType)
class UFortDefenderItemDefinition : public UFortCharacterType
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortDefenderSubtype GetDefenderSubtype() const;

	UFUNCTION(BlueprintPure)
	FGameplayTag GetDefenderSubtypeTag() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CombinedStats")
	TArray<FGameplayEffectApplicationInfo> CombinedStatGEs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Appearance")
	FName AppearanceOverrideName;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Pawn", meta=(AssetBundles="ItemsInInventoryInZone"))
	TSoftClassPtr<AFortAIPawn> PawnClass;

};

