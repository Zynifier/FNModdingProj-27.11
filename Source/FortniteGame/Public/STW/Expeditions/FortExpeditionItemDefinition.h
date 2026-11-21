// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortItemAndCount.h"
#include "FortRarityEnum.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortExpeditionItemDefinition.generated.h"

class UFortCardPackItemDefinition;

USTRUCT(BlueprintType)
struct FFortCriteriaRequirementData : public FTableRowBase
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="FortCriteriaRequirementData")
	FString RequiredTagString;
#endif

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortCriteriaRequirementData", meta=(DataTableImportOptional))
	FGameplayTag RequiredTag;

	UPROPERTY(VisibleAnywhere, Category="CriteriaData")
	bool bGlobalMod;

	UPROPERTY(VisibleAnywhere, Category="CriteriaData")
	float ModValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CriteriaData")
	bool bRequireRarity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CriteriaData")
	EFortRarity RequiredRarity;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortExpeditionItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Expedition")
	void GetAllRewards(TArray<UFortCardPackItemDefinition*>& OutRewards);

	UFUNCTION(BlueprintPure, Category="Expedition")
	void GetExpeditionCosts(TArray<FItemAndCount>& OutExpeditionCosts) const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	FGameplayTagContainer GetRequiredTags() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Expedition")
	FString CriteriaRequirementsLootTier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Expedition")
	float ExpeditionDuration_Minutes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Expedition")
	float ExpeditionExpirationDuration_Minutes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Expedition")
	int32 BaseTargetPowerRating;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Expedition")
	int32 TierFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Expedition")
	int32 MaxTargetPowerClamp;

private:
	UPROPERTY(EditAnywhere, Category="Expedition")
	FDataTableRowHandle ExpeditionRules;

};

