// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaMapScreenAnalyticsInterface.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "AthenaCollectionScreenContainer.generated.h"

class UCommonActivatableWidget;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UDynamicEntryBox;
class UObject;

USTRUCT()
struct FAthenaCollectionScreenContainerTabInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenContainerTabInfo")
	FText TabTitle;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenContainerTabInfo", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> TabIcon;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenContainerTabInfo")
	TSoftClassPtr<UCommonActivatableWidget> TabClass;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenContainerTabInfo")
	FGameplayTagContainer TabCategoryTags;

};

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaCollectionScreenContainer : public UCommonActivatableWidget, public IAthenaMapScreenContainerTabInterface, public IAthenaMapScreenAnalyticsInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Fullscreen Map")
	FAthenaMapScreenContainerTabInfo MapTabInfo;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Show Tabs Set"))
	void BP_OnShowTabsSet(bool bShowTabs);

	UFUNCTION(BlueprintCallable)
	void DisableTabActions();

	UFUNCTION(BlueprintCallable)
	void EnableTabActions();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VisibilitySwitcher_Content;

private:
	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenContainer")
	TArray<FAthenaCollectionScreenContainerTabInfo> TabInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaCollectionScreenContainer", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaCollectionScreenContainer", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaCollectionScreenContainerTabButton"))
	TObjectPtr<UDynamicEntryBox> EntryBox_TabButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionScreenContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TabTitle;

	UPROPERTY(Transient)
	TArray<FAthenaCollectionScreenContainerTabInfo> ActiveTabInfos;

};

