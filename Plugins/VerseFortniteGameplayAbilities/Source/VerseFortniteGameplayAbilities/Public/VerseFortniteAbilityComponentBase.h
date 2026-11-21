// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityAbilityInterface.h"
#include "EntityActorComponent.h"
#include "VerseFortniteAbilityComponentBase.generated.h"

UCLASS(Abstract)
class UVerseFortniteAbilityComponentBase : public UEntityActorComponent, public IEntityAbilityInterface
{
	GENERATED_BODY()

};

