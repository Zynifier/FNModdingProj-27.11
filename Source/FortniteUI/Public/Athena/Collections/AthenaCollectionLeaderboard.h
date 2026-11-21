// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaCollectionLeaderboard.generated.h"

class UDynamicEntryBox;
class UScrollBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionLeaderboard : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AthenaCollectionLeaderboard", meta=(ClampMin="0.010000"))
	float LeaderboardScrollSpeed;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionLeaderboard", meta=(ClampMin="0.000000"))
	float LeaderboardScrollInitialDelay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Leaderboard;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaCollectionLeaderboardEntry"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Leaderboard;

};

