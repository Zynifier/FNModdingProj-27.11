// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortHabaneroDisplayData.generated.h"

class UFortHabaneroTierTypeData;
class UMaterialInstance;
class UTexture2D;

UENUM(BlueprintType)
enum class EHabaneroTierType : uint8
{
	HabaneroSauce0 = 0,
	HabaneroSauce1 = 1,
	HabaneroSauce2 = 2,
	HabaneroSauce3 = 3,
	HabaneroSauce4 = 4,
	HabaneroSauce5 = 5,
	HabaneroSauce6 = 6,
	HabaneroSauce7 = 7,
	HabaneroSauce8 = 8,
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortHabaneroTier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroTier", meta=(DisplayName="Icon Foreground"))
	TSoftObjectPtr<UMaterialInstance> ForegroundIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroTier", meta=(DisplayName="Small Icon Foreground"))
	TSoftObjectPtr<UMaterialInstance> ForegroundIconSmall;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroTier", meta=(DisplayName="Icon Background"))
	TSoftObjectPtr<UMaterialInstance> BackgroundIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroTier", meta=(DisplayName="Small Icon Background"))
	TSoftObjectPtr<UMaterialInstance> BackgroundIconSmall;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroTier")
	TSoftObjectPtr<UTexture2D> WhiteIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroTier")
	TSoftObjectPtr<UTexture2D> SimpleIconSmall;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroTier", meta=(DisplayName="Name"))
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroTier", meta=(DisplayName="Category"))
	TObjectPtr<UFortHabaneroTierTypeData> TierType;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortHabaneroModeList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroModeList", meta=(DisplayName="Tiers"))
	TArray<FFortHabaneroTier> TierList;

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortHabaneroDisplayData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Habanero Entries", meta=(DisplayName="Modes"))
	TMap<FString, FFortHabaneroModeList> EntryData;

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortHabaneroTierTypeData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHabaneroTierTypeData", meta=(DisplayName="Category"))
	EHabaneroTierType Category;

};

