// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemDefinitionBase.h"
#include "ItemVariant.generated.h"

class UItemDefinition;

USTRUCT()
struct FOverriddenRecord
{
	GENERATED_BODY()

};

// An item variant has a parent item definition as well as specific item components (from base class) it might wish to override

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemVariant : public UItemDefinitionBase
{
	GENERATED_BODY()

private:
	// The parent item definition from which this variant will originate

	UPROPERTY(EditDefaultsOnly, Category="Item Definition")
	TObjectPtr<UItemDefinition> Original;

	// The array to record the class of the overridden component and which of its property has been changed.

	UPROPERTY(Transient)
	TArray<FOverriddenRecord> CachedOverriddenList;

	// When a Component's property is about to be modified, this will be set in PreEditChange 
// and then be used in PostEditChangeChainProperty to find the Component.

	UPROPERTY(Transient)
	int32 ModifiedComponentIdx;

};

