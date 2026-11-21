// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortZoneLoadingScreenConfig.generated.h"

class UFortTips;
class USoundBase;
class UTexture2D;

USTRUCT(BlueprintType)
struct FZoneLoadingScreenHeadingConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	TObjectPtr<UTexture2D> HeadingImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LoadingScreen")
	FText Heading;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LoadingScreen")
	FText HeadingDescription;

};

USTRUCT()
struct FZoneLoadingScreenConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	TSoftObjectPtr<UTexture2D> BackgroundImage;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FText TitleDescription;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FText Title;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FZoneLoadingScreenHeadingConfig Headings[3];

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	TArray<TObjectPtr<UFortTips>> LoadingTips;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	TObjectPtr<USoundBase> LoadingMusic;

};

