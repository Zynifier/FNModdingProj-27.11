// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaBroadcastMapPanelBase.generated.h"

class UAthenaMapLayer;
class UAthenaSpectatorMapPlayerListBase;
class UCommonButtonLegacy;
class UCommonWidgetSwitcherLegacy;
class UFortBroadcasterMapSettings;

UCLASS(BlueprintType, meta=(DisableNativeTick))
class UAthenaBroadcastMapPanelBase : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBroadcastMapPanelBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpectatorMapPlayerListBase> PlayerList;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBroadcastMapPanelBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaMapLayer> AthenaMapLayer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBroadcastMapPanelBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> LhsSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBroadcastMapPanelBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CycleSideBar;

	UPROPERTY(EditAnywhere, Category="AthenaBroadcastMapPanelBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CycleSideBarRowHandle;

	UPROPERTY(EditAnywhere, Category="AthenaBroadcastMapPanelBase")
	TSubclassOf<UFortBroadcasterMapSettings> MapSettingsClass;

};

