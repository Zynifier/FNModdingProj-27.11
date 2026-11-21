// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInitializationInterface.generated.h"

UINTERFACE(MinimalAPI)
class UFortInitializationInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void MatchStarted();

	UFUNCTION()
	virtual bool NeedsWorldReady() const;

	UFUNCTION()
	virtual void WorldReady();

};

