// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "FortTeamActorInterface.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTeamIndexChangedDelegate);

UINTERFACE(MinimalAPI)
class UFortTeamActorInterface : public UGenericTeamAgentInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortTeamActorInterface : public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual uint8 GetTeam() const;

};

