// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaPlayerTeamKillsBase.generated.h"

class AFortPlayerStateAthena;
class UAthenaPlayerViewModel;
class UTextBlock;

UCLASS(meta=(DisableNativeTick))
class UAthenaPlayerTeamKillsBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandlePlayerViewTargetChanged();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerTeamKillsBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> KillsText;

	UPROPERTY()
	TObjectPtr<UAthenaPlayerViewModel> PlayerVM;

private:
	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> SourcePlayerState;

};

