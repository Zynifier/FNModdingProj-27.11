// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Map/AthenaFullScreenMapQuestCategoryBase.h"
#include "AthenaFullScreenMapQuestInactiveCategoryButton.generated.h"

UCLASS(Abstract, meta=(Category="Fortnite UI"))
class UAthenaFullScreenMapQuestInactiveCategoryButton : public UAthenaFullScreenMapQuestCategoryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_Populate(const FText& Title);

};

