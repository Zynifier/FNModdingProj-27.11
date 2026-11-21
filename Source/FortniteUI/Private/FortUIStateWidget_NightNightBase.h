// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "FortUIStateWidget_NightNightBase.generated.h"

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortUIStateWidget_NightNightBase : public UFortUIStateWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnToggleUIChanged(bool bHideUI);

private:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortUIStateWidget_NightNightBase")
	bool bEnableNightNightPatchCheck;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortUIStateWidget_NightNightBase")
	float PatchCheckIntervalSeconds;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortUIStateWidget_NightNightBase")
	float PatchCheckIntervalJitterSeconds;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortUIStateWidget_NightNightBase")
	FDateTime GameShutdownTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortUIStateWidget_NightNightBase")
	float GameShutdownTimeJitterSeconds;

};

