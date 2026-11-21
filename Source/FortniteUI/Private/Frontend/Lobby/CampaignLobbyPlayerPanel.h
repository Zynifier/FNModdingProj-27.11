// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/FortLobbyPlayerPanel.h"
#include "CampaignLobbyPlayerPanel.generated.h"

class UCommonButtonLegacy;
class UCommonNumericTextBlock;

UCLASS(Abstract)
class UCampaignLobbyPlayerPanel : public UFortLobbyPlayerPanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowBackbackChanged(bool bShowBackpack);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowHeadAccessoryChanged(bool bShowHeadAccessory);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ShowHeadAccessory;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ShowBackpack;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> Number_PowerLevel;

};

