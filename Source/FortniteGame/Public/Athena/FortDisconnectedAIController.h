// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FortTeamActorInterface.h"
#include "FortDisconnectedAIController.generated.h"

UCLASS(HideCategories=("Collision", "Rendering", "Transformation"))
class AFortDisconnectedAIController : public AAIController, public IFortTeamActorInterface
{
	GENERATED_BODY()

};

