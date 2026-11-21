// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "RebootRallyQRCode.generated.h"

UCLASS(meta=(DisableNativeTick))
class URebootRallyQRCode : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetIsInvite(bool bIsInvite);

};

