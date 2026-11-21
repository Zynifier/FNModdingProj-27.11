// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortTheaterSelect.generated.h"

class UFortQuestItemDefinition;
class UOverlay;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTheaterSelect : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="TheaterSelect")
	bool GetTheaterRecommendedRatingRange(const FString& UniqueId, int32& Minimum, int32& Maximum) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigationLeft();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigationRight();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> OverlayMain;

private:
	UPROPERTY(EditAnywhere, Category="FortTheaterSelect")
	TObjectPtr<UFortQuestItemDefinition> DefaultRequiredCompletedQuest;

};

