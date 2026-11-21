// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "CommonTabListWidgetLegacy.h"
#include "FortTabListWidgetBase.h"
#include "FortTabListWidgetBase_Legacy.generated.h"

class UCommonButtonBase;
class UCommonUserWidget;
class UUserWidget;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class FORTNITEUI_API UFortTabListWidgetBase_Legacy : public UCommonTabListWidgetLegacy
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTabContentCreated_Legacy, FName, TabId, UCommonUserWidget*, TabWidget);

public:
	UFUNCTION(BlueprintPure, Category="Tab List")
	bool GetPreregisteredTabInfo(const FName TabNameId, FFortTabListRegistrationInfo& OutTabInfo);

	UFUNCTION(BlueprintPure, Category="Tab List")
	int32 GetVisibleTabCount();

	UFUNCTION(BlueprintPure, Category="Tab List")
	bool IsFirstTabActive() const;

	UFUNCTION(BlueprintPure, Category="Tab List")
	bool IsLastTabActive() const;

	UFUNCTION(BlueprintPure, Category="Tab List")
	bool IsTabVisible(FName TabId);

	UFUNCTION(BlueprintCallable, Category="Tab List")
	void RegisterAllPreregisteredTabInfos();

	UFUNCTION(BlueprintCallable, Category="Tab List")
	void RegisterDivider(TSubclassOf<UUserWidget> DividerWidgetType);

	UFUNCTION(BlueprintCallable, Category="Tab List")
	bool RegisterFortTab(FName TabNameId, TSubclassOf<UCommonButtonBase> TabButtonType, const FFortTabButtonLabelInfo& LabelInfo, UWidget* ContentWidget);

	UFUNCTION(BlueprintImplementableEvent, Category="Tab List")
	void RemoveAllDividers();

	UFUNCTION(BlueprintCallable, Category="Tab List")
	void SetTabHiddenState(FName TabNameId, bool bHidden);

	UPROPERTY(BlueprintAssignable, Category="Tab List")
	FOnTabContentCreated_Legacy OnTabContentCreated;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Tab List", meta=(BlueprintProtected="true"))
	void HandleDividerCreation(UUserWidget* DividerWidget);

private:
	UPROPERTY(EditAnywhere, Category="FortTabListWidgetBase_Legacy")
	TArray<FFortTabListRegistrationInfo> PreregisteredTabInfoArray;

	UPROPERTY(EditAnywhere, Category="FortTabListWidgetBase_Legacy", meta=(InlineEditConditionToggle="HiddenVisibility"))
	bool bHideSingleTab;

	UPROPERTY(EditAnywhere, Category="FortTabListWidgetBase_Legacy", meta=(EditCondition="bHideSingleTab"))
	ESlateVisibility HideSingleTabVisibility;

	UPROPERTY()
	TMap<FName, FFortTabButtonLabelInfo> PendingTabLabelInfoMap;

};

