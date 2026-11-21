// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortDialogTypes.h"
#include "FortRootViewportLayout.generated.h"

class UAthenaProgressModal;
class UCommonActivatableWidget;
class UCommonActivatableWidgetQueue;
class UCommonTextBlock;
class UFortConfirmationWindow;
class UFortErrorWindow;
class UFortLetoLayoutBorder;
class UFortPinModal;
class UFortRestartClientModal;
class UFortToastDisplayArea;
class UFortUINotificationManager;
class UFortUIStateWidgetBase;
class UFortUIStateWidget_NUI;
class UFortWebPurchaseScreen;
class UOverlay;
class USizeBox;
class UWidget;

USTRUCT()
struct FPluginUIStateWidgetEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName EntryName;

	UPROPERTY()
	TSoftClassPtr<UFortUIStateWidgetBase> WidgetClass;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortLetoLayoutBorder : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateBorderWidth(float HalfBorderWidth);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

};

UCLASS(Abstract, Config=Game, meta=(Category="Fortnite UI", DisableNativeTick))
class FORTNITEUI_API UFortRootViewportLayout : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void PurchasingWidgetDismissedCallback();

	UFUNCTION()
	void PurchasingWidgetDisplayCallback(UWidget* WebWidget, const FString& OfferId);

	UPROPERTY(EditAnywhere, Category="FortRootViewportLayout")
	TSubclassOf<UFortWebPurchaseScreen> WebPurchaseScreenWidgetClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRootViewportLayout", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UFortWebPurchaseScreen> WebPurchaseWidget_RuntimeSpawned;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRootViewportLayout")
	TSubclassOf<UCommonActivatableWidget> MVVMDialogWidgetClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortUIStateWidgetBase> CurrentStateWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> StateContentBox;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetQueue> WidgetQueue_ModalContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaProgressModal> AthenaProgressModal;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Dialog;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRootViewportLayout", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortConfirmationWindow> ConfirmationWindow_ConfirmationWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRootViewportLayout", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortErrorWindow> ErrorWindow_Errors;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaProgressModal> ProgressModal_ControllerDisconnected;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRestartClientModal> RestartModal;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPinModal> PinModal;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortToastDisplayArea> ToastDisplayArea_ToastHandler;

private:
	UFUNCTION()
	void HandleControllerConnectionChanged(bool bConnected);

	UPROPERTY(Transient)
	TObjectPtr<UFortUINotificationManager> NotificationManager;

	UPROPERTY(Transient)
	TArray<FFortDialogDescription_NUI> ConfirmationQueue;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortUIStateWidget_NUI> CurrentLegacyStateWidget;

	UPROPERTY(EditAnywhere, Category="FortRootViewportLayout")
	TSubclassOf<UFortLetoLayoutBorder> LetoLayoutBorderClass;

	UPROPERTY(Config)
	TArray<FPluginUIStateWidgetEntry> PluginUIStateWidgetEntries;

};

