// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaMapPlayersLeftWidget.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapPlayersLeftWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxSquadSizeSet(int32 MaxSquadSize);

private:
	UFUNCTION()
	void HandlePlayersLeftChanged(int32 NumPlayersLeft);

	UFUNCTION()
	void HandleTeamsLeftChanged(int32 NumTeamsLeft);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayersTeamsLeft;

	UPROPERTY(EditDefaultsOnly, Category="AthenaMapPlayersLeftWidget")
	FText PlayersTeamsLeftTextFormat;

};

