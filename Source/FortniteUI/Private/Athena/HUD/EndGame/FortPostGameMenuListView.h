// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "Blueprint/UserWidget.h"
#include "Components/ListViewBase.h"
#include "Engine/DataTable.h"
#include "CommonButtonLegacy.h"
#include "FortPostGameMenuListView.generated.h"

class UCommonActionWidget;
class UCommonTextBlock;
class UFortCTAButton;
class UFortPostGameMenuEntry;
class UFortPostGameMenuItemShopEntry;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPostGameMenuEntry : public UCommonButtonLegacy, public IUserListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortPostGameMenuEntry")
	FDataTableRowHandle HoldInputAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPostGameMenuEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Overlay_Entry;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPostGameMenuEntryOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortPostGameMenuEntryOverlay(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPostGameMenuEntryOverlay", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Name;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> InputAction_Select;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPostGameMenuItemShopEntry : public UFortPostGameMenuEntry
{
	GENERATED_BODY()

};

UCLASS(meta=(EntryClass="FortPostGameMenuEntry"))
class UFortPostGameMenuListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UFortPostGameMenuListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	UFortPostGameMenuEntry* GetFirstEntry() const;

private:
	UPROPERTY(EditAnywhere, Category="Entry Classes")
	TSubclassOf<UFortPostGameMenuEntry> EntryClass;

	UPROPERTY(EditAnywhere, Category="Entry Classes")
	TSubclassOf<UFortPostGameMenuItemShopEntry> ItemShopEntryClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	float EntrySpacing;

};

