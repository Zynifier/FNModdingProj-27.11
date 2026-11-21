// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "BattlePassLeaderboard.generated.h"

class UBattlePassLeaderboardListView;
class UCommonButtonLegacy;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassLeaderboard : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SeasonContext;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLeaderboard", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassLeaderboardListView> ListView_Leaderboard;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

};

