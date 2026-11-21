// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "BattlePassSubPageInterface.h"
#include "FortBattlePassCustomSkinPageTab.generated.h"

class UBattlePassEnabledInputData;
class UCommonActivatableWidget;
class UCommonVisibilitySwitcher;
class UDynamicEntryBox;
class UObject;
class UScrollBox;

USTRUCT()
struct FBattlePassCharaterRewardTabInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BattlePassCharaterRewardTabInfo", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> TabIcon;

	UPROPERTY(EditAnywhere, Category="BattlePassCharaterRewardTabInfo")
	int32 TabCategoryCounter;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassCustomSkinPageTab : public UCommonActivatableWidget, public IBattlePassSubPageInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void EnableTabActions();

private:
	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Categories;

	UPROPERTY(Transient)
	TObjectPtr<UBattlePassEnabledInputData> EquipEnabledData;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VisibilitySwitcher_Content;

	UPROPERTY(EditAnywhere, Category="FortBattlePassCustomSkinPageTab")
	TArray<FBattlePassCharaterRewardTabInfo> TabInfos;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> ListView_PrimaryTabs;

	UPROPERTY(Transient)
	TArray<FBattlePassCharaterRewardTabInfo> ActiveTabInfos;

	UPROPERTY(EditAnywhere, Category="FortBattlePassCustomSkinPageTab")
	TSubclassOf<UCommonActivatableWidget> CustomizationRowClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortBattlePassCustomSkinPageTab", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortBattlePassCustomSkinPageTab", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

};

