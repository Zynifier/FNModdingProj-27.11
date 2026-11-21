// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Athena/Creative/ItemTileView/AthenaCreativeItemTileButton.h"
#include "Creative/FortCreativeIslandLinkScreen.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCreativeIslandSelect.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonListView;
class UCommonTextBlock;
class UCommonTileView;
class UDataRegistry;
class UFortCreativeIslandLink;
class UFortCreativeIslandTemplateButton;
class UFortCreativeRealEstatePlotItemDefinition;
class UFortEditableFilteredCountedTextBox;
class UFortLazyImage;
class UObject;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortCreativeIslandGeneration : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetShowTemplateIslands();

	UFUNCTION(BlueprintNativeEvent)
	void HandleCancelClicked();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HandleNoOptionsLoaded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectionUpdated(UFortCreativeIslandTemplateButton* CurrentSelection);

	UFUNCTION(BlueprintCallable)
	void SetupIslandTemplateData();

	UFUNCTION(BlueprintCallable)
	void StartingIslandsOnCurrentItemSelectionChanged(UObject* Item);

	UFUNCTION(BlueprintCallable)
	void TemplateIslandsOnCurrentItemSelectionChanged(UObject* Item);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> StartingIslandsTileView;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> TemplateIslandsTileView;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> AcceptButton;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> IslandTemplateNameText;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> IslandDescriptionText;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PublishedIslandName;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PublishedIslandCode;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PublishedIslandAuthor;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PublishedIslandBulletOne;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PublishedIslandBulletTwo;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandGeneration", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PublishedIslandBulletThree;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeIslandGeneration")
	TObjectPtr<UCommonButtonGroupLegacy> TabButtonGroup;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnIslandFilterComplete();

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandGeneration")
	TObjectPtr<UDataRegistry> IslandTemplateDataTable;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortCreativeRealEstatePlotItemDefinition>> FilteredIslandTemplateDefinitions;

	UPROPERTY()
	FCachedIslandsGroup CachedTemplateIslands;

	UPROPERTY()
	TArray<TObjectPtr<UFortCreativeIslandLink>> IslandLinks;

private:
	UFUNCTION()
	void StartingIslandsOnHoveredItemChanged(UObject* Item, bool bIsHovered);

	UFUNCTION()
	void TemplateIslandsOnHoveredItemChanged(UObject* Item, bool bIsHovered);

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandNamingModal : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitFromIslandLink(UFortCreativeIslandLink* IslandLink);

	UFUNCTION(BlueprintCallable)
	void InitFromPlotItemDefinition(UFortCreativeRealEstatePlotItemDefinition* RealEstateItemDefinition);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeIslandNamingModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> FilteredTextEntryWidget_Name;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeIslandNamingModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Confirm;

protected:
	UPROPERTY(BlueprintReadWrite, Category="FortCreativeIslandNamingModal")
	FText InitialDisplayText;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeIslandNamingModal")
	FText DefaultIslandName;

private:
	UPROPERTY()
	TObjectPtr<UFortCreativeRealEstatePlotItemDefinition> TemplateRealEstatePlotDefinition;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandSelect : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="FortCreativeIslandSelect")
	TObjectPtr<UCommonButtonGroupLegacy> TabButtonGroup;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeIslandSelect", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_IslandList;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeIslandTemplateButton : public UAthenaCreativeItemTileButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UFortCreativeIslandLink* GetIslandLink();

	UFUNCTION(BlueprintCallable)
	UFortCreativeRealEstatePlotItemDefinition* GetPlotTemplateDefinition();

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandTemplateButton")
	FVector2D FeaturedIslandTemplateImageSize;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandTemplateButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> TemplateImage;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandTemplateButton")
	FSlateBrush DefaultFeaturedTemplateImage;

};

