// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/FortMobileHUDElement.h"
#include "FortMobileEasyLootGrid.generated.h"

class AActor;
class AFortPlayerController;
class UButton;
class UCommonListView;
class UFortControllerComponent_Interaction;
class UFortMobileEasyLootGridItemEntry;
class UImage;
class UOverlay;
class UVerticalBox;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMobileEasyLootGrid : public UFortMobileHUDElement
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static bool IsEasyLootGridEnabled(const AFortPlayerController* FortPC);

	UFUNCTION(BlueprintPure)
	static bool IsEasyLootGridEnabledForActor(const AFortPlayerController* FortPC, const AActor* PickUpItem);

	UFUNCTION(BlueprintCallable)
	void UpdateListPostAnimation();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAutoPickupPressed(bool bEnable);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBackpackFullChanged(bool bFull);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCollapsedListPressed(bool bShouldCollapseList);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLootFeedBack(bool bEnable);

private:
	UFUNCTION()
	void HandleAutoPickUpPressed();

	UFUNCTION()
	void HandleCollapsedListPressed();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> Button_AutoPickUp;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortMobileEasyLootGrid", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UButton> Button_CollapsedList;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortMobileEasyLootGrid", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> LootGridListBox;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortMobileEasyLootGrid", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Panel_Background;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Items;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortMobileEasyLootGrid", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_FullBackpack;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortControllerComponent_Interaction> InteractionComponent;

	UPROPERTY(Transient)
	TArray<UFortMobileEasyLootGridItemEntry*> LootGridListItems;

};

