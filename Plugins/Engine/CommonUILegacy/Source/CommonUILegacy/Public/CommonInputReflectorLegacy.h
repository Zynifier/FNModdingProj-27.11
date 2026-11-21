// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActionHandlerInterface.h"
#include "CommonUserWidget.h"
#include "CommonInputReflectorLegacy.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Common UI", DisableNativeTick))
class COMMONUILEGACY_API UCommonInputReflectorLegacy : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	/** Let the layout have a chance to add a new button that we're tracking as an active button */
	UFUNCTION(BlueprintImplementableEvent, Category="CommonInputReflector")
	void OnButtonAdded(UCommonButtonLegacy* AddedButton, const FCommonInputActionHandlerData& Data);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CommonInputReflector")
	TSubclassOf<UCommonButtonLegacy> ButtonType;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UCommonButtonLegacy>> ActiveButtons;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UCommonButtonLegacy>> InactiveButtons;

};

