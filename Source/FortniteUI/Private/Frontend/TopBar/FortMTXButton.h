// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "Online/FortMcpContext.h"
#include "FortMTXButton.generated.h"

class UCommonNumericTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMTXButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CancelInterpolation();

private:
	UFUNCTION()
	void HandleLocalAccountInfoChanged(FFortPrivateAccountInfo NewInfo);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> Text_Amount;

};

