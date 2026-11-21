// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "FortMainMenuLeaveButtonWrapper.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMainMenuLeaveButtonWrapper : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnTextChanged(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnTimerTextChanged(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnTimerVisibilityChanged(ESlateVisibility InVisibility);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortMainMenuLeaveButtonWrapper", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> ButtonInternal;

private:
	UFUNCTION()
	void HandleLobbyDisconnected();

	UFUNCTION()
	void HandleLobbyStarted();

};

