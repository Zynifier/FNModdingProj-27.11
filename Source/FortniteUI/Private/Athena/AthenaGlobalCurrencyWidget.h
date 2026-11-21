// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaGlobalCurrencyWidget.generated.h"

class UCommonNumericTextBlock;
class UFortItemDefinition;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaGlobalCurrencyWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleOnItemCountChanged(UFortItemDefinition* Definition, int32 Delta);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> CurrencyTotalText;

};

