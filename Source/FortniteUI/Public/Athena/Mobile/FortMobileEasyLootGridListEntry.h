// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "UObject/NoExportTypes.h"
#include "FortMobileEasyLootGridListEntry.generated.h"

class AActor;
class UAthenaItemIcon;
class UCommonButtonBase;
class UFortMobileEasyLootGrid;
class UFortMobileEasyLootGridItemEntry;
class USizeBox;
class UTextBlock;

UCLASS(BlueprintType)
class UFortMobileEasyLootGridItemEntry : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> LootGridItem;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMobileEasyLootGridListEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFortMobileEasyLootGridListEntry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemAdded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemRemoved(UFortMobileEasyLootGrid* list);

private:
	UFUNCTION()
	void PrimaryButtonClicked();

	UFUNCTION()
	void SecondaryButtonClicked();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PickUp;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Consume;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> Box_SecondaryAbility;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_WeaponName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_WeaponRarity;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemIcon> ItemIcon;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMobileEasyLootGridListEntry", meta=(AllowPrivateAccess="true"))
	TWeakObjectPtr<UFortMobileEasyLootGridItemEntry> LootGridItemEntry;

	UPROPERTY(BlueprintReadWrite, Category="FortMobileEasyLootGridListEntry", meta=(AllowPrivateAccess="true"))
	bool bAnimItemAdded;

};

