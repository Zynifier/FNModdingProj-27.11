// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_Tempest.generated.h"

UCLASS()
class UFortCheatManager_Tempest : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EndTempestStorm(const FString& StormName = TEXT(""));

};

