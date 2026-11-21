// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "FortRarityData.generated.h"

class UFortItem;
class UFortItemDefinition;
class UObject;
enum class EFortRarity : uint8;

USTRUCT(BlueprintType)
struct FFortColorPalette
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FLinearColor Color1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FLinearColor Color2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FLinearColor Color3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FLinearColor Color4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FLinearColor Color5;

};

USTRUCT(BlueprintType)
struct FFortRarityItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	FLinearColor Color1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	FLinearColor Color2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	FLinearColor Color3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	FLinearColor Color4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	FLinearColor Color5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	float Falloff;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	float Brightness;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	float Roughness;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rarity")
	float Glow;

};

UCLASS(MinimalAPI)
class UFortRarityData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetRarityColorPalette"))
	static FFortColorPalette BPGetRarityColorPalette(EFortRarity Rarity);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetRarityData"))
	static FFortRarityItemData BPGetRarityData(EFortRarity Rarity);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetRarityDataForItemDef"))
	static FFortRarityItemData BPGetRarityDataForItemDef(const UFortItemDefinition* ItemDef);

	UFUNCTION(BlueprintCallable, Category="Rarity", meta=(WorldContext="WorldContextObject"))
	static EFortRarity GetRarityCosmeticForItem(const UObject* WorldContextObject, const UFortItem* Item);

	UPROPERTY(EditAnywhere, Category="Rarity", meta=(ArraySizeEnum="/Script/FortniteGame.EFortRarity"))
	FFortRarityItemData RarityCollection[8];

};

