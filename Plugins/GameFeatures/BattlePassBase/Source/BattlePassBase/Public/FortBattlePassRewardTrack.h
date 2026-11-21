// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Math/MathFwd.h"
#include "FortBattlePassRewardTrack.generated.h"

class UCommonButtonBase;
class UFortBattlePassPrerequisiteHeader;
class UFortBattlePassTileBase;
class UGridPanel;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassRewardTrack : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPageSelected();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPageUnselected();

private:
	UPROPERTY(EditDefaultsOnly, Category="FortBattlePassRewardTrack")
	TSubclassOf<UFortBattlePassTileBase> RewardTileClass;

	UPROPERTY(EditDefaultsOnly, Category="FortBattlePassRewardTrack")
	TSubclassOf<UFortBattlePassTileBase> RewardEmptyTileClass;

	UPROPERTY(EditDefaultsOnly, Category="FortBattlePassRewardTrack")
	TSubclassOf<UFortBattlePassPrerequisiteHeader> PrerequisiteHeaderClass;

	UPROPERTY(EditDefaultsOnly, Category="FortBattlePassRewardTrack")
	FVector2D GridCellPadding;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UGridPanel> GridPanel_Rewards;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBattlePassTileBase> DefaultFocusTile;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UCommonButtonBase> LastFocusedTile;

};

