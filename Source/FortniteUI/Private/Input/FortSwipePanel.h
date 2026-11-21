// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "Math/MathFwd.h"
#include "Input/FortSwipeDetector.h"
#include "FortSwipePanel.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFortSwipeEvent);

UCLASS(BlueprintType, Blueprintable)
class UFortSwipePanel : public UContentWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Fort Swipe Panel")
	void GetSwipeInfo(int32& OutIndex, FVector2D& OutSwipePercentage) const;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SwipeDetection", meta=(AllowPrivateAccess="TRUE", ClampMin="0", UIMin="0"))
	FVector2D SwipeThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SwipeDetection", meta=(AllowPrivateAccess="TRUE"))
	bool bBeginSwipeOnPointerEnter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(AllowPrivateAccess="TRUE"))
	bool bConsumePointerInput;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE", DisplayName="On Swipe Left"))
	FOnFortSwipeEvent BP_OnSwipeLeft;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE", DisplayName="On Swipe Right"))
	FOnFortSwipeEvent BP_OnSwipeRight;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE", DisplayName="On Swipe Up"))
	FOnFortSwipeEvent BP_OnSwipeUp;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE", DisplayName="On Swipe Down"))
	FOnFortSwipeEvent BP_OnSwipeDown;

	UPROPERTY()
	FFortSwipeDetector SwipeDetector_DEPRECATED;

};

