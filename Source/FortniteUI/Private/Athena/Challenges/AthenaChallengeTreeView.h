// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Challenges/AthenaChallengeListView.h"
#include "AthenaChallengeTreeView.generated.h"

class UAthenaChallengeTreeEntry_ChallengeSet;

UCLASS()
class UAthenaChallengeTreeView : public UAthenaChallengeListViewBase
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleQuestsUpdated();

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UAthenaChallengeTreeEntry_ChallengeSet> SetHeaderEntryClass;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeTreeView")
	bool bReturnFocusToSelection;

};

