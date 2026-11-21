// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "ChallengeBundles/FortChallengeSetStyle.h"
#include "AthenaChallengeDisplayData.generated.h"

class UImage;
class UMaterialInstanceDynamic;
class UTexture2D;

UCLASS()
class UAthenaChallengeDisplayData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaChallengeDisplayData")
	int32 SoonDisplayMinuteThreshold;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeDisplayData")
	FLinearColor PartyAssistFontColor;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeDisplayData")
	FLinearColor DifficultChallengeFontColor;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeDisplayData")
	TObjectPtr<UTexture2D> PartyAssistIcon;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeDisplayData")
	TObjectPtr<UTexture2D> ExternalPartyAssistIcon;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeDisplayData")
	FFortChallengeSetStyle DefaultChallengeStyle;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeDisplayData")
	FFortChallengeSetStyle DailyChallengeStyle;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeDisplayData")
	TArray<FGameplayTagContainer> PunchCardSortOrder;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeDisplayData")
	TArray<FFortChallengePunchCardStyles> ChallengePunchCardStyles;

};

UCLASS()
class FORTNITEUI_API UAthenaChallengeDisplayLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void ApplyChallengeSetStyleColorsToImageMaterial(const FFortChallengeSetStyle& DisplayStyle, UImage* ImageWidget);

	UFUNCTION(BlueprintCallable)
	static void ApplyChallengeSetStyleColorsToMaterial(const FFortChallengeSetStyle& DisplayStyle, UMaterialInstanceDynamic* StyleMaterial);

	UFUNCTION(BlueprintCallable)
	static FLinearColor GetChallengeStyleLightAccentColor(const FFortChallengeSetStyle& DisplayStyle);

};

