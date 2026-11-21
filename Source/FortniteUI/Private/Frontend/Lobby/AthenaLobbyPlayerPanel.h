// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/FortLobbyPlayerPanel.h"
#include "AthenaLobbyPlayerPanel.generated.h"

class UCommonButtonBase;
class UTextBlock;

UCLASS(Abstract)
class UAthenaLobbyPlayerPanel : public UFortLobbyPlayerPanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHasBattlePassUpdated(bool bHasBattlePass);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsMutedUpdated(bool bIsMuted);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLobbyPlayerPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Mute;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ViewProfile;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_BattlePassTier;

};

