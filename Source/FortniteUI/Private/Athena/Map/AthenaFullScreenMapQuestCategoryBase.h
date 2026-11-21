// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "AthenaFullScreenMapQuestCategoryBase.generated.h"

UCLASS(Abstract, meta=(Category="Fortnite UI"))
class UAthenaFullScreenMapQuestCategoryBase : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnFocusLostFromCategories();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnFocusSetToCategories();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowNewBang(bool bEnabled);

};

