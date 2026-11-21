// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemTier.h"
#include "STW/Heroes/FortHeroSpecialization.h"
#include "FortPerks.generated.h"

class UFortHero;
class UFortHeroSpecialization;

UENUM(BlueprintType)
enum class EFortPerksWidgetState : uint8
{
	Normal = 0,
	Upgrade = 1,
	Evolution = 2,
};

USTRUCT(BlueprintType)
struct FFortUIPerk
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortUIPerk")
	FFortSpecializationSlot SpecializationSlot;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerk")
	TObjectPtr<UFortHero> Hero;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerk")
	EFortItemTier Tier;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerk")
	EFortSupportBonusType SupportBonusType;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerk")
	bool bIsTierPerk;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerk")
	bool bIsUpgrade;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerk")
	bool bIsEvolution;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerk")
	bool bIsEvolutionBranch;

};

USTRUCT(BlueprintType)
struct FFortUIPerkTier
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortUIPerkTier")
	TObjectPtr<UFortHeroSpecialization> HeroSpecialization;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerkTier")
	TObjectPtr<UFortHero> CurrentHero;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerkTier")
	EFortItemTier Tier;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerkTier")
	bool bIsUpgrade;

	UPROPERTY(BlueprintReadOnly, Category="FortUIPerkTier")
	bool bIsEvolution;

};

