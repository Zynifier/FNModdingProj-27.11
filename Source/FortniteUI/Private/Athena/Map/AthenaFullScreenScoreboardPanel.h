// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/MinigameWidgetBase.h"
#include "AthenaFullScreenScoreboardPanel.generated.h"

class UScrollBox;

UCLASS(Abstract, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaFullScreenScoreboardPanel : public UMinigameWidgetBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenScoreboardPanel", meta=(BindWidget, EditInline="true"))
	UScrollBox* DataScrollBox;

};

