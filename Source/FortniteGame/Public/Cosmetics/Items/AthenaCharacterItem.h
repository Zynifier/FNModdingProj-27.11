// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Items/FortAccountItem.h"
#include "AthenaCharacterItem.generated.h"

class UFortHero;

UCLASS(MinimalAPI)
class UAthenaCosmeticAccountItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Cosmetics")
	UFortHero* GetHero() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	virtual FText GetLockerDescriptionText() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	virtual FText GetLockerItemTypeText() const;

	UFUNCTION(BlueprintPure)
	bool HasCosmeticVariance() const;

	UFUNCTION(BlueprintCallable)
	bool HasMultipleVariants();

protected:
	UPROPERTY(Transient)
	TArray<FMcpVariantChannelInfo> VariantChannels;

	UPROPERTY(Transient)
	TArray<FMcpVariantChannelInfo> ActiveVariantOverrides;

	UPROPERTY()
	TArray<FMcpVariantReader> Variants;

private:
	UPROPERTY()
	TObjectPtr<UFortHero> Hero;

};

UCLASS(MinimalAPI)
class UAthenaCharacterItem : public UAthenaCosmeticAccountItem
{
	GENERATED_BODY()

};

