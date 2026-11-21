// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "FortMcpVariantChannelInfo.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FMcpVariantChannelInfo : public FCosmeticVariantInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="McpVariantChannelInfo", meta=(Categories="Cosmetics.Variant.Property"))
	FGameplayTagContainer OwnedVariantTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="McpVariantChannelInfo")
	TObjectPtr<UFortItemDefinition> ItemVariantIsUsedFor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="McpVariantChannelInfo")
	FString CustomData;

};

