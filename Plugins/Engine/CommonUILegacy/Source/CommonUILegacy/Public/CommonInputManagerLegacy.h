// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActionHandlerInterface.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "CommonInputManagerLegacy.generated.h"

class ICommonActionHandlerInterface;
class UCommonActivatablePanelLegacy;
class UCommonGlobalInputHandlerLegacy;

UENUM()
enum class EOperation : uint8
{
	Intro = 0,
	Outro = 1,
	Push = 2,
	Pop = 3,
	Invalid = 4,
};

USTRUCT()
struct FOperation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EOperation Operation;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonActivatablePanelLegacy> Panel;

	UPROPERTY()
	bool bIntroPanel;

	UPROPERTY()
	bool bActivatePanel;

	UPROPERTY()
	bool bOutroPanelBelow;

};

UCLASS()
class COMMONUILEGACY_API UCommonInputManagerLegacy : public UObject
{
	GENERATED_BODY()

public:
	/** Gets the list of actions that can be triggered */
	UFUNCTION(BlueprintCallable, Category="CommonInputManager")
	bool GetAvailableInputActions(TArray<FCommonInputActionHandlerData>& AvailableInputActions);

	/** Get global input handler priority filter level; no handlers below this priority will be executed */
	UFUNCTION(BlueprintPure, Category="CommonInputManager")
	int32 GetGlobalInputHandlerPriorityFilter() const;

	UFUNCTION(BlueprintPure, Category="CommonInputManager")
	UCommonActivatablePanelLegacy* GetTopPanel() const;

	UFUNCTION(BlueprintPure, Category="CommonInputManager")
	bool IsInputSuspended() const;

	UFUNCTION(BlueprintPure, Category="CommonInputManager")
	bool IsPanelOnStack(const UCommonActivatablePanelLegacy* InPanel) const;

	/** Pops the specified activatable panel from the panel stack */
	UFUNCTION(BlueprintCallable, Category="CommonInputManager")
	void PopActivatablePanel(UCommonActivatablePanelLegacy* ActivatablePanel);

	/** Pushes the specified activatable panel on the panel stack */
	UFUNCTION(BlueprintCallable, Category="CommonInputManager")
	void PushActivatablePanel(UCommonActivatablePanelLegacy* ActivatablePanel, bool bIntroPanel = true, bool bOutroPanelBelow = true);

	UFUNCTION(BlueprintCallable, Category="CommonInputManager")
	void ResumeStartingOperationProcessing();

	/** Set global input handler priority filter level; no handlers below this priority will be executed */
	UFUNCTION(BlueprintCallable, Category="CommonInputManager")
	void SetGlobalInputHandlerPriorityFilter(int32 InFilterPriority = 0);

	/** Start listening for an existing held action on an activatable panel */
	UFUNCTION(BlueprintCallable, Category="CommonInputManager")
	bool StartListeningForExistingHeldAction(const FDataTableRowHandle& InputActionDataRow, const FCommonActionCompleteSingle& CompleteEvent, const FCommonActionProgressSingle& ProgressEvent);

	/** Stop listening for an existing held action on an activatable panel */
	UFUNCTION(BlueprintCallable, Category="CommonInputManager")
	bool StopListeningForExistingHeldAction(const FDataTableRowHandle& InputActionDataRow, const FCommonActionCompleteSingle& CompleteEvent, const FCommonActionProgressSingle& ProgressEvent);

	UFUNCTION(BlueprintCallable, Category="CommonInputManager")
	void SuspendStartingOperationProcessing();

private:
	UPROPERTY()
	TScriptInterface<ICommonActionHandlerInterface> CurrentlyHeldActionInputHandler;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UCommonActivatablePanelLegacy>> ActivatablePanelStack;

	/** The global input handler for other user widgets such as buttons, tab lists, etc.*/
	UPROPERTY()
	TObjectPtr<UCommonGlobalInputHandlerLegacy> GlobalInputHandler;

	UPROPERTY()
	TArray<FOperation> Operations;

};

