// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonInputTypeEnum.h"
#include "FortCreativePropertyEditorDialogBase.generated.h"

class UCanvasPanelSlot;
class UCreativePropertyEditWidgetUserOptionBase;
class UObject;
class UWidgetAnimation;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativePropertyEditorDialogBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void AddOption(UObject* Object);

	UFUNCTION(BlueprintCallable)
	void Close();

	UFUNCTION(BlueprintCallable)
	void Open();

	UFUNCTION(BlueprintCallable)
	virtual void Reset();

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortCreativePropertyEditorDialogBase", meta=(EditInline="true"))
	TObjectPtr<UCanvasPanelSlot> PanelSlot;

protected:
	UFUNCTION(BlueprintPure)
	UCreativePropertyEditWidgetUserOptionBase* GetOwningEditWidget() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnClose();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInputMethodChanged(const ECommonInputType InputType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIntroAnimFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpen();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOutroAnimFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowLoadingSpinnerChanged(const bool bShowingLoadingSpinner);

	UPROPERTY(BlueprintReadOnly, Category="FortCreativePropertyEditorDialogBase")
	bool bIsOpen;

	UPROPERTY(EditDefaultsOnly, Category="Dialog")
	bool bShouldDisableMessageKnobsDialogActionsWhileOpen;

private:
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_IntroOutro;

};

