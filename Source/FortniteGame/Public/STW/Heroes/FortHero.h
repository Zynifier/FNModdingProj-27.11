// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Items/FortPersistentTypes.h"
#include "STW/Heroes/FortWorker.h"
#include "FortHero.generated.h"

class UCustomCharacterPart;
class UFortAbilityKit;
class UFortHeroSpecialization;
class UFortHeroType;

UENUM(BlueprintType)
enum class ESpecializationType : uint8
{
	Tier1 = 0,
	Tier2 = 1,
	Tier3 = 2,
	Tier4 = 3,
	NumTiers = 4,
};

UCLASS(MinimalAPI, NotBlueprintable)
class UFortHero : public UFortWorker
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortHero", meta=(DisplayName="GetHeroType"))
	UFortHeroType* GetHeroTypeBP() const;

	UFUNCTION(BlueprintPure, Category="FortHero")
	int32 GetUnclampedLevel() const;

	UFUNCTION(BlueprintPure, Category="FortHero")
	bool IsInExpeditionSquad() const;

	UFUNCTION(BlueprintPure, Category="FortHero")
	bool IsLevelClamped() const;

	UPROPERTY(BlueprintReadOnly, Category="FortHero")
	FString hero_name;

	UPROPERTY()
	TArray<FFortSavedModeLoadout> mode_loadouts;

	UPROPERTY()
	bool refundable;

	UPROPERTY()
	TArray<FMcpVariantReader> OutfitVariants;

	UPROPERTY()
	TArray<FMcpVariantReader> BackblingVariants;

	UPROPERTY()
	TArray<TObjectPtr<UFortHeroSpecialization>> Specializations;

	UPROPERTY()
	TArray<TObjectPtr<UFortAbilityKit>> SpecializationAbilityKits;

	UPROPERTY()
	TArray<TObjectPtr<UCustomCharacterPart>> CharacterParts;

protected:
	UPROPERTY(Transient)
	TArray<FMcpVariantChannelInfo> OutfitVariantChannels;

	UPROPERTY(Transient)
	TArray<FMcpVariantChannelInfo> BackblingVariantChannels;

};

