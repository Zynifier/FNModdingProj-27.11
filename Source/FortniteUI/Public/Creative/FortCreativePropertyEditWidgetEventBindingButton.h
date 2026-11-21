// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortCreativePropertyEditWidgetEventBindingButton.generated.h"

class UCommonTextBlock;
enum class EFortGameplayEventReferenceType : uint8;

UCLASS(Abstract, Blueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UFortCreativePropertyEditWidgetEventBindingButton : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEventReferenceTypeSet(const EFortGameplayEventReferenceType EventReferenceType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsDisplayingButtonOptionsSet(const bool bIsDisplayingButtonOptions);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTextSet(const FText& Text);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditWidgetEventBindingButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Name;

};

