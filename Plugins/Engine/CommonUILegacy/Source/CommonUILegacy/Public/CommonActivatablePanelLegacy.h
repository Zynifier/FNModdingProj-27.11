// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActionHandlerInterface.h"
#include "CommonActivatableWidget.h"
#include "CommonUITypes.h"
#include "Engine/DataTable.h"
#include "CommonActivatablePanelLegacy.generated.h"

class UCommonActivatablePanelLegacy;
class UCommonPopupMenuLegacy;
class UDataTable;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWidgetActivationChangedDynamic, UCommonActivatablePanelLegacy*, Panel);

UCLASS(BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Common UI", DisableNativeTick))
class COMMONUILEGACY_API UCommonActivatablePanelLegacy : public UCommonActivatableWidget, public ICommonActionHandlerInterface
{
	GENERATED_BODY()

public:
	/** Set an input action handler up for a press action */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void AddInputActionHandler(UDataTable* DataTable, FName RowName, FCommonActionCommited CommitedEvent);

	/** Set an input action handler up for a press action with a popup menu */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void AddInputActionHandlerWithPopup(UDataTable* DataTable, FName RowName, FCommonActionCommited CommitedEvent, UCommonPopupMenuLegacy* PopupMenu = nullptr);

	/** Set an input action handler up for a hold action */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void AddInputActionHandlerWithProgress(UDataTable* DataTable, FName RowName, FCommonActionCommited CommitedEvent, FCommonActionProgressSingle ProgressEvent);

	/** Set an input action handler up for a hold action with a popup menu */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void AddInputActionHandlerWithProgressPopup(UDataTable* DataTable, FName RowName, FCommonActionCommited CommitedEvent, FCommonActionProgressSingle ProgressEvent, UCommonPopupMenuLegacy* PopupMenu = nullptr);

	/** Add a press action with no handler */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void AddInputActionNoHandler(UDataTable* DataTable, FName RowName);

	/** Called to start the intro sequence of the panel */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void BeginIntro();

	/** Called to start the Outro sequence of the panel */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void BeginOutro();

	/** Gets the list of input action rows for visualization of input actions that this activatable panel handles */
	UFUNCTION(BlueprintPure, Category="ActivatablePanel")
	bool GetInputActions(TArray<FCommonInputActionHandlerData>& InputActionDataRows) const;

	UFUNCTION(BlueprintPure, Category="ActivatablePanel")
	bool HasInputActionHandler(FDataTableRowHandle InputActionRow) const;

	/** True if this widget is currently in the input manager panel stack */
	UFUNCTION(BlueprintPure, Category="ActivatablePanel")
	bool IsInActivationStack() const;

	/** True if this widget is currently introed */
	UFUNCTION(BlueprintPure, Category="ActivatablePanel")
	bool IsIntroed() const;

	/** Removes a panel off of its associated stack */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	virtual void PopPanel();

	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void RemoveAllInputActionHandlers();

	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void RemoveInputActionHandler(FDataTableRowHandle InputActionRow);

	/** Add a specific handlers state */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void SetActionHandlerState(const UDataTable* DataTable, FName RowName, EInputActionState State);

	/** Add a specific handlers state */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void SetActionHandlerStateFromHandle(FDataTableRowHandle InputActionRow, EInputActionState State);

	/** Add a specific handlers state 
	 *  The DisabledCommitEvent will be called if the user attempts this action while disabled
	 */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void SetActionHandlerStateFromHandleWithDisabledCommitEvent(FDataTableRowHandle InputActionRow, EInputActionState State, FCommonActionCommited DisabledCommitEvent);

	/** Add a specific handlers state
	 *  The DisabledCommitEvent will be called if the user attempts this action while disabled
	 */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void SetActionHandlerStateWithDisabledCommitEvent(UDataTable* DataTable, FName RowName, EInputActionState State, FCommonActionCommited DisabledCommitEvent);

	/** Set an input action handler up for a press action */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void SetInputActionHandler(FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent);

	/** Set an input action handler up for a press action with a popup menu */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void SetInputActionHandlerWithPopupMenu(FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent, UCommonPopupMenuLegacy* PopupMenu = nullptr);

	/** Set an input action handler up for a hold action */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void SetInputActionHandlerWithProgress(FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent, FCommonActionProgressSingle ProgressEvent);

	/** Set an input action handler up for a hold action with a pop-up menu */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void SetInputActionHandlerWithProgressPopupMenu(FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent, FCommonActionProgressSingle ProgressEvent, UCommonPopupMenuLegacy* PopupMenu = nullptr);

	/** Fires when the widget is activated. */
	UPROPERTY(BlueprintAssignable)
	FOnWidgetActivationChangedDynamic OnWidgetActivated;

	/** Fires when the widget is deactivated. */
	UPROPERTY(BlueprintAssignable)
	FOnWidgetActivationChangedDynamic OnWidgetDeactivated;

	virtual bool HandleHoldInput(int32 ControllerId, FKey KeyPressed, EInputEvent EventType, bool& bPassThrough) override;

	virtual bool HandlePressInput(FKey KeyPressed, EInputEvent EventType, bool& bPassThrough) override;

	virtual bool HandleTouchInput(uint32 TouchId, ETouchType::Type TouchType, const FVector2D& TouchLocation, bool& bPassThrough) override;

	virtual void UpdateCurrentlyHeldAction(float InDeltaTime) override;

	virtual void TriggerFirstMatchingInputAction(int32 ControllerId, const FCommonInputActionDataBase& InInputActionData, bool bHoldAction) override;

protected:
	/** Call when the Intro is finished */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void EndIntro();

	/** Call when the Outro is finished */
	UFUNCTION(BlueprintCallable, Category="ActivatablePanel")
	void EndOutro();

	UFUNCTION(BlueprintImplementableEvent, Category="ActivatablePanel")
	void OnAddedToActivationStack();

	/**
	 *	Used to do custom Intro for the panel
	 *	NOTE: This function is meant to only be overridden and not have the parent called.
	 *        The base implementation simply calls EndIntro.
	 */
	UFUNCTION(BlueprintNativeEvent, Category="ActivatablePanel")
	void OnBeginIntro();

	/**
	 *	Used to do custom Outro for the panel
	 *	NOTE: This function is meant to only be overridden and not have the parent called.
	 *        The base implementation simply calls EndOutro.
	 */
	UFUNCTION(BlueprintNativeEvent, Category="ActivatablePanel")
	void OnBeginOutro();

	UFUNCTION(BlueprintImplementableEvent, Category="ActivatablePanel")
	void OnInputModeChanged(bool bUsingGamepad);

	UFUNCTION(BlueprintImplementableEvent, Category="ActivatablePanel")
	void OnRemovedFromActivationStack();

	UFUNCTION(BlueprintImplementableEvent, Category="ActivatablePanel")
	void OnTransitionedBySwitcher();

	/** Prevents unhandled actions from going further down the stack of activatable panels */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ActivatablePanel")
	bool bConsumeAllActions;

	/** Whether or not actions can be exposed by a reflector widget */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ActivatablePanel")
	bool bExposeActionsExternally;

	/**
	 *	Let's the input handling go past the stack and let's the global input handler have a chance
	 *	to handle the input. NOTE: Should not be combined with input actions registered using
	 *	SetInputActionHandler or SetInputActionHandlerWithProgress.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ActivatablePanel")
	bool bShouldBypassStack;

};

