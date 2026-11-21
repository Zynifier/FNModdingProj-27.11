// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonBase.h"
#include "UObject/NoExportTypes.h"
#include "FortLevelSaveComponent.h"
#include "LevelManagementListEntry.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;
class ULevelManagementListView;
class UWidgetSwitcher;

UCLASS(BlueprintType)
class ULevelInstanceEntryObjectWrapper : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="LevelInstanceEntryObjectWrapper")
	FLevelInstanceListElement LevelInstanceListElement;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class ULevelManagementListEntry : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CompareToLevelInstanceInfoEntry(const FLevelInstanceListElement& InLevelInstanceInfoEntry);

	UFUNCTION(BlueprintCallable)
	void HandleLevelDeleteClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSelected(bool bEntrySelected);

	UPROPERTY(BlueprintReadOnly, Export, Category="LevelManagementListEntry", meta=(EditInline="true"))
	TObjectPtr<ULevelManagementListView> ParentView;

protected:
	UPROPERTY(BlueprintReadWrite, Category="LevelManagementListEntry")
	FLevelInstanceListElement LevelInstanceListElementEntry;

	UPROPERTY(BlueprintReadOnly, Export, Category="LevelManagementListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LevelName;

	UPROPERTY(BlueprintReadOnly, Export, Category="LevelManagementListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NumPortals;

	UPROPERTY(BlueprintReadOnly, Export, Category="LevelManagementListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NumRefs;

	UPROPERTY(BlueprintReadOnly, Export, Category="LevelManagementListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher_TerrainType;

	UPROPERTY(BlueprintReadOnly, Export, Category="LevelManagementListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> IconTextButton_Delete;

};

