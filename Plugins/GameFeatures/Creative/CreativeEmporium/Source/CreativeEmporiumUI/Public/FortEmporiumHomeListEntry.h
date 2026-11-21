// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "UObject/NoExportTypes.h"
#include "FortEmporiumHomeListEntry.generated.h"

class UAthenaCreativeItemTileView;
class UCommonTextBlock;
class UFortEmporiumHomeListView;
class UFortEmporiumItemListTabPanel;
enum class EFortItemCardSize : uint8;

UCLASS(BlueprintType)
class UFortEmporiumHomeEntryObjectWrapper : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumHomeEntryObjectWrapper", meta=(EditInline="true"))
	UFortEmporiumItemListTabPanel* TabPanel;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEmporiumHomeListEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFortEmporiumHomeListEntry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumHomeListEntry", meta=(EditInline="true"))
	TObjectPtr<UFortEmporiumHomeListView> ParentView;

protected:
	UFUNCTION(BlueprintPure)
	EFortItemCardSize GetCardSizeForCategory() const;

	UFUNCTION(BlueprintPure)
	bool GetCollapseBorderPadFlagForCategory() const;

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWarningMessage(bool bShowMessage);

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumHomeListEntry")
	int32 MaxItemsToShow;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortEmporiumHomeListEntry", meta=(EditInline="true"))
	TObjectPtr<UFortEmporiumItemListTabPanel> TabPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumHomeListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CategoryLabel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumHomeListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaCreativeItemTileView> HomeListView_ItemOptions;

};

