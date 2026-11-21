// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortTabListWidgetBase.h"
#include "FortCreativePropertyEditorFilter.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonButtonStyle;
class UCommonTextBlock;
class UDynamicEntryBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativePropertyEditorFilter : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSelectedFilterChanged, const FName, SelectedFilterId, const FName, PreviouslySelectedFilterId);

public:
	UFUNCTION(BlueprintPure)
	FName GetSelectedFilterButtonId() const;

	UPROPERTY(BlueprintAssignable)
	FOnSelectedFilterChanged OnSelectedFilterChanged;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFilterButtonCreated(UCommonButtonBase* FilterButton, const FFortTabListRegistrationInfo& TabInfo);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FilterName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="CommomButtonBase"))
	TObjectPtr<UDynamicEntryBox> EntryBox_FilterButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PreviousFilter;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_NextFilter;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyEditorFilter")
	TSubclassOf<UCommonButtonStyle> TabButtonStyle;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyEditorFilter")
	TArray<FFortTabListRegistrationInfo> TabInfos;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> FilterButtonGroup;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UCommonButtonBase>, FFortTabListRegistrationInfo> FilterButtonToTabInfoMap;

};

