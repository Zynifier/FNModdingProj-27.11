// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortDialogTypes.h"
#include "UI/FortUIManagerInterface.h"
#include "FortUIManagerWidget_NUI.generated.h"

class UCommonActivatablePanelLegacy;
class UFortConfirmationWindow;
class UFortErrorWindow;
class UFortPinModal;
class UFortPlayerBanned;
class UFortProgressModal;
class UFortRestartClientModal;
class UFortUIManagerWidget_NUI;
class UFortUINotification;
class UFortUINotificationManager;
class UFortUINotificationQueue;
class UFortUIStateWidget_NUI;
class UNamedSlot;
class UObject;
class UUserWidget;
enum class EFortNotificationQueueType : uint8;
enum class EFortUIState : uint8;

UCLASS(Abstract, meta=(Category="Fortnite UI"))
class FORTNITEUI_API UFortUIManagerWidget_NUI : public UCommonUserWidget, public IFortUIManagerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Do Not Call In Blueprint Please")
	virtual UFortUINotification* CreateNotification(TSubclassOf<UFortUINotification> UINotificationClass);

	UFUNCTION(BlueprintCallable, Category="UI Manager", meta=(WorldContext="WorldContextObject"))
	static UFortUIManagerWidget_NUI* GetUIManagerWidget(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="UI Manager", meta=(WorldContext="WorldContextObject"))
	static UFortUINotificationQueue* GetUINotificationQueue(UObject* WorldContextObject, EFortNotificationQueueType QueueType);

	UFUNCTION(BlueprintImplementableEvent, Category="UI Manager")
	bool IsShowingModalsConfirmationsErrors();

	UFUNCTION(BlueprintCallable, Category="Fort Dialogs", meta=(WorldContext="WorldContextObject"))
	static void KillConfirmationDialog(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="CampaignHUD")
	void RequestClearConfirmationLayer();

protected:
	UFUNCTION(BlueprintPure, Category="UI Manager", meta=(BlueprintProtected="true", DisplayName="Get Current UI State"))
	EFortUIState _BPGetCurrentUIState() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintProtected="true"))
	bool IsStateContentChildShowing() const;

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="true"))
	void NativeClearLayers();

	UFUNCTION(BlueprintImplementableEvent)
	void OnModalQueueEmptied();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStateEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStateStarted();

	UFUNCTION(BlueprintImplementableEvent, Category="UI Manager|State Management")
	void UpdateStateWidgetContent(UFortUIStateWidget_NUI* StateWidget);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIManagerWidget_NUI", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UNamedSlot> StateContentLayer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIManagerWidget_NUI", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UNamedSlot> ModalLayer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIManagerWidget_NUI", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortErrorWindow> ErrorWindow_Errors;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRestartClientModal> RestartModal;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPinModal> PinModal;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIManagerWidget_NUI", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortConfirmationWindow> ConfirmationWindow_ConfirmationWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIManagerWidget_NUI", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressModal> ProgressModal_Progress;

private:
	UFUNCTION()
	void HandleConfirmationWindowDeactivated(UCommonActivatablePanelLegacy* DeactivatedPanel);

	UFUNCTION()
	void HandleDeactivatedModal(UCommonActivatablePanelLegacy* DeactivatedPanel);

	UFUNCTION()
	void HandleErrorWindowDeactivated(UCommonActivatablePanelLegacy* RemovedPanel);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonActivatablePanelLegacy> CurrentModalWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UCommonActivatablePanelLegacy>> ModalPanelQueue;

	UPROPERTY(EditAnywhere, Category="FortUIManagerWidget_NUI")
	TSubclassOf<UFortPlayerBanned> PlayerBannedScreen;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortUIStateWidget_NUI> CurrentStateWidget;

	UPROPERTY(Transient)
	TObjectPtr<UFortUINotificationManager> NotificationManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<TSubclassOf<UObject>, TObjectPtr<UUserWidget>> TypedWidgetCache;

	UPROPERTY(Transient)
	TArray<FFortDialogDescription_NUI> ConfirmationQueue;

};

