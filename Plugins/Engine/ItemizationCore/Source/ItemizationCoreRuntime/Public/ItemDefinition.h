// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemDefinitionBase.h"
#include "ItemDefinition.generated.h"

/** This class contains the designer-set data for anything a player owns */
UCLASS(BlueprintType)
class ITEMIZATIONCORERUNTIME_API UItemDefinition : public UItemDefinitionBase
{
	GENERATED_BODY()

private:
	// When a Component's property is about to be modified, this will be set in PreEditChange 
// and then be used in PostEditChangeChainProperty to find the Component.

	UPROPERTY(Transient)
	int32 ModifiedComponentIdx;

};

