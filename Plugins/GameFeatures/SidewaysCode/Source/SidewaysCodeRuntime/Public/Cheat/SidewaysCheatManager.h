// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "SidewaysCheatManager.generated.h"

enum class ESidewaysState : uint8;

UCLASS()
class USidewaysCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetSidewaysState(ESidewaysState SidewaysState);

};

