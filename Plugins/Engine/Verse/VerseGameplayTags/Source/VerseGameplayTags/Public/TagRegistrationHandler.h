// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureStateChangeObserver.h"
#include "UObject/NoExportTypes.h"
#include "TagRegistrationHandler.generated.h"

/**
 * Class to be created by the module which owns the verse tag class. Should occur prior to the construction of any 
 * tag based objects/assets. 
 */
UCLASS()
class VERSEGAMEPLAYTAGS_API UTagRegistrationHandler : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

