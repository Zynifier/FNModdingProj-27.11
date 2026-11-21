// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaRespawnBase.generated.h"

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class ERespawnUIState : uint8
{
	Hidden = 0,
	ShowRespawnEnabled = 1,
	ShowRespawnDisabled = 2,
};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaRespawnBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateLives(int32 Lives);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateRespawnState(bool bEnabled);

	UFUNCTION()
	void UpdateAllUI();

	UPROPERTY(Transient)
	ERespawnUIState RespawnState;

};

