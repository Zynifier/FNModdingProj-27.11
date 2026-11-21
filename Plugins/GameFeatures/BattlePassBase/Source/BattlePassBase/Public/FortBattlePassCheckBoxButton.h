// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortBattlePassCheckBoxButton.generated.h"

UCLASS(Abstract)
class BATTLEPASSBASE_API UFortBattlePassCheckBoxButton : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStateChanged(const bool bNewIsChecked);

};

