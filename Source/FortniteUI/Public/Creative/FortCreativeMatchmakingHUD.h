// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCreativeMatchmakingHUD.generated.h"

class AFortPlayerControllerAthena;
class UFortKeybindWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeMatchmakingHUD : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnKeybindComplete(AFortPlayerControllerAthena* FortPC);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnMatchmakingComplete(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_PartyLeaderSetup();

	UFUNCTION()
	void CancelMatchmaking();

	UFUNCTION()
	void OnMatchmakingComplete(bool bSuccess);

	UFUNCTION(BlueprintCallable)
	void Open();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMatchmakingHUD", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindWidget_MMHUD;

};

