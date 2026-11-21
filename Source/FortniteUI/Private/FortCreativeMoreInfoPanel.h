// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Creative/FortCreativeTypes.h"
#include "Creative/MyIsland/FortCreativeMyIslandContentPanelInterface.h"
#include "FortCreativeMoreInfoPanel.generated.h"

class UCommonButtonBase;
class UFortEditableFilteredCountedTextBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeMoreInfoPanel : public UCommonActivatableWidget, public IFortCreativeMyIslandContentPanelInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnIslandMetaDataUpdateComplete(const FString& Error);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIslandMetaDataUpdateTimedOut();

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsUpdatingChanged(const bool bIsUpdating);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatePlotData(const TArray<FString>& Errors, const FCreativeIslandInfo& IslandInfo);

	UFUNCTION(BlueprintCallable)
	void SetIslandIntroduction(const TArray<FText>& IslandIntroduction);

	UFUNCTION(BlueprintCallable)
	void SetIslandTitle(const FText& IslandTitle);

private:
	UFUNCTION()
	void HandleIslandMetaDataUpdateComplete(const FString& Error);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMoreInfoPanel", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> FilteredText_IslandTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMoreInfoPanel", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> FilteredText_IslandIntroduction1;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMoreInfoPanel", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> FilteredText_IslandIntroduction2;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMoreInfoPanel", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> FilteredText_IslandIntroduction3;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Apply;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Clear;

};

