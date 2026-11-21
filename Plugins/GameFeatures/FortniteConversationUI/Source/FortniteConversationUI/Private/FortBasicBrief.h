// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortConversationOptionBrief.h"
#include "FortBasicBrief.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBasicBrief : public UFortConversationOptionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnChoiceTextReceived(const FText& Text);

};

