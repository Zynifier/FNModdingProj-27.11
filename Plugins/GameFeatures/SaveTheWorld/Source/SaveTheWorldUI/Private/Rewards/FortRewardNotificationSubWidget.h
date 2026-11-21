// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActionHandlerInterface.h"
#include "CommonUITypes.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "FortRewardNotificationSubWidget.generated.h"

class UDataTable;
class UFortItem;
class UFortRewardNotificationWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRewardWidgetTransitionDelegate);

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortRewardNotificationSubWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Rewards")
	void Init(UFortRewardNotificationWidget* MainWidget);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnActivated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDeactivated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnNavigationDown();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnNavigationLeft();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnNavigationRight();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnNavigationUp();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnPrimaryAction();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void TransitionIn();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void TransitionOut();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Rewards")
	FOnRewardWidgetTransitionDelegate OnTransitionInComplete;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Rewards")
	FOnRewardWidgetTransitionDelegate OnTransitionOutComplete;

protected:
	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddInputActionHandler(UDataTable* DataTable, FName RowName, FCommonActionCommited CommittedEvent);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void InspectItem(UFortItem* ItemToInspect, int32 QuantityOverride = -1);

	UFUNCTION(BlueprintPure, Category="Rewards")
	void IsPrimaryActionEnabled(bool& bEnabled);

	UFUNCTION(BlueprintPure, Category="Rewards")
	void IsPrimaryActionHidden(bool& bHidden);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void RemoveAllInputActionHandlers();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void RemoveInputActionHandler(FDataTableRowHandle InputActionRow);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void SetInputActionHandlerState(UDataTable* DataTable, FName RowName, EInputActionState State);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void SetPrimaryActionEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void SetPrimaryActionHidden();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void SetPrimaryActionText(FText Text);

	UFUNCTION(BlueprintImplementableEvent, Category="Rewards")
	void TransitionInBegin();

	UFUNCTION(BlueprintImplementableEvent, Category="Rewards")
	void TransitionOutBegin();

};

