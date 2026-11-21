// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortMusicAsset.generated.h"

class USoundBase;

UENUM(BlueprintType)
enum class EFortMusicSectionStopBehavior : uint8
{
	Crossfade = 0,
	AllowFadeOut = 1,
};

UENUM()
namespace EFortMusicSectionType
{
	enum Type
	{
		Intro = 0,
		Loop = 1,
		Outro = 2,
		Max_None = 3 UMETA(DisplayName="None"),
	};
}

USTRUCT(BlueprintType)
struct FFortMusicSection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMusicSection")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMusicSection")
	float FadeInTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMusicSection")
	float FadeOutTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMusicSection")
	float InitialOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMusicSection")
	float Duration;

};

UCLASS(BlueprintType)
class UFortMusicAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Music Assets")
	FFortMusicSection GetMusicSection(EFortMusicSectionType::Type Section);

	UPROPERTY(EditDefaultsOnly, Category="FortMusicAsset", meta=(ArraySizeEnum="/Script/FortniteGame.EFortMusicSectionType"))
	FFortMusicSection Sections[3];

	UPROPERTY(EditDefaultsOnly, Category="FortMusicAsset")
	float Priority;

	UPROPERTY(EditDefaultsOnly, Category="FortMusicAsset")
	EFortMusicSectionStopBehavior StopBehavior;

	UPROPERTY(EditDefaultsOnly, Category="FortMusicAsset")
	bool bIsStinger;

};

