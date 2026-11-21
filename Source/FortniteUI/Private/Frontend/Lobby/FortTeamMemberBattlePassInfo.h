// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortTeamMemberEntryBase.h"
#include "FortTeamMemberBattlePassInfo.generated.h"

class UPanelWidget;
class UTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortTeamMemberXPBoostInfo : public UFortTeamMemberEntryBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_BattlePassOwnerInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_BattlePassSelfXPBoost;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_EventXPBoost;

};

