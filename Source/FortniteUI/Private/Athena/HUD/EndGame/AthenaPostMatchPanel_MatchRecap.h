// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/EndGame/AthenaPostMatchPanel.h"
#include "AthenaPostMatchPanel_MatchRecap.generated.h"

class UFortMatchXPRecap;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaPostMatchPanel_MatchRecap : public UAthenaPostMatchPanel
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleReturnToIslandButtonShown(bool bShown);

protected:
	UFUNCTION()
	void HandleFadeOutOverlay();

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaPostMatchPanel_MatchRecap", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchXPRecap> XPRecap;

};

