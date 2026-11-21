// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Creative/Options/FortCreativeOption.h"
#include "FortMatchmakingKnobsDataSource.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCreativeGlobalOptions.generated.h"

class UCommonButtonLegacy;
class UCommonListView;
class UCommonTextBlock;
class UFortCreativeGlobalOptions;
class UFortCreativeOption;
class UFortCreativeOptionsBundle;
class UFortCreativeOptionsCategory;
class UFortMatchmakingKnobsSpinnerButton;
class UImage;

UCLASS(Abstract, Config=Creative, meta=(DisableNativeTick))
class UFortCreativeGlobalOptions : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetListDataSource(UFortMatchmakingKnobsDataSource::Type ListType);

protected:
	UFUNCTION(BlueprintPure)
	UFortCreativeOptionsCategory* GetOptionListFromMemoryPointer() const;

	UFUNCTION(BlueprintCallable)
	void UpdateCachedIndices();

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeGlobalOptions")
	int32 CachedLastUsedIndexInCategory;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGlobalOptions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeOptionsCategory> Category_Player;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGlobalOptions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeOptionsCategory> Category_MoveTool;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGlobalOptions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Accept;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGlobalOptions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGlobalOptions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ToolTipText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGlobalOptions", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UImage> Image_DisplayImage;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortCreativeOptionsBundle> OptionsAsset;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeOptionsCategory : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCreativeOptionsCategory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	UCommonListView* GetOptionsList() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectionUpdated(UFortMatchmakingKnobsSpinnerButton* CurrentSelection);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeOptionsCategory")
	FCreativeOptionCategoryData OptionCategory;

	UPROPERTY()
	TArray<TObjectPtr<UFortCreativeOption>> CreativeOptions;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortCreativeGlobalOptions> GlobalOptionsUI;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Options;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CategoryText;

};

