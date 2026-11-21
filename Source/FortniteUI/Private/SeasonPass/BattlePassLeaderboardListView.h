// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "BattlePassLeaderboardListView.generated.h"

UCLASS(meta=(EntryClass="AthenaFeatTimelineListEntryBase"))
class UBattlePassLeaderboardListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UBattlePassLeaderboardListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditAnywhere, Category="BattlePassLeaderboardListView")
	float FirstEntrySpacing;

	UPROPERTY(EditAnywhere, Category="BattlePassLeaderboardListView")
	float EntrySpacing;

};

