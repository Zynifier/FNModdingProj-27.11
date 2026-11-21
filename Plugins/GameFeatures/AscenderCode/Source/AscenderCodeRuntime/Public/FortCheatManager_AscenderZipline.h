// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_AscenderZipline.generated.h"

UCLASS()
class UFortCheatManager_AscenderZipline : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void RemoveAscenders(const bool bRemoveAscendersOn = true);

};

