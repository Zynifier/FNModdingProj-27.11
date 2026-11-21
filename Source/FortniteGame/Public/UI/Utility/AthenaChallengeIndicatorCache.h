// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AthenaChallengeIndicatorCache.generated.h"

class AFortPlayerController;
class UFortQuestObjectiveInfo;

UCLASS(MinimalAPI)
class UAthenaChallengeIndicatorCache : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleDynamicQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool bDisplayStatusUpdate, bool bDisplayAnnouncementUpdate);

	UFUNCTION()
	void HandleQuestsUpdated();

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> OwningPlayerController;

};

