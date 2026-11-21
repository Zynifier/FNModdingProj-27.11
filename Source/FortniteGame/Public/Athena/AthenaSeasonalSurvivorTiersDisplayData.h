// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "AthenaSeasonalSurvivorTiersDisplayData.generated.h"

class UAthenaSeasonalSurvivorTiersDisplayData;
class UFortPersistentResourceItemDefinition;
class UMaterialInterface;
class UObject;

USTRUCT(BlueprintType)
struct FSurvivorPresigeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SurvivorPresigeData")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SurvivorPresigeData")
	TSoftObjectPtr<UMaterialInterface> SmallIconMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SurvivorPresigeData")
	TSoftObjectPtr<UMaterialInterface> LargeIconMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SurvivorPresigeData")
	FLinearColor Color1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SurvivorPresigeData")
	FLinearColor Color2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SurvivorPresigeData")
	FLinearColor TextColor;

};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEGAME_API UAthenaSeasonalSurvivorTiersDisplayData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetMaxTier() const;

	UFUNCTION(BlueprintPure)
	FSurvivorPresigeData GetPrestigeData(const int32 PrestigeLevel) const;

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static const UAthenaSeasonalSurvivorTiersDisplayData* GetSurvivorTierDisplayData(UObject* WorldContextObject);

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonalSurvivorTiersDisplayData")
	TArray<FSurvivorPresigeData> PrestigeLevelData;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonalSurvivorTiersDisplayData")
	int32 MaxTier;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonalSurvivorTiersDisplayData")
	TObjectPtr<UFortPersistentResourceItemDefinition> TierUpItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonalSurvivorTiersDisplayData")
	TObjectPtr<UFortPersistentResourceItemDefinition> PrestigeUpItemDefinition;

};

