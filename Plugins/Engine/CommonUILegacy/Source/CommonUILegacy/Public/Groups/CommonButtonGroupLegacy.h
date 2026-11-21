// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Groups/CommonButtonGroupBase.h"
#include "CommonButtonGroupLegacy.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSimpleButtonGroupDelegate, UCommonButtonLegacy*, AssociatedButton, int32, ButtonIndex);

/** 
 * Manages an arbitrary collection of CommonButton widgets.
 * Ensures that no more (and optionally, no less) than one button in the group is selected at a time
 */
UCLASS(BlueprintType)
class COMMONUILEGACY_API UCommonButtonGroupLegacy : public UCommonButtonGroupBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="BaseButtonGroup", meta=(WorldContext="ContextObject"))
	static UCommonButtonGroupLegacy* CreateButtonGroup(UObject* ContextObject, bool bInSelectionRequired);

	UFUNCTION(BlueprintPure, Category="BaseButtonGroup")
	UCommonButtonLegacy* GetButtonAtIndex(int32 Index) const;

	UFUNCTION(BlueprintPure, Category="BaseButtonGroup")
	UCommonButtonLegacy* GetSelectedButton() const;

	UPROPERTY(BlueprintAssignable)
	FSimpleButtonGroupDelegate OnSelectedButtonChanged;

	UPROPERTY(BlueprintAssignable)
	FSimpleButtonGroupDelegate OnHoveredButtonChanged;

	UPROPERTY(BlueprintAssignable)
	FSimpleButtonGroupDelegate OnButtonClicked;

	UPROPERTY(BlueprintAssignable)
	FSimpleButtonGroupDelegate OnButtonDoubleClicked;

protected:
	UFUNCTION()
	virtual void OnButtonHovered(UCommonButtonLegacy* BaseButton);

	UFUNCTION()
	virtual void OnButtonUnhovered(UCommonButtonLegacy* BaseButton);

	UFUNCTION()
	virtual void OnHandleButtonClicked(UCommonButtonLegacy* BaseButton);

	UFUNCTION()
	virtual void OnHandleButtonDoubleClicked(UCommonButtonLegacy* BaseButton);

	/** Legacy codebases will be overiding w.r.t CommonButton, provide an interface and call any overrides they might have. */
	UFUNCTION()
	virtual void OnSelectionStateChanged(UCommonButtonLegacy* BaseButton, bool bIsSelected);

private:
	UFUNCTION()
	void HandleNativeOnButtonClicked(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex);

	UFUNCTION()
	void HandleNativeOnButtonDoubleClicked(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex);

	UFUNCTION()
	void HandleNativeOnHoveredButtonChanged(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex);

	UFUNCTION()
	void HandleNativeOnSelectedButtonChanged(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex);

	UFUNCTION()
	void HandleOnButtonClicked(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex);

	UFUNCTION()
	void HandleOnButtonDoubleClicked(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex);

	UFUNCTION()
	void HandleOnHoveredButtonChanged(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex);

	UFUNCTION()
	void HandleOnSelectedButtonChanged(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex);

};

