// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortBeanTempCheatManager.generated.h"

UCLASS()
class UFortBeanTempCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void ActivateBeanstalkGFP();

};

