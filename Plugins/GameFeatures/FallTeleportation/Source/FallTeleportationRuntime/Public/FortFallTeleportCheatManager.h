// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortFallTeleportCheatManager.generated.h"

UCLASS()
class FALLTELEPORTATIONRUNTIME_API UFortFallTeleportCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

private:
	UFUNCTION(Exec)
	void EnableFallTeleportationIndefinitely();

};

