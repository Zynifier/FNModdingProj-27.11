// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "FortChallengeSetStyle.generated.h"

class UObject;
class UTexture2D;

UENUM(BlueprintType)
enum class EBundleStyleColor : uint8
{
	Primary = 0,
	Secondary = 1,
	Accent = 2,
};

USTRUCT(BlueprintType)
struct FFortChallengePunchCardStyles
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortChallengePunchCardStyles", meta=(Categories="ChallengeBundle.Metadata.PunchCard"))
	FGameplayTag StyleType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengePunchCardStyles")
	FString EncodedName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengePunchCardStyles")
	FLinearColor BaseColor1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengePunchCardStyles")
	FLinearColor BaseColor2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengePunchCardStyles")
	FLinearColor BaseColor3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengePunchCardStyles")
	FLinearColor BaseColor4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengePunchCardStyles")
	FLinearColor BaseColor5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengePunchCardStyles")
	FLinearColor AccentColor1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengePunchCardStyles")
	FLinearColor AccentColor2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengePunchCardStyles")
	TSoftObjectPtr<UTexture2D> BackgrounTexture;

};

USTRUCT(BlueprintType)
struct FFortChallengeSetStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeSetStyle")
	FLinearColor PrimaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeSetStyle")
	FLinearColor SecondaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeSetStyle")
	FLinearColor AccentColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeSetStyle")
	FLinearColor Context_LimitedTimeColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeSetStyle")
	FLinearColor Context_BaseColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeSetStyle", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> DisplayImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeSetStyle", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> CustomBackground;

};

UCLASS()
class UFortChallengeSetStyleAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortChallengeSetStyleAsset")
	FFortChallengeSetStyle Style;

};

