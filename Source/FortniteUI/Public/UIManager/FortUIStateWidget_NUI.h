// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortClientEventInterface.h"
#include "Social/FortSocialPanelContainerInterface.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortUIStateWidget_NUI.generated.h"

class UWidget;
enum class EFortUIState : uint8;

USTRUCT(BlueprintType)
struct FContentPushState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Details")
	bool bHideHeader;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Details")
	bool bHideFooter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Details")
	bool bHideChatWidget;

};

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UFortUIStateWidget_NUI : public UFortActivatablePanel, public IFortClientEventInterface, public IFortSocialPanelContainerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetTopBarWidget() const;

	UFUNCTION(BlueprintPure, Category="FortUIState")
	virtual bool IsContentOnStack() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortUIState|State Management")
	void OnEnterState(EFortUIState PreviousUIState);

	UFUNCTION(BlueprintImplementableEvent, Category="FortUIState|State Management")
	void OnExitState(EFortUIState NextUIState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenSocialMenu();

	UFUNCTION(BlueprintCallable, Category="FortUIState|State Management")
	void PopAllContentWidgets();

	UFUNCTION(BlueprintCallable, Category="FortUIState|State Management")
	UWidget* PopContentWidget();

	UFUNCTION(BlueprintCallable, Category="FortUIState|State Management")
	void PushContentWidget(UWidget* Widget);

	UFUNCTION(BlueprintCallable, Category="FortUIState|State Management")
	void PushContentWidgetAdvanced(UWidget* Widget, bool bHideHeader, bool bHideFooter, bool bHideChatWidget);

	UFUNCTION(BlueprintCallable)
	virtual void RequestOpenSocialPanel();

	UFUNCTION(BlueprintCallable, Category="FortUIState|State Management")
	void SetFrontEndVisibility(bool bHideHeader, bool bHideFooter, bool bHideChatWidget);

	UFUNCTION(BlueprintCallable, Category="FortUIState|State Management")
	void SetSocialButtonEnabled(bool bEnabled);

protected:
	UFUNCTION()
	void DynamicHandleLoadingScreenVisibilityChanged(bool IsVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAutoHideBuildingMaterialsChanged(bool AutoHide);

	UFUNCTION(BlueprintImplementableEvent, Category="FortUIState|State Management")
	void OnFrontEndVisibilityUpdated(bool bHideHeader, bool bHideFooter, bool bHideChatWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHUDScaleChanged(float HUDScale);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadingScreenVisibilityChanged(bool IsVisible);

	UFUNCTION(BlueprintImplementableEvent, Category="FortUIState|State Management")
	void OnSocialButtonEnabled(bool bEnabled);

	UFUNCTION(BlueprintNativeEvent, Category="FortUIState|State Management")
	UWidget* PopContentWidgetInternal(FContentPushState State);

	UFUNCTION(BlueprintNativeEvent, Category="FortUIState|State Management")
	void PushContentWidgetInternal(UWidget* Widget, FContentPushState State);

	UPROPERTY(Transient)
	TArray<FContentPushState> StackStates;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UWidget*> StackWidgets;

};

