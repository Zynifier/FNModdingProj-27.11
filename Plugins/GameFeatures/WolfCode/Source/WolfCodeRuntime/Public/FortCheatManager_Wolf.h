// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_Wolf.generated.h"

UCLASS()
class UFortCheatManager_Wolf : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void WolfEnable(const bool bEnable);

};

