// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaLivingWorldActorUpdateHandler.generated.h"

class UFortAthenaLivingWorldManager;

USTRUCT()
struct FFortAthenaLivingWorldActorUpdateHandler
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaLivingWorldManager> LivingWorldManager;

};

