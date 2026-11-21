// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "AthenaFullScreenMapQuestProductButton.generated.h"

class UTexture2D;

UCLASS(Abstract, meta=(Category="Fortnite UI"))
class UAthenaFullScreenMapQuestProductButton : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_Populate(const FText& DisplayName, const TSoftObjectPtr<UTexture2D>& Icon);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_ProductExpanded(const bool bExpanded);

};

