// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Engine/DataTable.h"
#include "CommonButtonLegacy.generated.h"

class UCommonActivatablePanelLegacy;
class UCommonButtonBase;
class UCommonButtonLegacy;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCommonButtonClicked, UCommonButtonLegacy*, Button);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCommonSelectedStateChanged, UCommonButtonLegacy*, Button, bool, Selected);

/** Custom UButton override that allows us to disable clicking without disabling the widget entirely */
UCLASS(meta=(DevelopmentStatus="Experimental"))
class UCommonButtonInternalLegacy : public UCommonButtonInternalBase
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Common UI", DisableNativeTick))
class COMMONUILEGACY_API UCommonButtonLegacy : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	//@TODO: DarenC - Remove parent class doesn't have OldPanel param so signature difference means we need a new method & redirector for BP's .
// For now this is needed for legacy?

	UFUNCTION(BlueprintCallable, Category="Common Button|Setters")
	void SetTriggeredInputActionLegacy(const FDataTableRowHandle& InputActionRow, UCommonActivatablePanelLegacy* OldPanel);

protected:
	/** Legacy codebases will be overiding w.r.t CommonButton, provide an interface and call any overrides they might have. */
	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FCommonSelectedStateChanged OnSelectedChanged;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FCommonButtonClicked OnButtonClicked;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FCommonButtonClicked OnButtonDoubleClicked;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FCommonButtonClicked OnButtonHovered;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FCommonButtonClicked OnButtonUnhovered;

private:
	UFUNCTION()
	void HandleOnButtonClicked(UCommonButtonBase* Button);

	UFUNCTION()
	void HandleOnButtonDoubleClicked(UCommonButtonBase* Button);

	UFUNCTION()
	void HandleOnButtonHovered(UCommonButtonBase* Button);

	UFUNCTION()
	void HandleOnButtonUnhovered(UCommonButtonBase* Button);

	UFUNCTION()
	void HandleOnSelectedChanged(UCommonButtonBase* Button, bool InSelected);

};

