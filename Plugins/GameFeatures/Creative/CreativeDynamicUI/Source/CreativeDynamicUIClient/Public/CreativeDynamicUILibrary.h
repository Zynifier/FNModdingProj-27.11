// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/SlateEnums.h"
#include "CreativeDynamicUILibrary.generated.h"

enum class ECreativeDynamicUIAlignment : uint8;

UCLASS()
class CREATIVEDYNAMICUICLIENT_API UCreativeDynamicUILibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static EHorizontalAlignment GetHorizontalAlignment(const ECreativeDynamicUIAlignment Alignment);

	UFUNCTION(BlueprintPure)
	static EVerticalAlignment GetVerticalAlignment(const ECreativeDynamicUIAlignment Alignment);

};

