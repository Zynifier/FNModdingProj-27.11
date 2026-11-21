// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortGameplayCinematicHostWidget.generated.h"

class UAthenaLoadingScreenItemDefinition;
class UCommonActivatableWidget;

USTRUCT()
struct FCinematicWidgetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CinematicWidgetData")
	FName WidgetEntryName;

	UPROPERTY(EditDefaultsOnly, Category="CinematicWidgetData", meta=(AllowedClasses="/Script/SpecialEventGameplayUI.FortGameplayCinematicWidget,/Script/SpecialEventGameplayUI.FortGameplayIntroPanelWidget"))
	TSubclassOf<UCommonActivatableWidget> WidgetClass;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Appearance", "Designer", "Interaction", "Performance", "Layout", "Behavior", "Clipping", "Navigation", "Localization", "Accessibility", "RenderTransform"), meta=(DisableNativeTick))
class SPECIALEVENTGAMEPLAYUI_API UFortGameplayCinematicHostWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Host Widget")
	FName IntroWidgetEntryName;

	UPROPERTY(EditDefaultsOnly, Category="Host Widget")
	TArray<FCinematicWidgetData> WidgetEntries;

	UPROPERTY(EditDefaultsOnly, Category="Loading Screen")
	TObjectPtr<UAthenaLoadingScreenItemDefinition> LoadingScreenDefinition;

};

