// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/EndGame/FortPostGameScreen.h"
#include "AthenaReadyUpScreenWidget.generated.h"

class UAthenaKeepPlayingTogetherScreenOverlay;
class UAthenaReadyUpScreenOverlay;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaReadyUpScreenWidget : public UFortPostGameScreen
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaReadyUpScreenWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaReadyUpScreenOverlay> ReadyUpOverlay;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaReadyUpScreenWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaKeepPlayingTogetherScreenOverlay> KeepPlayingTogetherOverlay;

};

