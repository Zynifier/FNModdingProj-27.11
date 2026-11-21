// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InfiltrationRoundInfoMutatorInterface.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPreRoundVisibilityChange, bool, bNewVisibility);

UINTERFACE(MinimalAPI)
class UInfiltrationRoundInfoMutatorInterface : public UInterface
{
	GENERATED_BODY()
};

class IInfiltrationRoundInfoMutatorInterface
{
	GENERATED_BODY()

};

