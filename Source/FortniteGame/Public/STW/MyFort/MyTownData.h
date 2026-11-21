// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortGender.h"
#include "MyTownData.generated.h"

class UFortCurrencyItemDefinition;
class UFortItemIconDefinition;
class UFortPersistentResourceItemDefinition;
class UFortTokenType;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct FMyTownWorkerPortraitData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftObjectPtr<UFortItemIconDefinition> Portrait;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 SelectionWeight;

};

USTRUCT(BlueprintType)
struct FMyTownWorkerGenderData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 SelectionWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TArray<FMyTownWorkerPortraitData> PotraitData;

};

USTRUCT(BlueprintType)
struct FMyTownWorkerPersonalityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FGameplayTagContainer PersonalityTypeTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FText PersonalityName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 SelectionWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TArray<FMyTownWorkerGenderData> GenderData;

};

USTRUCT(BlueprintType)
struct FMyTownWorkerSetBonusData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FGameplayTagContainer SetBonusTypeTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 RequiredWorkersCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSubclassOf<UGameplayEffect> SetBonusEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 SelectionWeight;

};

UCLASS(MinimalAPI, BlueprintType)
class UMyTownData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Workers")
	TArray<FMyTownWorkerPersonalityData> WorkerPersonalities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Workers")
	TArray<FMyTownWorkerSetBonusData> WorkerSetBonuses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AmmoAndResources")
	TObjectPtr<UFortPersistentResourceItemDefinition> PersonnelXpItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AmmoAndResources")
	TObjectPtr<UFortPersistentResourceItemDefinition> HeroXpItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AmmoAndResources")
	TObjectPtr<UFortPersistentResourceItemDefinition> VoucherItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AmmoAndResources")
	TObjectPtr<UFortPersistentResourceItemDefinition> SchematicXpItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AmmoAndResources")
	TObjectPtr<UFortCurrencyItemDefinition> CurrencyItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AmmoAndResources")
	TObjectPtr<UFortTokenType> SkillPointItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AmmoAndResources")
	TObjectPtr<UFortTokenType> ResearchPointItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Homebase")
	TSubclassOf<UGameplayEffect> TotalRatingGameplayEffect;

};

