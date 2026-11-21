// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "RidingCheatManager.generated.h"

UCLASS()
class URidingCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void RidingSetStaminaPercent(const float StaminaPercent);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void StartRidingActor();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void StopRidingActor();

};

