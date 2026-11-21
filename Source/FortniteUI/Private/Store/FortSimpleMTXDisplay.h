// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Online/FortMcpContext.h"
#include "FortSimpleMTXDisplay.generated.h"

UCLASS(meta=(DisableNativeTick))
class UFortSimpleMTXDisplay : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="TRUE"))
	void OnUpdateAvailableMTX(int32 AvailableBalance);

private:
	UFUNCTION()
	void HandleLocalAccountInfoChanged(FFortPrivateAccountInfo NewInfo);

};

