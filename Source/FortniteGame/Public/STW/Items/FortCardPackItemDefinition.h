// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortCardPackItemDefinition.generated.h"

class UFortPackPersonality;
class UTexture2D;
class UTexture;

UCLASS(MinimalAPI, BlueprintType)
class UFortCardPackItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CardPackItemDefinition")
	int32 GetDisplayRarityLevel() const;

	UFUNCTION(BlueprintPure, Category="CardPackItemDefinition")
	FLinearColor GetPackColor() const;

	UFUNCTION(BlueprintPure, Category="CardPackItemDefinition")
	UTexture* GetPackImage() const;

	UFUNCTION(BlueprintPure, Category="CardPackItemDefinition")
	UFortPackPersonality* GetPackPersonality() const;

	UFUNCTION(BlueprintPure, Category="CardPackItemDefinition")
	TSoftObjectPtr<UTexture2D> GetXRayImage() const;

	UFUNCTION(BlueprintPure, Category="CardPackItemDefinition")
	bool IsChoicePack() const;

	UFUNCTION(BlueprintPure, Category="CardPackItemDefinition")
	bool IsLlama() const;

private:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="FortCardPackItemDefinition")
	bool bIsLlama;

	UPROPERTY(EditAnywhere, Category="FortCardPackItemDefinition")
	bool bIsChoicePack;

	UPROPERTY(EditAnywhere, Category="FortCardPackItemDefinition")
	bool bAutoOpenAsReward;

	UPROPERTY(EditAnywhere, Category="FortCardPackItemDefinition", meta=(DisplayAfter="LootTierGroup"))
	int32 LootTier;

	UPROPERTY(EditAnywhere, Category="FortCardPackItemDefinition")
	FString LootTierGroup;

	UPROPERTY(EditAnywhere, Category="FortCardPackItemDefinition")
	int32 DisplayRarityLevel;

	UPROPERTY(EditAnywhere, Category="FortCardPackItemDefinition")
	TSoftObjectPtr<UTexture> PackImage;

	UPROPERTY(EditAnywhere, Category="FortCardPackItemDefinition")
	TSoftObjectPtr<UTexture2D> XRayTexture;

	UPROPERTY(EditAnywhere, Category="FortCardPackItemDefinition")
	FLinearColor PackColor;

	UPROPERTY(EditAnywhere, Category="FortCardPackItemDefinition")
	TSoftObjectPtr<UFortPackPersonality> PackPersonality;

};

