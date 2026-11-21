// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Items/FortAttributeLookupTable.h"
#include "FortTooltipLibrary.generated.h"

UCLASS()
class UFortTooltipLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="ActorToRegister"))
	static FText FormatAttributeBuffs(const FFortAttributeInfo& AttributeInfo, float AdditiveBuff, float MultiplicativeBuff);

};

