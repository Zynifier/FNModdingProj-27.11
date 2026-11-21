// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "ValkyrieFortniteEditorCheatManager.generated.h"

UCLASS()
class UValkyrieFortniteEditorCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void RequestSolarisCompile();

};

