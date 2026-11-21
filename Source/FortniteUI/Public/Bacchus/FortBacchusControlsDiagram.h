// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "FortBacchusControlsDiagram.generated.h"

class UCommonVisibilitySwitcher;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBacchusControlsDiagram : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortBacchusControlsDiagram(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintPure)
	bool GetIsDisplayingCombatMode() const;

	UFUNCTION(BlueprintCallable)
	void ToggleDisplayedControlMode(bool bShouldDisplayCombatControls);

	UPROPERTY(EditDefaultsOnly, Category="FortBacchusControlsDiagram")
	FGameplayTag NoBuildGameModeTag;

	UPROPERTY(EditDefaultsOnly, Category="FortBacchusControlsDiagram")
	bool bShowTitleBackground;

private:
	UFUNCTION()
	void HandlePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_BackgroundText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ScaleBox_TextCombatControls;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ScaleBox_TextBuildingControls;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Modes;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ScaleBox_CombatTapAnywhere;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ScaleBox_CombatFireButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_CombatModes;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ScaleBox_BuildingMode;

};

