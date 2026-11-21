// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "Math/MathFwd.h"
#include "CommonButtonLegacy.h"
#include "Items/AthenaSeasonItemDefinitionTypes.h"
#include "BattlePassNavigator.generated.h"

class UAthenaSeasonItemData_Level;
class UAthenaSeasonItemDefinition;
class UCommonButtonGroupLegacy;
class UCommonLazyImage;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortBangWrapper_NUI;

USTRUCT()
struct FTrackCategoryUI
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FTrackCategory TrackData;

	UPROPERTY()
	int32 LastSelectedIndex;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassNavigator : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTabChanged(bool bIsForwardChange);

private:
	UPROPERTY(Transient)
	TArray<FTrackCategoryUI> CreatedTabs;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaSeasonItemDefinition> SeasonData;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaSeasonItemData_Level> SeasonData_Level;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassNavigator", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassNavigator", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> EntryBoxButtonGroup;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="BattlePassNavigatorTabButton"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Categories;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SeasonNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CategoryName;

	UPROPERTY(Transient)
	TArray<int32> ViewedPages;

	UPROPERTY(Transient)
	FString CachedCategoryName;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UBattlePassNavigatorTabButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBangWrapper_NUI> BangWrapper_Seen;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D ImageSize_Mobile;

};

