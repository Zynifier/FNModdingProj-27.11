// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotHealingSkillSet.generated.h"

USTRUCT()
struct FFortBotDigestedHealingItems
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float UseItemResourceThreshold;

	UPROPERTY(Transient)
	FGameplayTagContainer ItemTags;

};

USTRUCT()
struct FFortBotDigestedHealingItemsList
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FFortBotDigestedHealingItems> HealthItems;

};

USTRUCT()
struct FFortBotDigestedHealingItemsSpec
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FGameplayTagQuery TagQuery;

	UPROPERTY(Transient)
	FFortBotDigestedHealingItemsList HealthItemsList;

};

USTRUCT()
struct FFortBotHealingItems
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortBotHealingItems", meta=(AllowPrivateAccess="true"))
	FScalableFloat UseItemResourceThreshold;

	UPROPERTY(EditDefaultsOnly, Category="FortBotHealingItems", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer ItemTags;

};

USTRUCT()
struct FFortBotHealingItemsList
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortBotHealingItemsList", meta=(AllowPrivateAccess="true"))
	TArray<FFortBotHealingItems> HealthItems;

};

USTRUCT()
struct FFortBotHealingItemsSpec
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortBotHealingItemsSpec", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortBotHealingItemsSpec", meta=(AllowPrivateAccess="true"))
	FFortBotHealingItemsList HealthItemsList;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotHealingDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FFortBotDigestedHealingItemsList HealthItemsList;

	UPROPERTY(Transient)
	TArray<FFortBotDigestedHealingItemsSpec> HealthItemsSpecializations;

	UPROPERTY(Transient)
	FFortBotDigestedHealingItemsList ShieldItemsList;

	UPROPERTY(Transient)
	TArray<FFortBotDigestedHealingItemsSpec> ShieldItemsSpecializations;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotHealingSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Healing Items", meta=(AllowPrivateAccess="true"))
	FFortBotHealingItemsList HealthItemsList;

	UPROPERTY(EditDefaultsOnly, Category="Healing Items", meta=(AllowPrivateAccess="true"))
	TArray<FFortBotHealingItemsSpec> HealthItemsSpecializations;

	UPROPERTY(EditDefaultsOnly, Category="Healing Items", meta=(AllowPrivateAccess="true"))
	FFortBotHealingItemsList ShieldItemsList;

	UPROPERTY(EditDefaultsOnly, Category="Healing Items", meta=(AllowPrivateAccess="true"))
	TArray<FFortBotHealingItemsSpec> ShieldItemsSpecializations;

};

