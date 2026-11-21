// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "DiscoCaptureWidgetBase.generated.h"

class AAthenaCapturePoint;
class AFortPlayerPawnAthena;
class AFortPlayerStateZone;
class UMaterialInstanceDynamic;
enum class EDiscoCaptureUIState : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EDiscoCaptureUIState : uint8
{
	None = 0,
	Hidden = 1,
	Dance = 2,
	Capturing = 3,
	Contested = 4,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FDiscoCaptureUIData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="DiscoCaptureUIData")
	EDiscoCaptureUIState CurrDisplayState;

	UPROPERTY()
	TObjectPtr<AAthenaCapturePoint> CapturePoint;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawnAthena> CurrPawn;

	UPROPERTY(BlueprintReadOnly, Category="DiscoCaptureUIData")
	TObjectPtr<UMaterialInstanceDynamic> CurrMID;

	UPROPERTY(BlueprintReadOnly, Category="DiscoCaptureUIData")
	float FillAmount;

	UPROPERTY(BlueprintReadOnly, Category="DiscoCaptureUIData")
	FText DisplayText;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UDiscoCaptureWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	AAthenaCapturePoint* GetClosestCapturePoint(AFortPlayerPawnAthena* ViewPawn);

	UFUNCTION()
	void OnHandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateCaptureUI(const EDiscoCaptureUIState& CaptureState, const FText& TextToDisplay, const UMaterialInstanceDynamic* ImageMID, float FillAmount);

	UFUNCTION()
	void UpdateAllUI();

	UFUNCTION()
	void UpdateDiscoCaptureUI();

	UPROPERTY(Transient)
	FDiscoCaptureUIData CaptureUIData;

	UPROPERTY(Transient)
	FDiscoCaptureUIData PrevCaptureUIData;

	UPROPERTY(Transient)
	uint8 LastViewedTeam;

};

