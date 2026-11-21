// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FortItemVariantHandle.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FItemVariantHandle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	TObjectPtr<UFortItemDefinition> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	FGuid ItemVariantGuid;

};

