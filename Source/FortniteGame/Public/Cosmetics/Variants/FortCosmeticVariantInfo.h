// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "FortCosmeticVariantInfo.generated.h"

USTRUCT(BlueprintType)
struct FCosmeticVariantInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticVariantInfo", meta=(Categories="Cosmetics.Variant.Channel"))
	FGameplayTag VariantChannelTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticVariantInfo", meta=(Categories="Cosmetics.Variant.Property"))
	FGameplayTag ActiveVariantTag;


	FORTNITEGAME_API bool operator==(const FCosmeticVariantInfo& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FCosmeticVariantInfo& Value);
};

USTRUCT(BlueprintType)
struct FVariantUID
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VariantUID", meta=(Categories="Cosmetics.Variant.Channel"))
	FGameplayTag ChannelTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VariantUID", meta=(Categories="Cosmetics.Variant.Property"))
	FGameplayTag VariantTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VariantUID")
	FPrimaryAssetId TemplateId;

};

