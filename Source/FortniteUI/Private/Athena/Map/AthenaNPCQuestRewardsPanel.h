// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Map/AthenaQuestCustomMapWidget.h"
#include "AthenaNPCQuestRewardsPanel.generated.h"

class UObject;

UCLASS()
class FORTNITEUI_API UAthenaNPCQuestRewardsPanel : public UAthenaQuestCustomMapWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Show"))
	void BP_Show(const FText& NPCTitle, const TSoftObjectPtr<UObject>& NPCPicture, const bool bIsLocked);

};

