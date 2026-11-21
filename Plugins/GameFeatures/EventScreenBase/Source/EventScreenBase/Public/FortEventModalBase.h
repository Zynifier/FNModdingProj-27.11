// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortEventModalBase.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventModalBase : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CloseModal();

};

