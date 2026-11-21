// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAITypes.h"
#include "FortAIRootAssignmentProviderInterface.generated.h"

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortAIRootAssignmentProviderInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortAIRootAssignmentProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Assignment")
	virtual const FFortAIAssignmentIdentifier& GetRootAssignmentIdentifier() const;

};

