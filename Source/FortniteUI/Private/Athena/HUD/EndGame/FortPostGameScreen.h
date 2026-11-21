// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortPostGameScreen.generated.h"

UENUM(BlueprintType)
enum class EPostGameClickCatcherMode : uint8
{
	Catch_None = 0,
	Catch_MobileOnly = 1,
	Catch_MouseOnly = 2,
	Catch_All = 3,
};

UENUM(BlueprintType)
enum class EPostGameHUDMode : uint8
{
	None = 0,
	AllHidden = 1,
	Spectating = 2,
	AllHiddenExceptXP = 3,
};

UENUM()
enum class EPostGameScreenContinueBehavior : uint8
{
	Next = 0,
	Previous = 1,
};

USTRUCT(BlueprintType)
struct FFortPostGameScreenConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPostGameScreenConfig")
	EPostGameClickCatcherMode ClickCatcherState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPostGameScreenConfig")
	EPostGameHUDMode PostGameHUDMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPostGameScreenConfig")
	bool bSohwCinematicBars;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPostGameScreenConfig")
	bool bShowPlacementOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPostGameScreenConfig")
	bool bIsContainerSafeZoneEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPostGameScreenConfig")
	bool bShowSpectatingPlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPostGameScreenConfig")
	bool bPutPawnInStasis;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPostGameScreenConfig")
	bool bAllowEmotesInStasis;

};

UCLASS(meta=(DisableNativeTick))
class UFortPostGameScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Post Game Flow", meta=(DisplayName="Should Display"))
	bool BP_ShouldDisplay();

	UFUNCTION(BlueprintCallable, Category="Post Game Flow")
	void GoToNextScreen();

	UFUNCTION(BlueprintCallable, Category="Post Game Flow")
	void GoToNextScreenAfterActivated();

	UFUNCTION(BlueprintCallable, Category="Post Game Flow")
	void GoToPreviousScreen();

	UFUNCTION(BlueprintCallable, Category="Post Game Flow")
	void GoToPreviousScreenAfterActivated();

protected:
	UFUNCTION(BlueprintCallable, Category="Requests", meta=(DisplayName="Request Overlay Fadeout"))
	void BP_OnFadeOutOverlayRequest();

	UFUNCTION(BlueprintCallable, Category="Requests", meta=(DisplayName="Request Toggle Blur"))
	void BP_OnToggleBlurRequest();

	UPROPERTY(EditAnywhere, Category="FortPostGameScreen")
	FFortPostGameScreenConfig PostGameScreenConfig;

private:
	UPROPERTY(EditAnywhere, Category="Flow Navigation")
	bool bCanGoBackToThisScreen;

};

