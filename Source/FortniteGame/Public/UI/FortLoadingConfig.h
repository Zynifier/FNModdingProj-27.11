// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Layout/Margin.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateTypes.h"
#include "FortLoadingConfig.generated.h"

class UFortTips;
class UObject;
class USoundBase;
class UUserWidget;

USTRUCT()
struct FFortEarlyAcessLoadingScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FSlateBrush EABackground;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FTextBlockStyle EATextStyle;

};

USTRUCT()
struct FFortLoadingBlockScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FProgressBarStyle LoadingProgressBar;

	UPROPERTY(EditAnywhere, Category="Visual")
	FMargin LoadingProgressBarPadding;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FTextBlockStyle LoadingTextStyle;

	UPROPERTY(EditAnywhere, Category="Visual")
	FMargin LoadingTextPadding;

};

USTRUCT()
struct FFortLogoLoadingScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Visual")
	FLinearColor LogoColor;

	UPROPERTY(EditAnywhere, Category="Visual")
	FMargin LogoPadding;

	UPROPERTY(EditAnywhere, Category="Visual")
	float LogoSize;

};

USTRUCT()
struct FFortPSALoadingScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Chance", meta=(ClampMax="100", ClampMin="1"))
	int32 PercentChance;

	UPROPERTY(EditAnywhere, Category="Requirements")
	int32 MinimumGames;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<UUserWidget> WidgetClass;

};

USTRUCT()
struct FFortSubGameLoadingScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LoadingScreen")
	TArray<TObjectPtr<UFortTips>> Tips;

	UPROPERTY(EditAnywhere, Category="Visual", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> BackgroundImage;

	UPROPERTY(EditAnywhere, Category="Visual")
	FVector2D BackgroundDesiredSize;

	UPROPERTY(EditAnywhere, Category="Visual")
	FLinearColor BackgroundColor;

	UPROPERTY(EditAnywhere, Category="Visual")
	FFortLogoLoadingScreen LogoLoadingScreen;

	UPROPERTY(EditAnywhere, Category="Visual")
	FFortLoadingBlockScreen LoadingBlockScreen;

	UPROPERTY(EditAnywhere, Category="Visual")
	FMargin SafeAreaMargin;

};

UCLASS(MinimalAPI)
class UFortLoadingConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LoadingScreen")
	FFortSubGameLoadingScreen LoadingScreenFallback;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FFortSubGameLoadingScreen LoadingScreens[2];

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FFortEarlyAcessLoadingScreen LoadingScreenEA;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FSlateBrush LoadingScreenMissionBackground;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FSlateBrush LoadingScreenTipBackground;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	TArray<FFortPSALoadingScreen> PSALoadingScreens;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	TObjectPtr<USoundBase> LoadingMusic;

};

