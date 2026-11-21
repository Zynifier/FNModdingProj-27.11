// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "FortMultiSize.h"
#include "FortScoreStylingData.generated.h"

UENUM(BlueprintType)
namespace EFortUIScoreType
{
	enum Type
	{
		Combat = 0,
		Building = 1,
		Utility = 2,
		Badges = 3,
		Bonus = 4,
		Total = 5,
		Max_None = 6 UMETA(Hidden),
	};
}

USTRUCT(BlueprintType)
struct FFortScoreStylingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortScoreStylingInfo")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortScoreStylingInfo")
	FFortMultiSizeBrush Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortScoreStylingInfo")
	FLinearColor Color;

};

UCLASS()
class UFortScoreStylingData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="Get Score Styling Data"))
	static bool GetScoreStylingData(EFortUIScoreType::Type Rarity, FFortScoreStylingInfo& ScoreStylingInfo);

	UPROPERTY(EditAnywhere, Category="Score Styling", meta=(ArraySizeEnum="/Script/FortniteGame.EFortUIScoreType"))
	FFortScoreStylingInfo ScoreStyles[6];

};

