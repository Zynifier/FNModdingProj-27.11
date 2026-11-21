// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortVariantSprayCustomizerConfig.generated.h"

class UFortItemDefinition;

USTRUCT()
struct FFortVariantSprayCustomizerChannelOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortVariantSprayCustomizerChannelOptions")
	FRotator RotationOffset;

};

USTRUCT()
struct FFortVariantSprayCustomizerCosmeticOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortVariantSprayCustomizerCosmeticOptions", meta=(AllowedClasses="/Script/FortniteGame.AthenaSprayItemDefinition"))
	TArray<TSoftObjectPtr<UFortItemDefinition>> ItemShopPreviewStyles;

	UPROPERTY(EditAnywhere, Category="FortVariantSprayCustomizerCosmeticOptions")
	TMap<FGameplayTag, FFortVariantSprayCustomizerChannelOptions> ChannelOptions;

};

UCLASS()
class UFortVariantSprayCustomizerConfig : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortVariantSprayCustomizerConfig")
	TMap<FGameplayTag, FFortVariantSprayCustomizerCosmeticOptions> SprayCustomizerOptions;

};

