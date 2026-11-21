// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ChallengeGiftBoxData.generated.h"

class UFortGiftBoxItemDefinition;

USTRUCT(BlueprintType)
struct FFortGiftBoxFortmatData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGiftBoxFortmatData")
	FString StringAssetType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGiftBoxFortmatData")
	FString StringData;

};

USTRUCT()
struct FChallengeGiftBoxData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ChallengeBundleSchedule")
	TSoftObjectPtr<UFortGiftBoxItemDefinition> GiftBoxToUse;

	UPROPERTY(EditAnywhere, Category="ChallengeBundleSchedule")
	TArray<FFortGiftBoxFortmatData> GiftBoxFormatData;

};

