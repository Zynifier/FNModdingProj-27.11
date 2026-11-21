// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "Items/FortItemEntry.h"
#include "AthenaCreativeItemTileButton.generated.h"

class UAthenaCreativeItemEntryObjectWrapper;
class UAthenaCreativeItemTileButton;
class UAthenaCreativeItemTileView;
class UFortItemDefinition;
class UObject;

UCLASS(MinimalAPI, BlueprintType)
class UAthenaCreativeItemEntryObjectWrapper : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AthenaCreativeItemEntryObjectWrapper")
	FFortItemEntry ItemEntry;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaCreativeItemEntryObjectWrapper")
	bool bIsDownloading;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaCreativeItemTileButton : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CompareToItemEntry(const FFortItemEntry& InItemEntry);

	UFUNCTION(BlueprintPure)
	int32 GetItemTypeCount();

	UFUNCTION(BlueprintPure, meta=(DefaultToSelf="Target", HidePin="Target"))
	static UAthenaCreativeItemEntryObjectWrapper* MakeFortItemEntryObjectWrapper(UObject* Target, UPARAM(ref) FFortItemEntry& InItemEntry);

	UFUNCTION(BlueprintImplementableEvent, Category="Input")
	void OnEntryClick(UAthenaCreativeItemTileButton* Entry);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCreativeItemTileButton", meta=(EditInline="true"))
	TObjectPtr<UAthenaCreativeItemTileView> ParentView;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Loading")
	void OnLoadedItem();

	UPROPERTY(BlueprintReadOnly, Category="AthenaCreativeItemTileButton")
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="AthenaCreativeItemTileButton")
	FFortItemEntry ItemEntry;

};

