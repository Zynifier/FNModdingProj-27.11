// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Math/MathFwd.h"
#include "PageNavigator/FortNavigatablePageInterface.h"
#include "FortBattlePassRewardGrid.generated.h"

class UCommonButtonBase;
class UFortBattlePassRewardGridHeader;
class UFortBattlePassTileBase;
class UGridPanel;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassRewardGrid : public UCommonActivatableWidget, public IFortNavigatablePage
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPageSelected();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPageUnselected();

private:
	UPROPERTY(EditAnywhere, Category="FortBattlePassRewardGrid")
	TSubclassOf<UFortBattlePassTileBase> GridTileClass;

	UPROPERTY(EditAnywhere, Category="FortBattlePassRewardGrid")
	TSubclassOf<UFortBattlePassTileBase> GridEmptyTileClass;

	UPROPERTY(EditAnywhere, Category="FortBattlePassRewardGrid")
	FVector2D GridCellPadding;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassRewardGrid", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortBattlePassRewardGridHeader> PageHeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UGridPanel> GridPanel_Rewards;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBattlePassTileBase> DefaultFocusTile;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UCommonButtonBase> LastFocusedTile;

};

