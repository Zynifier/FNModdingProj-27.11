// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortTheaterSelect_Legacy.generated.h"

class UFortQuestItemDefinition;
class UOverlay;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTheaterSelect_Legacy : public UCommonActivatablePanelLegacy
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
	UPROPERTY(EditAnywhere, Category="FortTheaterSelect_Legacy")
	TObjectPtr<UFortQuestItemDefinition> DefaultRequiredCompletedQuest;

};

