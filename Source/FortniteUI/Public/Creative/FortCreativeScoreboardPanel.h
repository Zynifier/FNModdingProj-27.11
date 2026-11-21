// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonActivatablePanelLegacy.h"
#include "OnlineLinkId.h"
#include "UIManager/AthenaHUDPrimaryContentInterface.h"
#include "FortCreativeScoreboardPanel.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeScoreboardPanel : public UCommonActivatablePanelLegacy, public IAthenaHUDPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void KickOffMatchmaking(FOnlineLinkId IslandToMatchmakeTo);

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativeScoreboardPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle MainMenuInputRowHandle;

};

