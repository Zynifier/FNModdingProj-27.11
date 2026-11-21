// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortConversationScreen.generated.h"

class UCommonVisibilitySwitcher;
class UFortBasicBrief;
class UFortConversationOptionBrief;
class UFortKeybindWidget;
class UFortRadialSlot;
class UFortSlottedRadialMenu;
class UImage;
class UInputComponent;
class USizeBox;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortConversationScreen : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void EndConversation();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnConversationOptionUnavailable(UFortRadialSlot* SelectedEntry);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnConversationStarted();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnItemSelected(int32 OriginalIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnOptionsPopulated();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnSelectedItemAvailabilityChanged(bool bIsAvailable);

	UFUNCTION(BlueprintPure, Category="Cosmetic")
	bool ShouldBlockOptionIntroAnim() const;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Details;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> ConversationInputComp;

	UPROPERTY(Transient)
	int32 CurrentlySelectedIndex;

	UPROPERTY(Transient)
	bool bBlockOptionIntroAnimation;

	UPROPERTY(EditAnywhere, Category="Cosmetic")
	FName RadialSelectionMaterialParameterName;

	UPROPERTY(EditAnywhere, Category="Item Prioritization")
	TArray<FGameplayTag> TagPriorities;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FName InteractActionNameKBM;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FName ADSInputAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FName InteractActionNameGamepad;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle ConfirmBinding;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle MakeSelectionBinding;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle ADSMouseBinding;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle CancelActionBinding;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle RightTriggerBinding;

	UPROPERTY(EditAnywhere, Category="Details")
	TMap<FString, TSoftClassPtr<UFortConversationOptionBrief>> DetailsNodeTypeToBrief;

	UPROPERTY(EditAnywhere, Category="Details")
	TSoftClassPtr<UFortConversationOptionBrief> ChatBrief;

	UPROPERTY(EditAnywhere, Category="Details")
	FString DataDrivenBriefPrefix;

	UPROPERTY(EditAnywhere, Category="Details")
	TSoftClassPtr<UFortConversationOptionBrief> DataDrivenBrief;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSlottedRadialMenu> RadialMenu_DialogOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_RadialHighlight;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConversationScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBasicBrief> BasicBrief_Main;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_RadialMenu;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConversationScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_Details;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_WheelContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConversationScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Background;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LoadingSpinner;

};

