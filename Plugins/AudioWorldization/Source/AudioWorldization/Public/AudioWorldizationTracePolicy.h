// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AudioWorldizationTracePolicy.generated.h"

UCLASS(BlueprintType)
class AUDIOWORLDIZATION_API UAudioWorldizationTracePolicyBase : public UObject
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class AUDIOWORLDIZATION_API UAudioWorldizationTracePolicyDefault : public UAudioWorldizationTracePolicyBase
{
	GENERATED_BODY()

};

