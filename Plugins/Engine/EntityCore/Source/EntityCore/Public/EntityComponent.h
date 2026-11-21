// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/Interface_ActorSubobject.h"
#include "UObject/NoExportTypes.h"
#include "EntityComponent.generated.h"

// @TODO: Make runtime meta attributes available for entity components
// EnforceSingleEntityComponent - Only allows a single instance of this component on an entity
// RequireDependantEntityComponent - Requires a dependent entity component instance to exist before this component can be added to an entity
// CreateDependantEntityComponent - Creates a dependent entity component if needed

UCLASS(Abstract)
class ENTITYCORE_API UEntityComponent : public UObject, public IInterface_ActorSubobject
{
	GENERATED_BODY()

};

