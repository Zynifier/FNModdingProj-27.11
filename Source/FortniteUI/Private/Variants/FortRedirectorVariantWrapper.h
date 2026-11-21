// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "Math/MathFwd.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortRedirectorVariantWrapper.generated.h"

class UFortVariantChannelVM;
class UFortVariantEditorWidgetBase;
class UFortVariantItemVM;
class UPanelWidget;

UCLASS(BlueprintType, Blueprintable)
class UFortRedirectorVariantWrapper : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRotationRequestedEvent, const FRotator&, RotationOffset, const bool, bSnap);

public:
	UFUNCTION(BlueprintCallable)
	void AddVariantChannelVM(UFortVariantChannelVM* ChannelVM);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleRotationOffsetRequested(const FRotator& RotationOffset, const bool bSnap);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleVariantEngaged(const FMcpVariantChannelInfo& InVariantChannelInfo, const UFortVariantItemVM* ItemVM);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFortVariantEditorWidgetBase* VariantPicker;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRedirectorVariantWrapper", meta=(BindWidgetOptional, EditInline="true"))
	UPanelWidget* Container;

	UPROPERTY(BlueprintAssignable)
	FOnRotationRequestedEvent OnRotationRequestedEvent;

private:
	UPROPERTY(Transient, meta=(AllowPrivateAccess))
	UFortVariantItemVM* VariantItemVM;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortVariantChannelVM>> WaitingChannelVMs;

};

