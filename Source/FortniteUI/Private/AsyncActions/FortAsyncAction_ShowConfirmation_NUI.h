// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Styling/SlateBrush.h"
#include "FortDialogTypes.h"
#include "FortAsyncAction_ShowConfirmation_NUI.generated.h"

class UFortAsyncAction_ShowConfirmation_NUI;
class UFortLocalPlayer;
class ULocalPlayer;
class UObject;
class UWidget;
enum class EFortDialogResult : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortConfirmationResultDelegate_NUI, EFortDialogResult, Result, FName, ResultName);

UCLASS()
class UFortAsyncAction_ShowConfirmation_NUI : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Dialogs", meta=(BlueprintInternalUseOnly="true", WorldContext="InWorldContextObject"))
	static UFortAsyncAction_ShowConfirmation_NUI* ShowConfirmationDialog_NUI(UObject* InWorldContextObject, FSlateBrush Icon, FText Title, FText Message, const TArray<FConfirmationDialogAction>& ConfirmButtonInputActions, const FName& DeclineButtonInputAction, UWidget* AdditionalContent = nullptr, UWidget* LeftAdditionalContent = nullptr, ULocalPlayer* TargetPlayer = nullptr);

	UFUNCTION(BlueprintCallable, Category="Fort Dialogs", meta=(BlueprintInternalUseOnly="true", WorldContext="InWorldContextObject"))
	static UFortAsyncAction_ShowConfirmation_NUI* ShowSimpleConfirmationDialog_CustomInput(UObject* InWorldContextObject, FSlateBrush Icon, FText Title, FText Message, FName ConfirmAction, FName DeclineAction, UWidget* AdditionalContent = nullptr, UWidget* LeftAdditionalContent = nullptr, bool Cancelable = false, ULocalPlayer* TargetPlayer = nullptr);

	UFUNCTION(BlueprintCallable, Category="Fort Dialogs", meta=(BlueprintInternalUseOnly="true", WorldContext="InWorldContextObject"))
	static UFortAsyncAction_ShowConfirmation_NUI* ShowSimpleConfirmationDialog_NUI(UObject* InWorldContextObject, FSlateBrush Icon, FText Title, FText Message, bool bShowConfirm, bool bShowDecline, UWidget* AdditionalContent = nullptr, UWidget* LeftAdditionalContent = nullptr, ULocalPlayer* TargetPlayer = nullptr);

	UPROPERTY(BlueprintAssignable)
	FFortConfirmationResultDelegate_NUI DialogResult;

private:
	UPROPERTY(Transient)
	TObjectPtr<UObject> WorldContextObject;

	UPROPERTY(Transient)
	TObjectPtr<UFortLocalPlayer> TargetLocalPlayer;

	UPROPERTY()
	FFortDialogDescription_NUI Description;

};

