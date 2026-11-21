// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Quests/FortAthenaQuestGameplayAbility.h"
#include "FortAthenaQuestGA_QuickBarInfo.generated.h"

class UFortItem;

UCLASS()
class UFortAthenaQuestGA_QuickBarInfo : public UFortAthenaQuestGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void Client_QuickBarsChanged(const TArray<TSoftObjectPtr<UFortItem>>& QuickBarItems);

	UFUNCTION(Server, Reliable)
	void Rep_QuickBarSlotsInformation(const TArray<FGuid>& QuickBarItemGuids);

	UFUNCTION(BlueprintCallable)
	void SendQuickBarSlotsToServer(const TArray<TSoftObjectPtr<UFortItem>>& QuickBarItems);

	UFUNCTION(BlueprintImplementableEvent)
	void Server_QuickBarSlotsUpdated(const TArray<TSoftObjectPtr<UFortItem>>& QuickBarItems);

};

