// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "QuestScreen_Legacy.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestScreen_Legacy : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category="Quest")
	void ProcessPendingSeenQuestItems();

};

